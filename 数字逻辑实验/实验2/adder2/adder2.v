`timescale 1ns / 1ps
`timescale 1ns / 1ps
module carrylookahead4(
	input [3:0]a,b,
	input cin,
	output cout,
	output [3:0]s
	);
wire [3:0]G,P,C;
assign G = a&b;
assign P = a^b;
assign C[0]=cin;
assign C[1] = G[0]|P[0]&C[0];
assign C[2] = G[1]|P[1]&G[0]|P[1]&P[0]&C[0];
assign C[3] = G[2]|P[2]&G[1]|P[2]&P[1]&G[0]|P[2]&P[1]&P[0]&C[0];
assign cout = G[3]|P[3]&G[2]|P[3]&P[2]&G[1]|P[3]&P[2]&P[1]&G[0]|P[3]&P[2]&P[1]&P[0]&C[0];
assign s = P^C;
endmodule

module carrylookahead8(
	input [7:0]a,b,
	input cin,
	output cout,
	output [7:0]s
	);
wire c;
carrylookahead4 c1(a[3:0],b[3:0],cin,c,s[3:0]);
carrylookahead4 c2(a[7:4],b[7:4],c,cout,s[7:4]);
endmodule
