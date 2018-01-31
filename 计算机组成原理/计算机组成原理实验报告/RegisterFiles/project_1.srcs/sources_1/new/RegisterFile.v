

`timescale 1ns / 1ps
module Dlatch(d,e,q,_q);
input d,e;
output reg q,_q;
always@(posedge e)
begin
	if(e==1)
	begin
		q=d;_q=~d;
	end
end
endmodule

module Dlatch32(data,e,q);
input e;
input [31:0]data;
output [31:0]q;
wire [31:0]_q;
Dlatch d0(data[0],e,q[0],_q[0]);
Dlatch d1(data[1],e,q[1],_q[1]);
Dlatch d2(data[2],e,q[2],_q[2]);
Dlatch d3(data[3],e,q[3],_q[3]);
Dlatch d4(data[4],e,q[4],_q[4]);
Dlatch d5(data[5],e,q[5],_q[5]);
Dlatch d6(data[6],e,q[6],_q[6]);
Dlatch d7(data[7],e,q[7],_q[7]);
Dlatch d8(data[8],e,q[8],_q[8]);
Dlatch d9(data[9],e,q[9],_q[9]);
Dlatch d10(data[10],e,q[10],_q[10]);
Dlatch d11(data[11],e,q[11],_q[11]);
Dlatch d12(data[12],e,q[12],_q[12]);
Dlatch d13(data[13],e,q[13],_q[13]);
Dlatch d14(data[14],e,q[14],_q[14]);
Dlatch d15(data[15],e,q[15],_q[15]);
Dlatch d16(data[16],e,q[16],_q[16]);
Dlatch d17(data[17],e,q[17],_q[17]);
Dlatch d18(data[18],e,q[18],_q[18]);
Dlatch d19(data[19],e,q[19],_q[19]);
Dlatch d20(data[20],e,q[20],_q[20]);
Dlatch d21(data[21],e,q[21],_q[21]);
Dlatch d22(data[22],e,q[22],_q[22]);
Dlatch d23(data[23],e,q[23],_q[23]);
Dlatch d24(data[24],e,q[24],_q[24]);
Dlatch d25(data[25],e,q[25],_q[25]);
Dlatch d26(data[26],e,q[26],_q[26]);
Dlatch d27(data[27],e,q[27],_q[27]);
Dlatch d28(data[28],e,q[28],_q[28]);
Dlatch d29(data[29],e,q[29],_q[29]);
Dlatch d30(data[30],e,q[30],_q[30]);
Dlatch d31(data[31],e,q[31],_q[31]);
Dlatch d32(data[32],e,q[32],_q[32]);
endmodule

module Mux32(
	input e1,e2,e3,e4,e5,
	input [31:0]data,
	output [31:0]out
	);
wire e;
and a(e,e1,e2,e3,e4,e5);
and a0(out[0],data[0],e);
and a1(out[1],data[1],e);
and a2(out[2],data[2],e);
and a3(out[3],data[3],e);
and a4(out[4],data[4],e);
and a5(out[5],data[5],e);
and a6(out[6],data[6],e);
and a7(out[7],data[7],e);
and a8(out[8],data[8],e);
and a9(out[9],data[9],e);
and a10(out[10],data[10],e);
and a11(out[11],data[11],e);
and a12(out[12],data[12],e);
and a13(out[13],data[13],e);
and a14(out[14],data[14],e);
and a15(out[15],data[15],e);
and a16(out[16],data[16],e);
and a17(out[17],data[17],e);
and a18(out[18],data[18],e);
and a19(out[19],data[19],e);
and a20(out[20],data[20],e);
and a21(out[21],data[21],e);
and a22(out[22],data[22],e);
and a23(out[23],data[23],e);
and a24(out[24],data[24],e);
and a25(out[25],data[25],e);
and a26(out[26],data[26],e);
and a27(out[27],data[27],e);
and a28(out[28],data[28],e);
and a29(out[29],data[29],e);
and a30(out[30],data[30],e);
and a31(out[31],data[31],e);
endmodule

module Mux(
	input [31:0]data0,data1,data2,data3,data4,data5,
		data6,data7,data8,data9,data10,data11,
		data12,data13,data14,data15,data16,
		data17,data18,data19,data20,data21,
		data22,data23,data24,data25,data26,
		data27,data28,data29,data30,data31,
	input [4:0]ra,
	output [31:0]rd
	);
wire [4:0]_ra;
wire [31:0]rd0,rd1,rd2,rd3,rd4,rd5,
		rd6,rd7,rd8,rd9,rd10,rd11,
		rd12,rd13,rd14,rd15,rd16,
		rd17,rd18,rd19,rd20,rd21,
		rd22,rd23,rd24,rd25,rd26,
		rd27,rd28,rd29,rd30,rd31;
not n1(_ra[1],ra[1]);
not n2(_ra[2],ra[2]);
not n3(_ra[3],ra[3]);
not n4(_ra[4],ra[4]);
not n5(_ra[0],ra[0]);
Mux32 m0(_ra[0],_ra[1],_ra[2],_ra[3],_ra[4],data0,rd0);
Mux32 m1(ra[0],_ra[1],_ra[2],_ra[3],_ra[4],data1,rd1);
Mux32 m2(_ra[0],ra[1],_ra[2],_ra[3],_ra[4],data2,rd2);
Mux32 m3(ra[0],ra[1],_ra[2],_ra[3],_ra[4],data3,rd3);
Mux32 m4(_ra[0],_ra[1],ra[2],_ra[3],_ra[4],data4,rd4);
Mux32 m5(ra[0],_ra[1],ra[2],_ra[3],_ra[4],data5,rd5);
Mux32 m6(_ra[0],ra[1],ra[2],_ra[3],_ra[4],data6,rd6);
Mux32 m7(ra[0],ra[1],ra[2],_ra[3],_ra[4],data7,rd7);
Mux32 m8(_ra[0],_ra[1],_ra[2],ra[3],_ra[4],data8,rd8);
Mux32 m9(ra[0],_ra[1],_ra[2],ra[3],_ra[4],data9,rd9);
Mux32 m10(_ra[0],ra[1],_ra[2],ra[3],_ra[4],data10,rd10);
Mux32 m11(ra[0],ra[1],_ra[2],ra[3],_ra[4],data11,rd11);
Mux32 m12(_ra[0],_ra[1],ra[2],ra[3],_ra[4],data12,rd12);
Mux32 m13(ra[0],_ra[1],ra[2],ra[3],_ra[4],data13,rd13);
Mux32 m14(_ra[0],ra[1],ra[2],ra[3],_ra[4],data14,rd14);
Mux32 m15(ra[0],ra[1],ra[2],ra[3],_ra[4],data15,rd15);
Mux32 m16(_ra[0],_ra[1],_ra[2],_ra[3],ra[4],data16,rd16);
Mux32 m17(ra[0],_ra[1],_ra[2],_ra[3],ra[4],data17,rd17);
Mux32 m18(_ra[0],ra[1],_ra[2],_ra[3],ra[4],data18,rd18);
Mux32 m19(ra[0],ra[1],_ra[2],_ra[3],ra[4],data19,rd19);
Mux32 m20(_ra[0],_ra[1],ra[2],_ra[3],ra[4],data20,rd20);
Mux32 m21(ra[0],_ra[1],ra[2],_ra[3],ra[4],data21,rd21);
Mux32 m22(_ra[0],ra[1],ra[2],_ra[3],ra[4],data22,rd22);
Mux32 m23(ra[0],ra[1],ra[2],_ra[3],ra[4],data23,rd23);
Mux32 m24(_ra[0],_ra[1],_ra[2],ra[3],ra[4],data24,rd24);
Mux32 m25(ra[0],_ra[1],_ra[2],ra[3],ra[4],data25,rd25);
Mux32 m26(_ra[0],ra[1],_ra[2],ra[3],ra[4],data26,rd26);
Mux32 m27(ra[0],ra[1],_ra[2],ra[3],ra[4],data27,rd27);
Mux32 m28(_ra[0],_ra[1],ra[2],ra[3],ra[4],data28,rd28);
Mux32 m29(ra[0],_ra[1],ra[2],ra[3],ra[4],data29,rd29);
Mux32 m30(_ra[0],ra[1],ra[2],ra[3],ra[4],data30,rd30);
Mux32 m31(ra[0],ra[1],ra[2],ra[3],ra[4],data31,rd31);
or o0(rd[0],rd0[0],rd1[0],rd2[0],rd3[0],rd4[0],rd5[0],
	rd6[0],rd7[0],rd8[0],rd9[0],rd10,rd11[0],rd12[0],
	rd13[0],rd14[0],rd15[0],rd16[0],rd17[0],rd18[0],
	rd19[0],rd20[0],rd21,rd22[0],rd23[0],rd24[0],rd25[0],
	rd26[0],rd27[0],rd28[0],rd29[0],rd30[0],rd31[0]);
or o1(rd[1],rd0[1],rd1[1],rd2[1],rd3[1],rd4[1],rd5[1],
	rd6[1],rd7[1],rd8[1],rd9[1],rd10,rd11[1],rd12[1],
	rd13[1],rd14[1],rd15[1],rd16[1],rd17[1],rd18[1],
	rd19[1],rd20[1],rd21,rd22[1],rd23[1],rd24[1],rd25[1],
	rd26[1],rd27[1],rd28[1],rd29[1],rd30[1],rd31[1]);
or o2(rd[2],rd0[2],rd1[2],rd2[2],rd3[2],rd4[2],rd5[2],
	rd6[2],rd7[2],rd8[2],rd9[2],rd10,rd11[2],rd12[2],
	rd13[2],rd14[2],rd15[2],rd16[2],rd17[2],rd18[2],
	rd19[2],rd20[2],rd21,rd22[2],rd23[2],rd24[2],rd25[2],
	rd26[2],rd27[2],rd28[2],rd29[2],rd30[2],rd31[2]);
or o3(rd[3],rd0[3],rd1[3],rd2[3],rd3[3],rd4[3],rd5[3],
	rd6[3],rd7[3],rd8[3],rd9[3],rd10,rd11[3],rd12[3],
	rd13[3],rd14[3],rd15[3],rd16[3],rd17[3],rd18[3],
	rd19[3],rd20[3],rd21,rd22[3],rd23[3],rd24[3],rd25[3],
	rd26[3],rd27[3],rd28[3],rd29[3],rd30[3],rd31[3]);
or o4(rd[4],rd0[4],rd1[4],rd2[4],rd3[4],rd4[4],rd5[4],
	rd6[4],rd7[4],rd8[4],rd9[4],rd10,rd11[4],rd12[4],
	rd13[4],rd14[4],rd15[4],rd16[4],rd17[4],rd18[4],
	rd19[4],rd20[4],rd21,rd22[4],rd23[4],rd24[4],rd25[4],
	rd26[4],rd27[4],rd28[4],rd29[4],rd30[4],rd31[4]);
or o5(rd[5],rd0[5],rd1[5],rd2[5],rd3[5],rd4[5],rd5[5],
	rd6[5],rd7[5],rd8[5],rd9[5],rd10,rd11[5],rd12[5],
	rd13[5],rd14[5],rd15[5],rd16[5],rd17[5],rd18[5],
	rd19[5],rd20[5],rd21,rd22[5],rd23[5],rd24[5],rd25[5],
	rd26[5],rd27[5],rd28[5],rd29[5],rd30[5],rd31[5]);
or o6(rd[6],rd0[6],rd1[6],rd2[6],rd3[6],rd4[6],rd5[6],
	rd6[6],rd7[6],rd8[6],rd9[6],rd10,rd11[6],rd12[6],
	rd13[6],rd14[6],rd15[6],rd16[6],rd17[6],rd18[6],
	rd19[6],rd20[6],rd21,rd22[6],rd23[6],rd24[6],rd25[6],
	rd26[6],rd27[6],rd28[6],rd29[6],rd30[6],rd31[6]);
or o7(rd[7],rd0[7],rd1[7],rd2[7],rd3[7],rd4[7],rd5[7],
	rd6[7],rd7[7],rd8[7],rd9[7],rd10,rd11[7],rd12[7],
	rd13[7],rd14[7],rd15[7],rd16[7],rd17[7],rd18[7],
	rd19[7],rd20[7],rd21,rd22[7],rd23[7],rd24[7],rd25[7],
	rd26[7],rd27[7],rd28[7],rd29[7],rd30[7],rd31[7]);
or o8(rd[8],rd0[8],rd1[8],rd2[8],rd3[8],rd4[8],rd5[8],
	rd6[8],rd7[8],rd8[8],rd9[8],rd10,rd11[8],rd12[8],
	rd13[8],rd14[8],rd15[8],rd16[8],rd17[8],rd18[8],
	rd19[8],rd20[8],rd21,rd22[8],rd23[8],rd24[8],rd25[8],
	rd26[8],rd27[8],rd28[8],rd29[8],rd30[8],rd31[8]);
or o9(rd[9],rd0[9],rd1[9],rd2[9],rd3[9],rd4[9],rd5[9],
	rd6[9],rd7[9],rd8[9],rd9[9],rd10,rd11[9],rd12[9],
	rd13[9],rd14[9],rd15[9],rd16[9],rd17[9],rd18[9],
	rd19[9],rd20[9],rd21,rd22[9],rd23[9],rd24[9],rd25[9],
	rd26[9],rd27[9],rd28[9],rd29[9],rd30[9],rd31[9]);
or o10(rd[10],rd0[10],rd1[10],rd2[10],rd3[10],rd4[10],rd5[10],
	rd6[10],rd7[10],rd8[10],rd9[10],rd10,rd11[10],rd12[10],
	rd13[10],rd14[10],rd15[10],rd16[10],rd17[10],rd18[10],
	rd19[10],rd20[10],rd21,rd22[10],rd23[10],rd24[10],rd25[10],
	rd26[10],rd27[10],rd28[10],rd29[10],rd30[10],rd31[10]);
or o11(rd[11],rd0[11],rd1[11],rd2[11],rd3[11],rd4[11],rd5[11],
	rd6[11],rd7[11],rd8[11],rd9[11],rd10,rd11[11],rd12[11],
	rd13[11],rd14[11],rd15[11],rd16[11],rd17[11],rd18[11],
	rd19[11],rd20[11],rd21,rd22[11],rd23[11],rd24[11],rd25[11],
	rd26[11],rd27[11],rd28[11],rd29[11],rd30[11],rd31[11]);
or o12(rd[12],rd0[12],rd1[12],rd2[12],rd3[12],rd4[12],rd5[12],
	rd6[12],rd7[12],rd8[12],rd9[12],rd10,rd11[12],rd12[12],
	rd13[12],rd14[12],rd15[12],rd16[12],rd17[12],rd18[12],
	rd19[12],rd20[12],rd21,rd22[12],rd23[12],rd24[12],rd25[12],
	rd26[12],rd27[12],rd28[12],rd29[12],rd30[12],rd31[12]);
or o13(rd[13],rd0[13],rd1[13],rd2[13],rd3[13],rd4[13],rd5[13],
	rd6[13],rd7[13],rd8[13],rd9[13],rd10,rd11[13],rd12[13],
	rd13[13],rd14[13],rd15[13],rd16[13],rd17[13],rd18[13],
	rd19[13],rd20[13],rd21,rd22[13],rd23[13],rd24[13],rd25[13],
	rd26[13],rd27[13],rd28[13],rd29[13],rd30[13],rd31[13]);
or o14(rd[14],rd0[14],rd1[14],rd2[14],rd3[14],rd4[14],rd5[14],
	rd6[14],rd7[14],rd8[14],rd9[14],rd10,rd11[14],rd12[14],
	rd13[14],rd14[14],rd15[14],rd16[14],rd17[14],rd18[14],
	rd19[14],rd20[14],rd21,rd22[14],rd23[14],rd24[14],rd25[14],
	rd26[14],rd27[14],rd28[14],rd29[14],rd30[14],rd31[14]);
or o15(rd[15],rd0[15],rd1[15],rd2[15],rd3[15],rd4[15],rd5[15],
	rd6[15],rd7[15],rd8[15],rd9[15],rd10,rd11[15],rd12[15],
	rd13[15],rd14[15],rd15[15],rd16[15],rd17[15],rd18[15],
	rd19[15],rd20[15],rd21,rd22[15],rd23[15],rd24[15],rd25[15],
	rd26[15],rd27[15],rd28[15],rd29[15],rd30[15],rd31[15]);
or o16(rd[16],rd0[16],rd1[16],rd2[16],rd3[16],rd4[16],rd5[16],
	rd6[16],rd7[16],rd8[16],rd9[16],rd10,rd11[16],rd12[16],
	rd13[16],rd14[16],rd15[16],rd16[16],rd17[16],rd18[16],
	rd19[16],rd20[16],rd21,rd22[16],rd23[16],rd24[16],rd25[16],
	rd26[16],rd27[16],rd28[16],rd29[16],rd30[16],rd31[16]);
or o17(rd[17],rd0[17],rd1[17],rd2[17],rd3[17],rd4[17],rd5[17],
	rd6[17],rd7[17],rd8[17],rd9[17],rd10,rd11[17],rd12[17],
	rd13[17],rd14[17],rd15[17],rd16[17],rd17[17],rd18[17],
	rd19[17],rd20[17],rd21,rd22[17],rd23[17],rd24[17],rd25[17],
	rd26[17],rd27[17],rd28[17],rd29[17],rd30[17],rd31[17]);
or o18(rd[18],rd0[18],rd1[18],rd2[18],rd3[18],rd4[18],rd5[18],
	rd6[18],rd7[18],rd8[18],rd9[18],rd10,rd11[18],rd12[18],
	rd13[18],rd14[18],rd15[18],rd16[18],rd17[18],rd18[18],
	rd19[18],rd20[18],rd21,rd22[18],rd23[18],rd24[18],rd25[18],
	rd26[18],rd27[18],rd28[18],rd29[18],rd30[18],rd31[18]);
or o19(rd[19],rd0[19],rd1[19],rd2[19],rd3[19],rd4[19],rd5[19],
	rd6[19],rd7[19],rd8[19],rd9[19],rd10,rd11[19],rd12[19],
	rd13[19],rd14[19],rd15[19],rd16[19],rd17[19],rd18[19],
	rd19[19],rd20[19],rd21,rd22[19],rd23[19],rd24[19],rd25[19],
	rd26[19],rd27[19],rd28[19],rd29[19],rd30[19],rd31[19]);
or o20(rd[20],rd0[20],rd1[20],rd2[20],rd3[20],rd4[20],rd5[20],
	rd6[20],rd7[20],rd8[20],rd9[20],rd10,rd11[20],rd12[20],
	rd13[20],rd14[20],rd15[20],rd16[20],rd17[20],rd18[20],
	rd19[20],rd20[20],rd21,rd22[20],rd23[20],rd24[20],rd25[20],
	rd26[20],rd27[20],rd28[20],rd29[20],rd30[20],rd31[20]);
or o21(rd[21],rd0[21],rd1[21],rd2[21],rd3[21],rd4[21],rd5[21],
	rd6[21],rd7[21],rd8[21],rd9[21],rd10,rd11[21],rd12[21],
	rd13[21],rd14[21],rd15[21],rd16[21],rd17[21],rd18[21],
	rd19[21],rd20[21],rd21,rd22[21],rd23[21],rd24[21],rd25[21],
	rd26[21],rd27[21],rd28[21],rd29[21],rd30[21],rd31[21]);
or o22(rd[22],rd0[22],rd1[22],rd2[22],rd3[22],rd4[22],rd5[22],
	rd6[22],rd7[22],rd8[22],rd9[22],rd10,rd11[22],rd12[22],
	rd13[22],rd14[22],rd15[22],rd16[22],rd17[22],rd18[22],
	rd19[22],rd20[22],rd21,rd22[22],rd23[22],rd24[22],rd25[22],
	rd26[22],rd27[22],rd28[22],rd29[22],rd30[22],rd31[22]);
or o23(rd[23],rd0[23],rd1[23],rd2[23],rd3[23],rd4[23],rd5[23],
	rd6[23],rd7[23],rd8[23],rd9[23],rd10,rd11[23],rd12[23],
	rd13[23],rd14[23],rd15[23],rd16[23],rd17[23],rd18[23],
	rd19[23],rd20[23],rd21,rd22[23],rd23[23],rd24[23],rd25[23],
	rd26[23],rd27[23],rd28[23],rd29[23],rd30[23],rd31[23]);
or o24(rd[24],rd0[24],rd1[24],rd2[24],rd3[24],rd4[24],rd5[24],
	rd6[24],rd7[24],rd8[24],rd9[24],rd10,rd11[24],rd12[24],
	rd13[24],rd14[24],rd15[24],rd16[24],rd17[24],rd18[24],
	rd19[24],rd20[24],rd21,rd22[24],rd23[24],rd24[24],rd25[24],
	rd26[24],rd27[24],rd28[24],rd29[24],rd30[24],rd31[24]);
or o25(rd[25],rd0[25],rd1[25],rd2[25],rd3[25],rd4[25],rd5[25],
	rd6[25],rd7[25],rd8[25],rd9[25],rd10,rd11[25],rd12[25],
	rd13[25],rd14[25],rd15[25],rd16[25],rd17[25],rd18[25],
	rd19[25],rd20[25],rd21,rd22[25],rd23[25],rd24[25],rd25[25],
	rd26[25],rd27[25],rd28[25],rd29[25],rd30[25],rd31[25]);
or o26(rd[26],rd0[26],rd1[26],rd2[26],rd3[26],rd4[26],rd5[26],
	rd6[26],rd7[26],rd8[26],rd9[26],rd10,rd11[26],rd12[26],
	rd13[26],rd14[26],rd15[26],rd16[26],rd17[26],rd18[26],
	rd19[26],rd20[26],rd21,rd22[26],rd23[26],rd24[26],rd25[26],
	rd26[26],rd27[26],rd28[26],rd29[26],rd30[26],rd31[26]);
or o27(rd[27],rd0[27],rd1[27],rd2[27],rd3[27],rd4[27],rd5[27],
	rd6[27],rd7[27],rd8[27],rd9[27],rd10,rd11[27],rd12[27],
	rd13[27],rd14[27],rd15[27],rd16[27],rd17[27],rd18[27],
	rd19[27],rd20[27],rd21,rd22[27],rd23[27],rd24[27],rd25[27],
	rd26[27],rd27[27],rd28[27],rd29[27],rd30[27],rd31[27]);
or o28(rd[28],rd0[28],rd1[28],rd2[28],rd3[28],rd4[28],rd5[28],
	rd6[28],rd7[28],rd8[28],rd9[28],rd10,rd11[28],rd12[28],
	rd13[28],rd14[28],rd15[28],rd16[28],rd17[28],rd18[28],
	rd19[28],rd20[28],rd21,rd22[28],rd23[28],rd24[28],rd25[28],
	rd26[28],rd27[28],rd28[28],rd29[28],rd30[28],rd31[28]);
or o29(rd[29],rd0[29],rd1[29],rd2[29],rd3[29],rd4[29],rd5[29],
	rd6[29],rd7[29],rd8[29],rd9[29],rd10,rd11[29],rd12[29],
	rd13[29],rd14[29],rd15[29],rd16[29],rd17[29],rd18[29],
	rd19[29],rd20[29],rd21,rd22[29],rd23[29],rd24[29],rd25[29],
	rd26[29],rd27[29],rd28[29],rd29[29],rd30[29],rd31[29]);
or o30(rd[30],rd0[30],rd1[30],rd2[30],rd3[30],rd4[30],rd5[30],
	rd6[30],rd7[30],rd8[30],rd9[30],rd10,rd11[30],rd12[30],
	rd13[30],rd14[30],rd15[30],rd16[30],rd17[30],rd18[30],
	rd19[30],rd20[30],rd21,rd22[30],rd23[30],rd24[30],rd25[30],
	rd26[30],rd27[30],rd28[30],rd29[30],rd30[30],rd31[30]);
or o31(rd[31],rd0[31],rd1[31],rd2[31],rd3[31],rd4[31],rd5[31],
	rd6[31],rd7[31],rd8[31],rd9[31],rd10,rd11[31],rd12[31],
	rd13[31],rd14[31],rd15[31],rd16[31],rd17[31],rd18[31],
	rd19[31],rd20[31],rd21,rd22[31],rd23[31],rd24[31],rd25[31],
	rd26[31],rd27[31],rd28[31],rd29[31],rd30[31],rd31[31]);
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
