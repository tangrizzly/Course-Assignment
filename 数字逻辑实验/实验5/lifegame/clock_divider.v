`timescale 1ns / 1ps

module clock_divider(
	input in,
	output out
	);

	parameter COUNTER_WIDTH = 1;

	reg [COUNTER_WIDTH - 1:0] counter = 0;

	always @(posedge in) begin
		counter <= counter + 1'b1;
	end

	assign out = counter[COUNTER_WIDTH - 1];

endmodule
