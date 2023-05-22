for %%I in (.) do @set CurrDirName=%%~nxI

@echo Generating data.h for %CurrDirName%.vol
@echo:

del 2> nul data.h

echo /* >> data.h
echo * >> data.h
echo * data.h >> data.h
echo * Macros for asset locations within data.vol >> data.h
echo *  >> data.h
echo * AUTOMATICALLY GENERATED. DO NOT EDIT MANUALLY. >> data.h
echo * >> data.h
echo */ >> data.h

echo: >> data.h

echo #ifndef _DATA_H >> data.h
echo #define _DATA_H >> data.h
echo: >> data.h
echo #define DATAFILE_NAME "%CurrDirName%.vol" >> data.h

    for /R "assets/GRAPHICS" %%f in (*.png) do (

    echo #define %%~nf "GRAPHICS/%%~nf" >> data.h
)

echo: >> data.h


    for /R "assets/MUSIC" %%f in (*.mid) do (

    echo #define %%~nf "MUSIC/%%~nf" >> data.h
)

echo: >> data.h

    for /R "assets/SOUND" %%f in (*.voc) do (

    echo #define %%~nf "SOUND/%%~nf" >> data.h
)

echo: >> data.h

    for /R "assets/MAP" %%f in (*.map) do (

    echo #define %%~nf "MAP/%%~nf" >> data.h
)

echo #endif >> data.h

echo Moving data.h
robocopy . src data.h

del data.h

