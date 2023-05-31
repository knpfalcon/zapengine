for %%I in (.) do @set CurrDirName=%%~nxI

call Wav2Voc.bat

@echo Generating data.h for %CurrDirName%.vol
@echo:

del 2> nul data.h

echo /* >> data.h
echo * >> data.h
echo * data.h >> data.h
echo * Macros for asset locations within the Zap Engine data file >> data.h
echo *  >> data.h
echo * AUTOMATICALLY GENERATED. DO NOT EDIT MANUALLY. >> data.h
echo * >> data.h
echo */ >> data.h

echo: >> data.h

echo #ifndef _DATA_H >> data.h
echo #define _DATA_H >> data.h

echo: >> data.h

echo #define DATAFILE_NAME "%CurrDirName%.vol" >> data.h

echo: >> data.h

echo /**************** >> data.h
echo  *    ACTORS    *>> data.h
echo  ****************/ >> data.h
setlocal enabledelayedexpansion
set /A iter = 0
    for /R "assets/ACTOR" %%f in (*.png) do (
    echo /* %%~nf */ >> data.h
    echo #define %%~nf_FILE "ACTOR/%%~nxf" >> data.h
    echo #define %%~nf !iter! >> data.h
    type assets\ACTOR\%%~nf.def >> data.h
    echo ZAP_ACTOR *CREATE_%%~nf^(void^); >> data.h
    echo: >> data.h
    set /A iter +=1
)
set /A iter = 0

echo /**************** >> data.h
echo  *     MUSIC    * >> data.h
echo  ****************/ >> data.h
    for /R "assets/MUSIC" %%f in (*.mid) do (

    echo #define %%~nf_FILE "MUSIC/%%~nxf" >> data.h
    echo #define %%~nf !iter! >> data.h
    set /A iter +=1
)
set /A iter = 0

echo: >> data.h
echo /**************** >> data.h
echo  *    SAMPLES   * >> data.h
echo  ****************/ >> data.h
    for /R "assets/SAMPLE" %%f in (*.voc) do (

    echo #define %%~nf_FILE "SAMPLE/%%~nxf" >> data.h
    echo #define %%~nf !iter! >> data.h
    set /A iter +=1
)
set /A iter = 0

echo: >> data.h
echo /**************** >> data.h
echo /      MAPS     * >> data.h
echo  ****************/ >> data.h
    for /R "assets/MAP" %%f in (*.zm) do (

    echo #define %%~nf_FILE "MAP/%%~nxf" >> data.h
    echo #define %%~nf !iter! >> data.h
    set /A iter +=1
)

echo #endif >> data.h
