`timescale 1ns / 1ps

module anti_jitter( //消除按键抖动
	input clock,
   input [WIDTH - 1:0] in,
   output reg [WIDTH - 1:0] out
   );

	parameter WIDTH = 1; //根据之前传递的参数进行改变
	parameter HOLD = 100000;//计时到32个时间单位

	reg [31:0] counter = 0;
	reg [WIDTH - 1:0] last_seen = 0;

	always @(posedge clock) begin
		if (last_seen != in) begin
			counter <= 0;//如果输入改变则重新计时
		end else if (counter < HOLD) begin
			counter <= counter + 1;
		end else begin //输入一个按键，其后的32个时间单位内不改变，则有效
			out <= last_seen;
		end
		last_seen <= in;//将每一时刻的输入记录
	end

endmodule
