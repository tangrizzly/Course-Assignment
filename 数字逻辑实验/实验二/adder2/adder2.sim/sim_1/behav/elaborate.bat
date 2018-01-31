@echo off
set xv_path=C:\\Vivado\\2015.4\\bin
call %xv_path%/xelab  -wto a5b0c5696c5b40c1a3dd7e0ca1825048 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot Carry_tb_behav xil_defaultlib.Carry_tb xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
