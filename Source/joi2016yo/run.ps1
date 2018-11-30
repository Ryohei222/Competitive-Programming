rm a.exe
$ProblemName = Read-Host "Input problem num(?) ex) a, b, c..."
$CurrentDirectoryName = Split-Path -Parent $MyInvocation.MyCommand.Path | Split-Path -Leaf
$FileName = "${CurrentDirectoryName}_${ProblemName}.cpp"
g++ $filename -std=c++14 -o a.exe
if(Test-Path a.exe){
    Write-Host "Successfully compiled"
    Write-Host "Input testcase"
    ./a.exe
}else{
    Write-Host "Failed in compile"
}