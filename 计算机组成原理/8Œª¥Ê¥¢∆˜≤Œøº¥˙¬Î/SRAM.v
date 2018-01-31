module SRAM(dataout,datain,address,RW,okay,LDAR);
  output [7:0] dataout;
  
  input [7:0] datain;
  input [1:0] address;
  input RW;     //read1,write0
  input okay;
  input LDAR;
  
  reg [7:0] a;
  reg [7:0] b;
  reg [7:0] c;
  reg [7:0] d;
  reg [1:0] addr;
  reg [7:0] dataout;
  
  always @(okay)
  begin
    if(okay==1)
      begin
      if(LDAR==1)
        addr=address;
      else if(RW==0)
        case (addr)
          2'b00:a=datain;
          2'b01:b=datain;
          2'b10:c=datain;
          2'b11:d=datain;
          default:;
        endcase
      else if(RW==1)
        case (addr)
          2'b00:dataout=a;
          2'b01:dataout=b;
          2'b10:dataout=c;
          2'b11:dataout=d;
          default:;
        endcase
      end
      
  end
endmodule