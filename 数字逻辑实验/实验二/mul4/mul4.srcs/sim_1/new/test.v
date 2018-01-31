`timescale 1ns / 1ps

module test;
    reg [3:0]a;
    reg [3:0]b;
    wire [7:0]p;
    
    initial begin
        a = 0;
        b = 0;
        repeat(10) begin
            #10 a = {$random}%16;
                   b = {$random}%16;
        end
        #10 $stop;
    end
    
    mul    u0(a,b,p);
endmodule
