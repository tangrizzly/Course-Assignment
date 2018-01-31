`timescale 1ns / 1ps

module top(
    input clk100mhz,
    input main_switch,
    input start_stop_switch,
    input high_low_switch,
    //input Sram_switch,
    input SramWrite_Read,
    input chooseAddr,
    //input SramReadEnable,
    input [3:0]control,
    inout [15:0]dataBus,
    output [18:0]addrBus,
    output chipEnable,upEnable,lowEnable,
    output write_read,outEnable, 
    output [15:0]LED,
    output [3:0]pos,
    output [3:0]sop,
    output [7:0]seg1,
    output [7:0]seg2
);

    wire clk190hz,clk12hz,clk3hz,clk75hz,en;
    wire [15:0]dataBus1,dataBus2,dataBusInfo;
    wire [3:0]GPUcontrol;

    clkDiv U1(clk100mhz,clk190hz,clk12hz,clk3hz);
    GPU    U2(clk3hz,clk12hz,main_switch,start_stop_switch,high_low_switch,GPUcontrol,en,dataBus1,dataBus2,dataBusInfo);
    segMsg U3(clk190hz,dataBus1,dataBus2,dataBusInfo,en,pos,sop,seg1,seg2);
    btnDeal U4(clk190hz,control[0],GPUcontrol[0]);
    btnDeal U5(clk190hz,control[1],GPUcontrol[1]);
    btnDeal U6(clk190hz,control[2],GPUcontrol[2]);
    btnDeal U7(clk190hz,control[3],GPUcontrol[3]);
    SRAM U8(clk100mhz,SramWrite_Read,chooseAddr,dataBus2,dataBus,addrBus,chipEnable,upEnable,lowEnable,write_read,outEnable,LED);
    
endmodule
