@echo off
set xv_path=F:\\Xilinx_vivado\\Vivado\\2015.4\\bin
call %xv_path%/xelab  -wto 823e5f3c4c4b4f6e9aab10ae92d8d8ae -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot life_game_test_behav xil_defaultlib.life_game_test xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
