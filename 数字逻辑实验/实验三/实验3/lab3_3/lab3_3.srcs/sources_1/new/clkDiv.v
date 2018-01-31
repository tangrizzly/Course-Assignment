`timescale 1ns / 1ps

module clkDiv(
    input clk100mhz,
    output clk190hz,
    output clk12hz,
    output clk3hz
);

reg [25:0]count = 0;
reg [17:0]count1 = 0;
reg [23:0]count2 = 0;

assign clk190hz = count1[17];
assign clk3hz = count[25];
assign clk12hz = count2[23];

always @(posedge clk100mhz) count<=count+1;
always @(posedge clk100mhz) count1<=count1+1;
always @(posedge clk100mhz) count2<=count2+1;

endmodule


