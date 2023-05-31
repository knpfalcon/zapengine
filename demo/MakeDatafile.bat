@for %%I in (.) do @set CurrDirName=%%~nxI

mkdir 2> nul "data/ACTOR/"
mkdir 2> nul "data/MUSIC/"
mkdir 2> nul "data/SAMPLE/"
mkdir 2> nul "data/MAP/"

for /R "assets/ACTOR" %%f in (*.png) do (
    echo f | xcopy %%~f "data/ACTOR/%%~nxf" /E /y
)

for /R "assets/ACTOR" %%f in (*.def) do (
    echo f | xcopy %%~f "data/ACTOR/%%~nxf" /E /y
)

for /R "assets/MUSIC" %%f in (*.mid) do (
    echo f | xcopy %%~f "data/MUSIC/%%~nxf" /E /y
)


for /R "assets/SAMPLE" %%f in (*.voc) do (
    echo f | xcopy %%~f "data/SAMPLE/%%~nxf" /E /y
)


for /R "assets/MAP" %%f in (*.zm) do (
    echo f | xcopy %%~f "data/MAP/%%~nxf" /E /y
)

7z a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on %CurrDirName%.vol .\data\*

rmdir /Q /S data

robocopy . ../build/demo %CurrDirName%.vol

del %CurrDirName%.vol
call DeleteVoc.bat
