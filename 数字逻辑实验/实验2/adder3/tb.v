`timescale 1ns / 1ps

module Carry_tb;
reg [7:0]a,b;
reg cin;
wire cout;
wire [7:0]s;

initial begin
cin=0;
a=0;b=0;
repeat(10)
begin
	#10 a=($random)%256;
    b=($random)%256;
end
#10 $stop;
end
carryselect u0(a,b,cin,cout,s);
endmodule
