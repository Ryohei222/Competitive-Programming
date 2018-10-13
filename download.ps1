Add-Type -AssemblyName System.Web
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12;

function Get-Submission {
    param (
        [string]$contestID,
        [string]$submissionID
    );
    $res = Invoke-WebRequest -Uri "https://beta.atcoder.jp/contests/${contestID}/submissions/${submissionID}" -Method GET
    $res = [System.Web.HttpUtility]::HtmlDecode($res.content)
    $start = $res.IndexOf('<pre id="submission-code" class="prettyprint linenums">')
    $end = $res.IndexOf("<h4>")
    $res = $res.SubString($start, $end - $start)
    return $res.SubString(55, $res.Length-65)
}

function Get-MySubmissions {
    param(
        [string]$userID
    );
    $res = Invoke-WebRequest `https://kenkoooo.com/atcoder/atcoder-api/results?user=${userID}` | select -ExpandProperty Content
    $res =  ConvertFrom-JSON $res
    $res = $res | Sort-Object -Property epoch_second -Descending
    $cnt = 0
    $ac = 0
    $all = [int]($res.Length / 20)
    foreach($item in $res){
        if($item.result -eq "AC"){
            $path = $item.contest_id
            $flag = Test-Path $path
            if(!$flag){
                $hoge = mkdir $path
            }
            $path = @(".", $path, $item.problem_id) -join "\"
            $path += ".cpp"
            $flag = Test-Path $path
            if(!$flag){
                Get-Submission $item.contest_id $item.id > $path
                $ac++;
                Start-Sleep -Milliseconds 50
            }
        }
        if($cnt % $all -eq 0){
            Write-Host -NoNewline "."
        }
        $cnt++
    }
    Write-Host
    Write-Host "Download successfully completed (${ac}files)"
}

$userID = Read-Host "Input AtCoderID"
Get-MySubmissions $userID