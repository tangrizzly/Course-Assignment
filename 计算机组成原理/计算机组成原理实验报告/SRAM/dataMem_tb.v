module DataMemory_tb;
reg clk;
reg [31:0]DataIn,Adr;
reg WrEn;
wire [31:0]out;
DataMemory t1(clk,DataIn,WrEn,Adr,out); 
initial begin
	WrEn=1;
	DataIn=32'b11010101110011100101001000010011;
	Adr=1;
	clk=0;
	#3 Adr=2;
	DataIn=32'b010100110101010000101001001010;
	#4 WrEn=0; Adr=1;
	#2 Adr=2;
	#2 $finish;
end
always  begin
	#2 clk=~clk;
end
endmodule