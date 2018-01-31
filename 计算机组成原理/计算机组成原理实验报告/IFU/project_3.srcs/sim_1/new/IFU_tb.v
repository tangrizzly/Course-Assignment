module IFU_tb;
reg clk,nPC_sel;
reg [31:0]TargetAddress;
wire [31:0]InstructionWord;

IFU u1(clk,nPC_sel,TargetAddress,InstructionWord);

initial begin
	clk=0;
	nPC_sel=1;
	TargetAddress=1;
	#2 nPC_sel=0;
	#20 $finish;
end

always  begin
	#1 clk=~clk;
end

endmodule