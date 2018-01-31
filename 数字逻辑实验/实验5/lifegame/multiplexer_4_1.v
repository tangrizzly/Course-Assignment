`timescale 1ns / 1ps

module multiplexer_4_1(
   input [3:0] in,
   input [1:0] select,
   output out
   );

	assign out = in[select];

endmodule

