module IFU(
	input clk,
	input nPC_sel,
	input [31:0]TargetAddress,
	output [31:0]InstructionWord
	);
wire [31:0]pc;
reg [31:0]pc_clk;
wire [31:0]adderout;
reg [31:0]InstructionMem[31:0];
 
integer i;
initial begin 
   for(i=0;i<32;i=i+1) 
     InstructionMem[i]<=i; 
end
assign pc = nPC_sel?TargetAddress:adderout;

always @(posedge clk) begin
	pc_clk=pc;
	if(pc_clk>=24) pc_clk=pc_clk%4;
end

assign adderout = pc_clk+4;
assign InstructionWord = InstructionMem[pc_clk/4];
endmodule
