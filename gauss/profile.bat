@echo off

rem (!) must be executed with administrative privileges
rem NVIDIA Nsight Tools : C:\Program Files\NVIDIA Corporation\Nsight Compute 2023.3.1\host\target-windows-x64\nsys.exe

nsys profile --output=.\profiles\gauss_%1.nsys-rep .\bin\gauss_%1.exe
start .\profiles\gauss_%1.nsys-rep