@echo off

set WindowsLib=

:: to add a library include append /I ../libs/<library include folder> to the following line: 
set IncludeDirs=/I ../src/ 

:: to add a library, just append the location of the .lib file you need onto this line:
set Libraries=%WindowsLib% 

mkdir ./bin/
cd ./bin
cl ../src/*.c /Zi /Fe%cd%/JugTest /MD %IncludeDirs% %Libraries% /link
cd ..	