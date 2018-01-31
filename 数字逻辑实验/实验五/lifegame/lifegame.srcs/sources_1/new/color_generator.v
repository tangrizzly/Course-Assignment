`timescale 1ns / 1ps

module color_generator(
	input [4:0] x_index,
	input [4:0] y_index,
	output [11:0] color
	);

	assign color[11:8] = x_index /12+9;
	assign color[7:4] = y_index / 9 + 9;
	assign color[3:0] = x_index/16+y_index/16+7;
	

endmodule

