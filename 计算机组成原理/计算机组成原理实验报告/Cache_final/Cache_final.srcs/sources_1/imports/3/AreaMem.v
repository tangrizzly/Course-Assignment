module AreaMem(dataout,datain,address,CLR,RW);
  output [3:0] dataout;
  input [3:0] datain;
  input [2:0] address;
  input CLR;
  input RW;

  reg [3:0] data1,data2,data3,data4,
            data5,data6,data7,data8;
  reg [2:0] addr;
  reg [3:0] dataout;

  always @(*)
  begin
    if(CLR==1)
      begin
        data1 = 0;
        data2 = 0;
        data3 = 0;
        data4 = 0;
        data5 = 0;
        data6 = 0;
        data7 = 0;
        data8 = 0;
        dataout = 0;
      end
    else if(RW==0)
      case (addr)
        3'b000:data1=datain;
        3'b001:data2=datain;
        3'b010:data3=datain;
        3'b011:data4=datain;
        3'b100:data5=datain;
        3'b101:data6=datain;
        3'b110:data7=datain;
        3'b111:data8=datain;
        default:;
      endcase
    else if(RW==1)
      case (addr)
        3'b000:dataout=data1;
        3'b001:dataout=data2;
        3'b010:dataout=data3;
        3'b011:dataout=data4;
        3'b100:dataout=data5;
        3'b101:dataout=data6;
        3'b110:dataout=data7;
        3'b111:dataout=data8;
        default:;
      endcase
  end
endmodule