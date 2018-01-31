@echo off
set xv_path=C:\\Vivado\\2015.4\\bin
call %xv_path%/xsim Carry_tb_behav -key {Behavioral:sim_1:Functional:Carry_tb} -tclbatch Carry_tb.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
