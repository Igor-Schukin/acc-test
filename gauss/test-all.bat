@echo off

echo ----- Start > test-all.txt
for %%v in (0 1 2 3 4 0M 1M) do (
    echo ----- %%v ----- >> test-all.txt
    .\bin\gauss_%%v.exe %1 >> test-all.txt
)
echo ----- Finish >> test-all.txt
