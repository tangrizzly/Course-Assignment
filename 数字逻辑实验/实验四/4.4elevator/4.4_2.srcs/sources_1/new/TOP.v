`timescale 1ns / 1ps
module top(
	input [4:2]downn0,
	input [3:1]upn0,
	input [4:1]bn0,
	input clr,clk,//清零端低电平有效，恢复至一层
	output [4:2]downn,
	output [3:1]upn,
	output [4:1]bn,
    output [3:0]pos,
    output [7:0]seg
	);
wire[4:2]downnfb;
wire[3:1]upnfb;
wire[4:1]bnfb;
wire[2:0]floor;
wire[1:0]updown;
wire[2:0]y;
ctrl U1(downn,upn,bn,clr,clk3hz,downnfb,upnfb,bnfb,floor,updown,open,y);
clkDiv U2(clk,clk190hz,clk3hz);
seg U3(clk190hz,floor,updown,open,y,pos,seg);
button U4(clr,clk190hz,bn0[1],bnfb[1],bn[1]);
button U5(clr,clk190hz,bn0[2],bnfb[2],bn[2]);
button U6(clr,clk190hz,bn0[3],bnfb[3],bn[3]);
button U7(clr,clk190hz,bn0[4],bnfb[4],bn[4]);
button U8(clr,clk190hz,upn0[1],upnfb[1],upn[1]);
button U9(clr,clk190hz,upn0[2],upnfb[2],upn[2]);
button U10(clr,clk190hz,upn0[3],upnfb[3],upn[3]);
button U11(clr,clk190hz,downn0[2],downnfb[2],downn[2]);
button U12(clr,clk190hz,downn0[3],downnfb[3],downn[3]);
button U13(clr,clk190hz,downn0[4],downnfb[4],downn[4]);
endmodule