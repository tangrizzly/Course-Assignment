module CacheMem(dataout,datain,address,CLR,RW);
  output [7:0] dataout;
  input [7:0] datain;
  input [4:0] address;
  input CLR;
  input RW;     //read1,write0
  reg [7:0] data0,data1,data2,data3,data4,data5,data6,data7,
            data8,data9,data10,data11,data12,data13,data14,data15,
            data16,data17,data18,data19,data20,data21,data22,data23,
            data24,data25,data26,data27,data28,data29,data30,data31;
  reg [4:0] addr;
  reg [7:0] dataout;

  always @(*)
  begin
    if(CLR==1)
    begin
      data0 = 0;
      data1 = 0;
      data2 = 0;
      data3 = 0;
      data4 = 0;
      data5 = 0;
      data6 = 0;
      data7 = 0;
      data8 = 0;
      data9 = 0;
      data10 = 0;
      data11 = 0;
      data12 = 0;
      data13 = 0;
      data14 = 0;
      data15 = 0;
      data16 = 0;
      data17 = 0;
      data18 = 0;
      data19 = 0;
      data20 = 0;
      data21 = 0;
      data22 = 0;
      data23 = 0;
      data24 = 0;
      data25 = 0;
      data26 = 0;
      data27 = 0;
      data28 = 0;
      data29 = 0;
      data30 = 0;
      data31 = 0;
    end
    else if(RW==0)
    begin
      addr=address;
      case (addr)
        5'b00000:data0=datain;
        5'b00001:data1=datain;
        5'b00010:data2=datain;
        5'b00011:data3=datain;
        5'b00100:data4=datain;
        5'b00101:data5=datain;
        5'b00110:data6=datain;
        5'b00111:data7=datain;
        5'b01000:data8=datain;
        5'b01001:data9=datain;
        5'b01010:data10=datain;
        5'b01011:data11=datain;
        5'b01100:data12=datain;
        5'b01101:data13=datain;
        5'b01110:data14=datain;
        5'b01111:data15=datain;
        5'b10000:data16=datain;
        5'b10001:data17=datain;
        5'b10010:data18=datain;
        5'b10011:data19=datain;
        5'b10100:data20=datain;
        5'b10101:data21=datain;
        5'b10110:data22=datain;
        5'b10111:data23=datain;
        5'b11000:data24=datain;
        5'b11001:data25=datain;
        5'b11010:data26=datain;
        5'b11011:data27=datain;
        5'b11100:data28=datain;
        5'b11101:data29=datain;
        5'b11110:data30=datain;
        5'b11111:data31=datain;
        default:;
      endcase
    end
    else if(RW==1)
    begin
      addr=address;
      case (addr)
        5'b00000:dataout=data0;
        5'b00001:dataout=data1;
        5'b00010:dataout=data2;
        5'b00011:dataout=data3;
        5'b00100:dataout=data4;
        5'b00101:dataout=data5;
        5'b00110:dataout=data6;
        5'b00111:dataout=data7;
        5'b01000:dataout=data8;
        5'b01001:dataout=data9;
        5'b01010:dataout=data10;
        5'b01011:dataout=data11;
        5'b01100:dataout=data12;
        5'b01101:dataout=data13;
        5'b01110:dataout=data14;
        5'b01111:dataout=data15;
        5'b10000:dataout=data16;
        5'b10001:dataout=data17;
        5'b10010:dataout=data18;
        5'b10011:dataout=data19;
        5'b10100:dataout=data20;
        5'b10101:dataout=data21;
        5'b10110:dataout=data22;
        5'b10111:dataout=data23;
        5'b11000:dataout=data24;
        5'b11001:dataout=data25;
        5'b11010:dataout=data26;
        5'b11011:dataout=data27;
        5'b11100:dataout=data28;
        5'b11101:dataout=data29;
        5'b11110:dataout=data30;
        5'b11111:dataout=data31;
        default:;
      endcase
    end
  end
endmodule