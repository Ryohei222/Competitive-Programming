$alphabet = "abcdefghijklmnopqrstuvwxyz"

$contestID = Read-Host "Put contest id"
$path = "../Source/${contestID}"
$flag = Test-Path $path
if(!$flag){
    mkdir $path
}

$cpath = "${path}/run.ps1"
if(!(Test-Path $cpath)){
    Copy-Item "run.ps1" $cpath
}

$path = "${path}/${contestID}_"
$probCount = Read-Host "Put the number of problems"
$probCount = [int]$probCount

for($i = 0; $i -lt $probCount; $i++){
    $c = $alphabet[$i]
    $cpath = "${path}${c}.cpp"
    $flag = Test-Path $cpath
    if(!$flag){
        Copy-Item "../Library/template.cpp" $cpath
    }
}

cd "../Source/${contestID}"