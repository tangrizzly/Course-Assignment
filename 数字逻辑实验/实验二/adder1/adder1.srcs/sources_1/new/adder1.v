`timescale 1ns / 1ps
module RippleCarry(
	input [7:0]a,b,
	input cin,
	output cout,
	output [7:0]s
	);
wire [7:1]c;
adder a0(a[0],b[0],cin,c[1],s[0]);
adder a1(a[1],b[1],c[1],c[2],s[1]);
adder a2(a[2],b[2],c[2],c[3],s[2]);
adder a3(a[3],b[3],c[3],c[4],s[3]);
adder a4(a[4],b[4],c[4],c[5],s[4]);
adder a5(a[5],b[5],c[5],c[6],s[5]);
adder a6(a[6],b[6],c[6],c[7],s[6]);
adder a7(a[7],b[7],c[7],cout,s[7]);
endmodule

module adder(
	input a,b,cin,
	output cout,s
	);
assign s=cin^a^b;
assign cout=a&b|b&cin|a&cin;
endmodule
