`timescale 1ns / 1ps
module seqdetb_tb;
reg clk;
reg clr;
reg din;
wire dout;
parameter period=8;
seqdetea U1(clk,clr,din,dout);
initial
begin
	clk=0;
	forever
	begin
		#(period/2) clk=1;
		#(period/2) clk=0;
	end
end
initial
begin
	clr=1;
	forever
	begin
		#6 clr=0;
	end
end
initial
begin
	din=1;
	#20 din=0;
	#50 din=1;
	#200 din=0;
	#50 din=1;
	#10$stop;
end
endmodule