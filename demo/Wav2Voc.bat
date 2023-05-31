

for /R "assets/SAMPLE" %%A in (*.wav) do (
    sox %%A -r 11110 -c 1 -b 8  assets/SAMPLE/%%~nA.voc
)
