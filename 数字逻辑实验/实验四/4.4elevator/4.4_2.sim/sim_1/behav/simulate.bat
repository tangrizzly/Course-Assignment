@echo off
set xv_path=F:\\Xilinx_vivado\\Vivado\\2015.4\\bin
call %xv_path%/xsim gputb_behav -key {Behavioral:sim_1:Functional:gputb} -tclbatch gputb.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
