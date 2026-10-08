gcc -Wall -Wextra .\main.c -o .\vegabase.exe

if($LASTEXITCODE -eq 0) {
    .\vegabase.exe
}