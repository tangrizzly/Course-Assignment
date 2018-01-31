`timescale 1ns / 1ps

module clock_divider_to_125ms(
   input clock_100mhz,
   output reg clock_125ms = 0
   );

	parameter COUNTER_MAX = 6250000;

	reg [25:0] counter = 0;

	always @(posedge clock_100mhz) begin
		if (counter < COUNTER_MAX - 1) begin
			counter <= counter + 1'b1;
		end else begin
			counter <= 0;
			clock_125ms <= ~clock_125ms;
		end
	end

endmodule

