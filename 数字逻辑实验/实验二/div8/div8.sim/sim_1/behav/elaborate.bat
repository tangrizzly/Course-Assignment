@echo off
set xv_path=F:\\Xilinx_vivado\\Vivado\\2015.4\\bin
call %xv_path%/xelab  -wto 76a64991d7274f4f9d5ca25a2311eabc -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot div84_sim_behav xil_defaultlib.div84_sim xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
