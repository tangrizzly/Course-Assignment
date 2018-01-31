module Ctrl(
	input [31:0]InstructionWord,
	output nPC_sel,RegWr,RegDst,ExtOp,ALUSrc,MEMWr,MemtoReg,
	output [1:0]ALUCtrl,
	output [4:0]rs,rt,rd,
	output [15:0]imm16
	);
parameter ADD = 00;
parameter SUB = 01;
parameter OR = 10;
parameter ZERO = 0;//进行零扩展
parameter SIGN = 1;//进行位扩展

wire [5:0]op;
wire [5:0]func;

assign op = InstructionWord[31:26];
assign func = InstructionWord[5:0];
assign rs = InstructionWord[25:21];
assign rt = InstructionWord[20:16];
assign rd = InstructionWord[15:11];
assign imm16 = InstructionWord[15:0];

wire rtype;
assign rtype = ~op[5]&~op[4]&~op[3]&~op[2]&~op[1]&~op[0];

assign add = rtype&func[5]&~func[4]&~func[3]&~func[2]&~func[1]&~func[0];
assign sub = rtype&func[5]&~func[4]&~func[3]&~func[2]&func[1]&~func[0];
assign ori = ~op[5]&~op[4]&op[3]&op[2]&~op[1]&op[0];
assign lw = op[5]&~op[4]&~op[3]&~op[2]&op[1]&op[0];
assign sw = op[5]&~op[4]&op[3]&~op[2]&op[1]&op[0];
assign beq = ~op[5]&~op[4]&~op[3]&op[2]&~op[1]&~op[0];

assign RegDst = add||sub;
assign ALUSrc = ori||lw||sw;
assign MemtoReg = lw;
assign RegWr = !(sw||beq);
assign MEMWr = sw;
assign nPC_sel = beq;
assign ExtOp = lw||sw;
assign ALUCtrl= (add||lw||sw)?00:((sub||beq)?01:10);

/*
//加法指令控制信号
RegDst=1;RegWr=1;ExtOp=x;ALUSrc=0;ALUCtr=ADD;
MEMWr=0;MemtoReg=0;nPC_sel=0;
//减法指令控制信号
RegDst=1;RegWr=1;ExtOp=x;ALUSrc=0;ALUCtr=SUB;
MEMWr=0;MemtoReg=0;nPC_sel=0;
//逻辑或指令控制信号
RegDst=0;RegWr=1;ExtOp=ZERO;ALUSrc=1;ALUCtr=OR;
MEMWr=0;MemtoReg=0;nPC_sel=0;
//Load指令的控制信号
RegDst=0;RegWr=1;ExtOp=SIGN;ALUSrc=1;ALUCtr=ADD;
MEMWr=0;MemtoReg=1;nPC_sel=0;
//Store指令的控制信号
RegDst=x;RegWr=0;ExtOp=SIGN;ALUSrc=1;ALUCtr=ADD;
MEMWr=1;MemtoReg=x;nPC_sel=0;
//beq指令的控制信号
RegDst=x;RegWr=0;ExtOp=x;ALUSrc=0;ALUCtr=SUB;
MEMWr=0;MemtoReg=x;nPC_sel=1;
*/

endmodule