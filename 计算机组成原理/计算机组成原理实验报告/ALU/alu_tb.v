module ALU_tb;
reg [1:0]ALUCtr;
reg [31:0]busA,busB;
wire [31:0]busW;
initial begin
	busA=7892;
	busB=5631;
	ALUCtr=00;
	#5 ALUCtr=01;
	#5 ALUCtr=10;
	#5 $finish;
end
ALU u0(ALUCtr,busA,busB,busW);


endmodule