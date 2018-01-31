`timescale 1ns / 1ps

module life_game_test;

	// Inputs
	reg clock;
	reg [3:0] button;
	reg [9:0] x_position;
	reg [8:0] y_position;
	reg inside_video;

	// Outputs
	wire [11:0] color;

	// Instantiate the Unit Under Test (UUT)
	life_game uut (
		.clock(clock), 
		.button(button), 
		.x_position(x_position), 
		.y_position(y_position), 
		.inside_video(inside_video), 
		.color(color)
	);

	initial begin
		// Initialize Inputs
		clock = 0;
		button = 0;
		x_position = 0;
		y_position = 0;
		inside_video = 0;

		// Wait 100 ns for global reset to finish
		#100;

		// Add stimulus here
		repeat (1000) begin
			#1;
			clock = ~clock;
		end
	end
      
endmodule


