`timescale 1ns / 1ps
module div84_sim();
  reg[15:0] numerator;
  reg[7:0] denominator;
  wire [15:0]quotient;
  wire [7:0] remainder;
  div8 U2(numerator,denominator,quotient,remainder);
  initial
   begin
   numerator=0;
   denominator=1;
   repeat(10)
     begin
           #10 numerator={$random}%128+63;
               denominator={$random}%63;
  end
  #10 $stop;
  end
endmodule