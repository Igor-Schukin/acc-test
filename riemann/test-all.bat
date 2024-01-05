@echo off

echo ----- Start  %date% %time% > test-all.txt
for %%v in (R0 R1 R2 T0 T1 T2 M0 M1 M2) do (
    echo ----- %%v ----- >> test-all.txt
    .\bin\riemann_%%v.exe %1 %2 >> test-all.txt
)
echo ----- Finish  %date% %time% >> test-all.txt
