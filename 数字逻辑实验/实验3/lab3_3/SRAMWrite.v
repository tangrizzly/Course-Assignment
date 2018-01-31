`timescale 1ns / 1ps

module SRAM(
    input clk100mhz,
    input enable,
    input chooseAddr,
    input [15:0]data,
    inout [15:0]dataBus,
    output reg[18:0]addrBus,
    output chipEnable,upEnable,lowEnable,
    output   write_read,outEnable,
    output [15:0]LED 
    );
     
     reg [15:0]LED;
     reg write_read;
     reg outEnable;
     reg [15:0]tempdata;
     
    assign dataBus = tempdata;
    assign chipEnable = 0;
    assign upEnable = 0;
    assign lowEnable = 0;
    
    always @ (posedge clk100mhz) begin
        case (chooseAddr) 
            0: addrBus <= 19'b000_0000_0000_0000_0000;
            1: addrBus <= 19'b000_0000_0000_0000_0001;
        endcase
    end
    
    always @ (posedge clk100mhz) begin
        if (enable) begin
            write_read <= 1'b0;
            outEnable <= 1'b1;
            tempdata <= data;
        end
        else begin
            write_read = 1;
            outEnable = 0;
        end
    end

    always @ (posedge clk100mhz) begin
            write_read <= 1;
            LED <= dataBus;
    end
            
endmodule
