module ALU(
	input [1:0]ALUCtr,
	input [31:0]busA,busB,
	output [31:0]busW
	);
wire [31:0]b;
wire  [31:0]subb,s,s2;
assign subb=(~busB)-1;
assign b = ALUCtr[0]?subb:busB;
assign cin=0;
carrylookahead32 adder(busA,b,cin,cout,s);
assign s2 = busA||busB;
assign busW = ALUCtr[1]?s2:s;//ALUCtr=00为加，=01为减，=10为逻辑或运算。
endmodule

module carrylookahead4(
	input [3:0]a,b,
	input cin,
	output [3:0]s,
	output Pm,Gm
	);
wire [3:0]G,P,C;
assign G = a&b;
assign P = a^b;
assign C[0]=cin;
assign C[1] = G[0]|P[0]&C[0];
assign C[2] = G[1]|P[1]&G[0]|P[1]&P[0]&C[0];
assign C[3] = G[2]|P[2]&G[1]|P[2]&P[1]&G[0]|P[2]&P[1]&P[0]&C[0];
assign s = P^C;
assign Pm = &P;
assign Gm = G[3]|P[3]&G[2]|P[3]&P[2]&G[1]|P[3]&P[2]&P[1]&G[0];
endmodule

module carrylookahead32(
	input [31:0]a,b,
	input cin,
	output cout,
	output [31:0]s
	);
wire [7:0]C;
wire [8:1]Pm,Gm;
wire Pmx,Gmx;
assign C[0]=cin;
assign C[1]=Gm[1]|Pm[1]&C[0];
assign C[2]=Gm[2]|Pm[2]&Gm[1]|Pm[2]&Pm[1]&C[0];
assign C[3]=Gm[3]|Pm[3]&Gm[2]|Pm[3]&Pm[2]&Gm[1]|Pm[3]&Pm[2]&Pm[1]&C[0];
carrylookahead4 c1(a[3:0],b[3:0],cin,s[3:0],Pm[1],Gm[1]);
carrylookahead4 c2(a[7:4],b[7:4],C[1],s[7:4],Pm[2],Gm[2]);
carrylookahead4 c3(a[11:8],b[11:8],C[2],s[11:8],Pm[3],Gm[3]);
carrylookahead4 c4(a[15:12],b[15:12],C[3],s[15:12],Pm[4],Gm[4]);
assign Gmx=Gm[4]|Pm[4]&Gm[3]|Pm[4]&Pm[3]&Gm[2]|Pm[4]&Pm[3]&Pm[2]&Gm[1];
assign Pmx=Pm[4]&Pm[3]&Pm[2]&Pm[1];
assign C[4]=Gmx+Pmx&C[0];
assign C[5]=Gm[5]|Pm[5]&C[4];
assign C[6]=Gm[6]|Pm[6]&Gm[5]|Pm[6]&Pm[5]&C[4];
assign C[7]=Gm[7]|Pm[7]&Gm[6]|Pm[7]&Pm[6]&Gm[5]|Pm[7]&Pm[6]&Pm[5]&C[4];
carrylookahead4 c5(a[19:16],b[19:16],C[4],s[19:16],Pm[5],Gm[5]);
carrylookahead4 c6(a[23:20],b[23:20],C[5],s[23:20],Pm[6],Gm[6]);
carrylookahead4 c7(a[27:24],b[27:24],C[6],s[27:24],Pm[7],Gm[7]);
carrylookahead4 c8(a[31:28],b[31:28],C[7],s[31:28],Pm[8],Gm[8]);
assign cout=Gm[8]|Pm[8]&Gm[7]|Pm[8]&Pm[7]&Gm[6]|Pm[8]&Pm[7]&Pm[6]&Gm[5]|Pm[8]&Pm[7]&Pm[6]&Pm[5]&C[4];
endmodule