`timescale 1ns / 1ps
module carryselect(
	input [7:0]a,b,
	input cin,
	output cout,
	output [7:0]s
	);
wire [7:0]c1;
wire [7:0]c0;
wire [7:1]c;
wire [7:0]s1,s0;
adder1 a01(a[0],b[0],c1[0],s1[0]);
adder0 a00(a[0],b[0],c0[0],s0[0]);
adder1 a11(a[1],b[1],c1[1],s1[1]);
adder0 a10(a[1],b[1],c0[1],s0[1]);
adder1 a21(a[2],b[2],c1[2],s1[2]);
adder0 a20(a[2],b[2],c0[2],s0[2]);
adder1 a31(a[3],b[3],c1[3],s1[3]);
adder0 a30(a[3],b[3],c0[3],s0[3]);
adder1 a41(a[4],b[4],c1[4],s1[4]);
adder0 a40(a[4],b[4],c0[4],s0[4]);
adder1 a51(a[5],b[5],c1[5],s1[5]);
adder0 a50(a[5],b[5],c0[5],s0[5]);
adder1 a61(a[6],b[6],c1[6],s1[6]);
adder0 a60(a[6],b[6],c0[6],s0[6]);
adder1 a71(a[7],b[7],c1[7],s1[7]);
adder0 a70(a[7],b[7],c0[7],s0[7]);
mult m0(c1[0],c0[0],s1[0],s0[0],cin,c[1],s[0]);
mult m1(c1[1],c0[1],s1[1],s0[1],c[1],c[2],s[1]);
mult m2(c1[2],c0[2],s1[2],s0[2],c[2],c[3],s[2]);
mult m3(c1[3],c0[3],s1[3],s0[3],c[3],c[4],s[3]);
mult m4(c1[4],c0[4],s1[4],s0[4],c[4],c[5],s[4]);
mult m5(c1[5],c0[5],s1[5],s0[5],c[5],c[6],s[5]);
mult m6(c1[6],c0[6],s1[6],s0[6],c[6],c[7],s[6]);
mult m7(c1[7],c0[7],s1[7],s0[7],c[7],cout,s[7]);
endmodule

module mult(
	input c1,c0,s1,s0,c,
	output d,s
	);
assign d = c?c1:c0;
assign s = c?s1:s0;
endmodule

module adder1(
	input a,b,
	output cout,s
	);
assign s=1^a^b;
assign cout=a&b|b|a;
endmodule

module adder0(
	input a,b,
	output cout,s
	);
assign s=0^a^b;
assign cout=a&b;
endmodule
