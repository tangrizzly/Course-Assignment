module Ctrl_tb;
reg [31:0]InstructionWord;
wire nPC_sel,RegWr,RegDst,ExtOp,ALUSrc,MEMWr,MemtoReg;
wire [1:0]ALUCtrl;
wire [4:0]rs,rt,rd;
wire [15:0]imm16;
Ctrl u0(InstructionWord,nPC_sel,RegWr,RegDst,ExtOp,ALUSrc,MEMWr,MemtoReg,ALUCtrl,rs,rt,rd,imm16);
initial begin
InstructionWord=32'b0000000000000000_10101_00011_11010_100000;
end
endmodule