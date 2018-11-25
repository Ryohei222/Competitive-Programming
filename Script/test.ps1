$CurrentDirectoryName = Split-Path -Parent $MyInvocation.MyCommand.Path | Split-Path -Leaf
python download_testcase.py $CurrentDirectoryName