@echo off
mkdir build
cd build
cmake -G "Ninja" ..
ninja


echo Creating bin directory...
mkdir "..\bin"

echo Copying source file...
copy /Y "..\src\main.cpp" "..\bin\"
echo Copying resources...
xcopy /E /I /Y "..\resources" "..\bin\resources"

cd ..
echo Build complete! Executable is in bin/ directory.