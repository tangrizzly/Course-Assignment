`timescale 1ns / 1ps
module seqdetea(
   input clk,clr,din,
   output reg dout
    );
    reg [2:0] present_state,next_state;
    parameter S0=3'b000,S1=3'b001,S2=3'b010,S3=3'b011,S4=3'b100;
    always@(posedge clk or posedge clr)
    begin
     if(clr == 1)
      present_state<=S0;
      else
      present_state<=next_state;
      end
     
     always@(*)
     begin
      case(present_state)
       S0:if(din==1)
            next_state<=S1;
            else
            next_state<=S0;
       S1:if(din==1)
             next_state<=S2;
             else
             next_state<=S0;
       S2:if(din==0)
              next_state<=S3;
              else
              next_state<=S2;
       S3:if(din==1)
           next_state<=S4;
           else
           next_state<=S0; 
       S4:if(din==0)
               next_state<=S0;
               else
               next_state<=S2; 
       default:next_state<=S0;
        endcase
       end
always@(*)
   begin
      if(present_state==S4)
          dout =1;
      else
          dout =0;
     end         
endmodule
