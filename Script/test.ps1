if(Test-Path a.exe){
    rm a.exe
}
$ProblemName = Read-Host "Input problem num(?) ex) a, b, c..."
$CurrentDirectoryName = Split-Path -Parent $MyInvocation.MyCommand.Path | Split-Path -Leaf
$ProblemId = "${CurrentDirectoryName}_${ProblemName}"
python $CurrentDirectoryName $ProblemId