`timescale 1ns / 1ps
module regfile(
	input RegWr,
	input [4:0]rd,rs,rt,
	input [31:0]busW,
	input clk,
	output [31:0]busA,busB
	);
endmodule


module Dlatch32(clk,data,e,q);
input clk,e;
input [31:0]data;
output [31:0]q;
always @(posedge clk) begin
	q=data;
end
endmodule

module Mux8to1(
	input [2:0]e,clk,
	input [31:0]data0,data1,data2,data3,data4,data5,
		data6,data7,
	output [31:0]out
	);
always @(posedge clk) begin
	case(e)
		0:out=data0;
		1:out=data1;
		2:out=data2;
		3:out=data3;
		4:out=data4;
		5:out=data5;
		6:out=data6;
		7:out=data7;
		default:out=0;
	endcase
end
endmodule

module Mux4to1(
	input [2:0]e,clk,
	input [31:0]data0,data1,data2,data3,
	output [31:0]out
	);
always @(posedge clk) begin
	case(e)
		0:out=data[0];
		1:out=data[1];
		2:out=data[2];
		3:out=data[3];
		default:out=0;
	endcase
end

module Mux(
	input [31:0]data0,data1,data2,data3,data4,data5,
		data6,data7,data8,data9,data10,data11,
		data12,data13,data14,data15,data16,
		data17,data18,data19,data20,data21,
		data22,data23,data24,data25,data26,
		data27,data28,data29,data30,data31,
	input [4:0]ra,
	output [31:0]bus
	);
wire[31:0] out0,out1,out2,out3,out4;
Mux8to1 m0(ra[2:0],clk,data0,data1,data2,data3,data4,data5,data6,data7,out0);
Mux8to1 m0(ra[2:0],clk,data8,data9,data10,data11,data12,data5,data6,data7,out0);
Mux8to1 m0(ra[2:0],clk,data0,data1,data2,data3,data4,data5,data6,data7,out0);
Mux8to1 m0(ra[2:0],clk,data0,data1,data2,data3,data4,data5,data6,data7,out0);
Mux4to1 m0(ra[4:3],clk,data0,data1,data2,data3,data4,data5,data6,data7,out0);
endmodule


module decoder(
output [31:0]out,
input [4:0]in
	);//输出低电平有效
wire [4:0]_in;
not n1(_in[0],in[0]);
not n2(_in[1],in[1]);
not n3(_in[2],in[2]);
not n4(_in[3],in[3]);
not n5(_in[4],in[4]);
nand a0(out[0],_in[0],_in[1],_in[2],_in[3],_in[4]);
nand a1(out[1],in[0],_in[1],_in[2],_in[3],_in[4]);
nand a2(out[2],_in[0],in[1],_in[2],_in[3],_in[4]);
nand a3(out[3],in[0],in[1],_in[2],_in[3],_in[4]);
nand a4(out[4],_in[0],_in[1],in[2],_in[3],_in[4]);
nand a5(out[5],in[0],_in[1],in[2],_in[3],_in[4]);
nand a6(out[6],_in[0],in[1],in[2],_in[3],_in[4]);
nand a7(out[7],in[0],in[1],in[2],_in[3],_in[4]);
nand a8(out[8],_in[0],_in[1],_in[2],in[3],_in[4]);
nand a9(out[9],in[0],_in[1],_in[2],in[3],_in[4]);
nand a10(out[10],_in[0],in[1],_in[2],in[3],_in[4]);
nand a11(out[11],in[0],in[1],_in[2],in[3],_in[4]);
nand a12(out[12],_in[0],_in[1],in[2],in[3],_in[4]);
nand a13(out[13],in[0],_in[1],in[2],in[3],_in[4]);
nand a14(out[14],_in[0],in[1],in[2],in[3],_in[4]);
nand a15(out[15],in[0],in[1],in[2],in[3],_in[4]);
nand a16(out[16],_in[0],_in[1],_in[2],_in[3],in[4]);
nand a17(out[17],in[0],_in[1],_in[2],_in[3],in[4]);
nand a18(out[18],_in[0],in[1],_in[2],_in[3],in[4]);
nand a19(out[19],in[0],in[1],_in[2],_in[3],in[4]);
nand a20(out[20],_in[0],_in[1],in[2],_in[3],in[4]);
nand a21(out[21],in[0],_in[1],in[2],_in[3],in[4]);
nand a22(out[22],_in[0],in[1],in[2],_in[3],in[4]);
nand a23(out[23],in[0],in[1],in[2],_in[3],in[4]);
nand a24(out[24],_in[0],_in[1],_in[2],in[3],in[4]);
nand a25(out[25],in[0],_in[1],_in[2],in[3],in[4]);
nand a26(out[26],_in[0],in[1],_in[2],in[3],in[4]);
nand a27(out[27],in[0],in[1],_in[2],in[3],in[4]);
nand a28(out[28],_in[0],_in[1],in[2],in[3],in[4]);
nand a29(out[29],in[0],_in[1],in[2],in[3],in[4]);
nand a30(out[30],_in[0],in[1],in[2],in[3],in[4]);
nand a31(out[31],in[0],in[1],in[2],in[3],in[4]);
endmodule


module write(
	input en_write,//低电平有效，开始将data写入寄存器
	input [5:1]reg_num,
	output [31:0]w2
	);
wire [31:0]w1;
decoder d0(w1,reg_num);
nor nr1(w2[0],en_write,w1[0]);
nor nr2(w2[1],en_write,w1[1]);
nor nr3(w2[2],en_write,w1[2]);
nor nr4(w2[3],en_write,w1[3]);
nor nr5(w2[4],en_write,w1[4]);
nor nr6(w2[5],en_write,w1[5]);
nor nr7(w2[6],en_write,w1[6]);
nor nr8(w2[7],en_write,w1[7]);
nor nr9(w2[8],en_write,w1[8]);
nor nr10(w2[9],en_write,w1[9]);
nor nr11(w2[10],en_write,w1[10]);
nor nr12(w2[11],en_write,w1[11]);
nor nr13(w2[12],en_write,w1[12]);
nor nr14(w2[13],en_write,w1[13]);
nor nr15(w2[14],en_write,w1[14]);
nor nr16(w2[15],en_write,w1[15]);
nor nr17(w2[16],en_write,w1[16]);
nor nr18(w2[17],en_write,w1[17]);
nor nr19(w2[18],en_write,w1[18]);
nor nr20(w2[19],en_write,w1[19]);
nor nr21(w2[20],en_write,w1[20]);
nor nr22(w2[21],en_write,w1[21]);
nor nr23(w2[22],en_write,w1[22]);
nor nr24(w2[23],en_write,w1[23]);
nor nr25(w2[24],en_write,w1[24]);
nor nr26(w2[25],en_write,w1[25]);
nor nr27(w2[26],en_write,w1[26]);
nor nr28(w2[27],en_write,w1[27]);
nor nr29(w2[28],en_write,w1[28]);
nor nr30(w2[29],en_write,w1[29]);
nor nr31(w2[30],en_write,w1[30]);
endmodule

module read(
	input [4:0]ra1,ra2,
	input [31:0]data0,
	input [31:0]data1,
	input [31:0]data2,
	input [31:0]data3,
	input [31:0]data4,
	input [31:0]data5,
	input [31:0]data6,
	input [31:0]data7,
	input [31:0]data8,
	input [31:0]data9,
	input [31:0]data10,
	input [31:0]data11,
	input [31:0]data12,
	input [31:0]data13,
	input [31:0]data14,
	input [31:0]data15,
	input [31:0]data16,
	input [31:0]data17,
	input [31:0]data18,
	input [31:0]data19,
	input [31:0]data20,
	input [31:0]data21,
	input [31:0]data22,
	input [31:0]data23,
	input [31:0]data24,
	input [31:0]data25,
	input [31:0]data26,
	input [31:0]data27,
	input [31:0]data28,
	input [31:0]data29,
	input [31:0]data30,
	input [31:0]data31,
	output [31:0]rd1,rd2
	);
Mux m1(data0,data1,data2,data3,data4,
	data5,data6,data7,data8,data9,data10,
	data11,data12,data13,data14,data15,
	data16,data17,data18,data19,data20,
	data21,data22,data23,data24,data25,
	data26,data27,data28,data29,data30,
	data31,ra1,rd1);
Mux m2(data0,data1,data2,data3,data4,
	data5,data6,data7,data8,data9,data10,
	data11,data12,data13,data14,data15,
	data16,data17,data18,data19,data20,
	data21,data22,data23,data24,data25,
	data26,data27,data28,data29,data30,
	data31,ra2,rd2);
endmodule

module RegisterFile(
	input [4:0]ra1,ra2,wa,
	input [31:0]wd,
	input en_write,//低电平有效
	output [31:0]rd1,rd2
	);
wire [31:0]w2;
wire [31:0]data0,data1,data2,data3,data4,
	data5,data6,data7,data8,data9,data10,
	data11,data12,data13,data14,data15,
	data16,data17,data18,data19,data20,
	data21,data22,data23,data24,data25,
	data26,data27,data28,data29,data30,
	data31;
write w1(en_write,wa,w2);
read r0(ra1,ra2,data0,data1,data2,data3,data4,
	data5,data6,data7,data8,data9,data10,
	data11,data12,data13,data14,data15,
	data16,data17,data18,data19,data20,
	data21,data22,data23,data24,data25,
	data26,data27,data28,data29,data30,
	data31,rd1,rd2);
Dlatch32 d0(wd,w2[0],data0);
Dlatch32 d1(wd,w2[1],data1);
Dlatch32 d2(wd,w2[2],data2);
Dlatch32 d3(wd,w2[3],data3);
Dlatch32 d4(wd,w2[4],data4);
Dlatch32 d5(wd,w2[5],data5);
Dlatch32 d6(wd,w2[6],data6);
Dlatch32 d7(wd,w2[7],data7);
Dlatch32 d8(wd,w2[8],data8);
Dlatch32 d9(wd,w2[9],data9);
Dlatch32 d10(wd,w2[10],data10);
Dlatch32 d11(wd,w2[11],data11);
Dlatch32 d12(wd,w2[12],data12);
Dlatch32 d13(wd,w2[13],data13);
Dlatch32 d14(wd,w2[14],data14);
Dlatch32 d15(wd,w2[15],data15);
Dlatch32 d16(wd,w2[16],data16);
Dlatch32 d17(wd,w2[17],data17);
Dlatch32 d18(wd,w2[18],data18);
Dlatch32 d19(wd,w2[19],data19);
Dlatch32 d20(wd,w2[20],data20);
Dlatch32 d21(wd,w2[21],data21);
Dlatch32 d22(wd,w2[22],data22);
Dlatch32 d23(wd,w2[23],data23);
Dlatch32 d24(wd,w2[24],data24);
Dlatch32 d25(wd,w2[25],data25);
Dlatch32 d26(wd,w2[26],data26);
Dlatch32 d27(wd,w2[27],data27);
Dlatch32 d28(wd,w2[28],data28);
Dlatch32 d29(wd,w2[29],data29);
Dlatch32 d30(wd,w2[30],data30);
Dlatch32 d31(wd,w2[31],data31);
endmodule
