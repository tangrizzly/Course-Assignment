`timescale 1ns / 1ps

module SRAMRead(
    input clk100mhz,
    input enable,
    input chooseAddr,
    inout [15:0]dataBus,
    output reg[18:0]addrBus,
    output chipEnable,outEnable,upEnable,lowEnable,    
    output reg write_read,
    output reg[15:0]LED
    );
    
    assign outEnable = 0;
    assign upEnable = 0;
    assign lowEnable = 0;
    
    
    end
    
endmodule
