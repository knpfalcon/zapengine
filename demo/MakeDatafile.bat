@for %%I in (.) do @set CurrDirName=%%~nxI

mkdir 2> nul "data/GRAPHICS/"
mkdir 2> nul "data/MUSIC/"
mkdir 2> nul "data/SOUND/"
mkdir 2> nul "data/MAP/"

call Wav2Voc.bat


for /R "assets/GRAPHICS" %%f in (*.png) do (

    echo f | xcopy %%~f "data/GRAPHICS/%%~nf" /E /y
)


for /R "assets/MUSIC" %%f in (*.mid) do (

    echo f | xcopy %%~f "data/MUSIC/%%~nf" /E /y
)


for /R "assets/SOUND" %%f in (*.voc) do (

    echo f | xcopy %%~f "data/SOUND/%%~nf" /E /y
)


for /R "assets/MAP" %%f in (*.zm) do (

    echo f | xcopy %%~f "data/MAP/%%~nf" /E /y
)

7z a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on %CurrDirName%.vol .\data\*

rmdir /Q /S data

robocopy . ../build/demo %CurrDirName%.vol

del %CurrDirName%.vol

