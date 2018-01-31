`timescale 1ns / 1ps

module top(
	input clock,
	input [7:0] sw,
	input btn_l, btn_r, btn_u, btn_d, btn_s,
	output reg [7:0] led = 0,
	output vga_h_sync,
	output vga_v_sync,
	output [3:0] vga_r,
	output [3:0] vga_g,
	output [3:0] vga_b
   );

	wire [7:0] switch;
	wire button_left, button_right, button_up, button_down, button_select;
	wire clock_50mhz;
	wire pointer_ready;
	wire [8:0] pointer_delta_x;
	wire [8:0] pointer_delta_y;
	wire clock_25mhz;
	wire inside_video;
	wire [9:0] x_position;
	wire [8:0] y_position;
	wire [11:0] color;
	wire clock_125ms;
	wire clock_250ms;
	wire clock_500ms;
	wire clock_1s;
	wire clock_life_game;

	anti_jitter #(8) switch_anti_jitter(clock, sw[7:0], switch[7:0]);
	anti_jitter #(5) button_anti_jitter(clock, {btn_l, btn_r, btn_u, btn_d, btn_s}, {button_left, button_right, button_up, button_down, button_select});

	clock_divider #(1) clock_divider_to_50mhz(clock, clock_50mhz);

	clock_divider #(1) clock_divider_to_25mhz(clock_50mhz, clock_25mhz);

	vga_controller vga_controller(clock_25mhz, switch[0], vga_h_sync, vga_v_sync, inside_video, x_position, y_position);

//	button_pointer #(25) button_pointer (button_left, button_right, button_up, button_down, button_select, pointer_ready, pointer_delta_x, pointer_delta_y, pointer_select);
	button_pointer #(25) button_pointer (button_up, button_down, button_left, button_right, button_select, pointer_ready, pointer_delta_x, pointer_delta_y, pointer_select);

	clock_divider_to_125ms clock_divider_to_125ms(clock, clock_125ms);
	clock_divider #(1) clock_divider_to_250ms(clock_125ms, clock_250ms);
	clock_divider #(1) clock_divider_to_500ms(clock_250ms, clock_500ms);
	clock_divider #(1) clock_divider_to_1s(clock_500ms, clock_1s);
	multiplexer_4_1 clock_multiplexer({clock_125ms, clock_250ms, clock_500ms, clock_1s}, switch[6:5], clock_life_game);

	life_game #(25) life_game(clock_life_game, switch[7], switch[4],pointer_ready, pointer_delta_x, pointer_delta_y, pointer_select, x_position, y_position, inside_video, color);
	assign vga_r = color[11:8];
	assign vga_g = color[7:4];
	assign vga_b = color[3:0];

	always @(posedge clock_125ms) begin
		if (sw[0]) led[0] = 1;
		else if (!sw[0]) led[0] = 0;
		if (sw[1]) led[1] = 1;
		else if (!sw[1]) led[1] = 0;
		if (sw[2]) led[2] = 1;
		else if (!sw[2]) led[2] = 0;
        if (sw[3]) led[3] = 1;
        else if (!sw[3]) led[3] = 0;
        if (sw[4]) led[4] = 1;
        else if (!sw[4]) led[4] = 0;
        if (sw[5]) led[5] = 1;
        else if (!sw[5]) led[5] = 0;
        if (sw[6]) led[6] = 1;
        else if (!sw[6]) led[6] = 0;
        if (sw[7]) led[7] = 1;
        else if (!sw[7]) led[7] = 0;
	end

endmodule

