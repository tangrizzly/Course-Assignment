`timescale 1ns / 1ps

module test;
    reg [7:0] numerator;
    reg [3:0] denominator;
    wire [7:0] quotient;
    wire [3:0] remainder;

    initial begin
        numerator=0;
        denominator=1;
        repeat(10) begin
            #10 numerator=($random)%16+7;
            denominator=($random)%16+1;
        end
        #10 $stop;
    end
    
    div4 U1(.numerator(numerator),.denominator (denominator),.quotient (quotient),.remainder(remainder));
endmodule
