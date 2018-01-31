`timescale 1ns / 1ps
module seqdetb_tb;
reg clk;
reg clr;
reg cin;
wire dout;
parameter period=40;
seqdetb U1(clk,clr,cin,dout);
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
		#50 clr=0;
	end
end
initial
begin
	cin=1;
	#350 cin=0;
	#50 cin=1;
	#100 cin=0;
	#50 cin=1;
end
endmodule