`timescale 1ns / 1ps
module gputb;
reg [4:2]downn;
reg [3:1]upn;
reg [4:1]bn;
reg clr,clk;//清零端低电平有效，恢复至一层
wire[4:2]downnfb;
wire[3:1]upnfb;
wire[4:1]bnfb;
wire [2:0]floor;
wire [1:0]updown;
wire [3:0]count;
wire [2:0]y;//状态
ctrl U1(downn,upn,bn,clr,clk3hz,downnfb,upnfb,bnfb,floor,updown,open,y);
initial begin
clr=0;
#1 clr=1;
bn[4]=1;
end
always 
#1 clk=~clk;

endmodule