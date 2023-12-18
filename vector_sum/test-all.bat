@echo off

echo ----- Start  %date% %time% > test-all.txt
for %%v in (0S 1S 2S 3S 4S 0D 1D 2D 3D 4D VA) do (
    echo ----- %%v ----- >> test-all.txt
    .\bin\vector_sum_%%v.exe %1 >> test-all.txt
)
echo ----- Finish  %date% %time% >> test-all.txt
