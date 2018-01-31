module ttSRAM;
  reg [7:0] datain;
  reg [1:0] address;
  reg RW;
  reg okay;
  reg LDAR;
  
  wire [7:0] dataout;
  
  SRAM s(dataout,datain,address,RW,okay,LDAR);
  initial
  begin
         address=2'b00;datain=8'b00000000;RW=0;okay=0;LDAR=1;
    #100 okay=1;
    #50  okay=0;LDAR=0;
    #50  okay=1;
    #50  address=2'b01;datain=8'b00010001;okay=0;LDAR=1;
    #50  okay=1;
    #50  okay=0;LDAR=0;
    #50  okay=1;
    #50  address=2'b10;datain=8'b00100010;okay=0;LDAR=1;
    #50  okay=1;
    #50  okay=0;LDAR=0;
    #50  okay=1;
    #50  address=2'b11;datain=8'b00110011;okay=0;LDAR=1;
    #50  okay=1;
    #50  okay=0;LDAR=0;
    #50  okay=1;
    #50  address=2'b00;RW=1;okay=0;LDAR=1;
    #50  okay=1;
    #50  okay=0;LDAR=0;
    #50  okay=1;
    #50  address=2'b01;okay=0;LDAR=1;
    #50  okay=1;
    #50  okay=0;LDAR=0;
    #50  okay=1;
    #50  address=2'b10;okay=0;LDAR=1;
    #50  okay=1;
    #50  okay=0;LDAR=0;
    #50  okay=1;
    #50  address=2'b11;okay=0;LDAR=1;
    #50  okay=1;
    #50  okay=0;LDAR=0;
    #50  okay=1;
    #100$stop;
  end
endmodule

