@echo off
set xv_path=C:\\Vivado\\2015.4\\bin
call %xv_path%/xelab  -wto 66ded4b8d88d4848896c2ebcce5ff3b5 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot seqdetb_tb_behav xil_defaultlib.seqdetb_tb xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
