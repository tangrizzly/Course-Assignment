`timescale 1ns / 1ps
 module ALUControl( ALU_Control, ALUOp, Function);
 output reg[2:0] ALU_Control;
 input [1:0] ALUOp;
 input [3:0] Function;
 wire [5:0] ALUControlIn;
 assign ALUControlIn = {ALUOp,Function};
 always @(ALUControlIn)
 casex (ALUControlIn)
  6'b11xxxx: ALU_Control=3'b000;
  6'b10xxxx: ALU_Control=3'b100;
  6'b01xxxx: ALU_Control=3'b001;
  6'b000000: ALU_Control=3'b000;
  6'b000001: ALU_Control=3'b001;
  6'b000010: ALU_Control=3'b010;
  6'b000011: ALU_Control=3'b011;
  6'b000100: ALU_Control=3'b100;
  default: ALU_Control=3'b000;
  endcase
 endmodule