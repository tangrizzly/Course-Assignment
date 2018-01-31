`timescale 1ns / 1ps

module top(
    input clk100mhz,
    input clr,
    output [3:0]pos,
    output [7:0]seg
);

    wire clk190hz,clk3hz;
    wire [15:0]dataBus;

    clkDiv U1(clk100mhz,clk190hz,clk3hz);
    GPU    U2(clk3hz,clr,dataBus);
    segMsg U3(clk190hz,dataBus,pos,seg);

endmodule