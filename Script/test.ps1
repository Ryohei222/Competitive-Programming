if(Test-Path a.exe){
    rm a.exe
}
$ProblemName = Read-Host "Input problem num(?) ex) a, b, c..."
$CurrentDirectoryName = Split-Path -Parent $MyInvocation.MyCommand.Path | Split-Path -Leaf
$FileName = "${CurrentDirectoryName}_${ProblemName}.cpp"
g++ $filename -std=gnu++1y -O2 -o a.exe
if(Test-Path a.exe){
    Write-Host "Successfully compiled"
    python .\download_testcase.py ${CurrentDirectoryName} "${CurrentDirectoryName}_${ProblemName}"
    $probnum = 1
    while($true){
        if(!(Test-Path "./testcase/${CurrentDirectoryName}_${ProblemName}_in${probnum}.txt")){
            break;
        }
        Write-Host "`r`nSample Input ${probnum}"
        Get-Content "./testcase/${CurrentDirectoryName}_${ProblemName}_in${probnum}.txt" | Write-Host
        Write-Host "`r`nSample Output ${probnum}"
        Get-Content "./testcase/${CurrentDirectoryName}_${ProblemName}_out${probnum}.txt" | Write-Host
        Write-Host "`r`nProgram Output ${probnum}"
        Get-Content "./testcase/${CurrentDirectoryName}_${ProblemName}_in${probnum}.txt" | ./a.exe
        #Write-Host Get-Content "./testcase/${CurrentDirectoryName}_${ProblemName}_out${probnum}.txt" -eq 
        $probnum++
    }
}else{
    Write-Host "Failed in compile"
}