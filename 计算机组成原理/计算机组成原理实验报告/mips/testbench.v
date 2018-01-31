`timescale 1ns / 1ps
 module tb_mips16;  //fpga4student.com: FPga projects, Verilog projects, VHDL projects
      // Inputs
      reg clk;
      reg reset;
      // Outputs
      wire [15:0] pc_out;
      wire [15:0] alu_result;
      wire [15:0] reg1,reg2,reg3;
      // Instantiate the Unit Under Test (UUT)
      mips_16 uut (
           .clk(clk),
           .reset(reset),
           .pc_out(pc_out),
           .alu_result(alu_result),
           .reg1(reg1),
           .reg2(reg2),
           .reg3(reg3)
      );
      initial begin
           clk = 0;
           forever #10 clk = ~clk;
      end
      initial begin
           // Initialize Inputs
           reset = 1;
           // Wait 100 ns for global reset to finish
           #100;
     reset = 0;
           // Add stimulus here
      end
 endmodule