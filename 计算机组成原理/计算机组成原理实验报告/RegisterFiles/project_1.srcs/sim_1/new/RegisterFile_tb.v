`timescale 1ns / 1ps
module RegisterFile_tb;
reg [4:0]ra1,ra2,wa;
reg [31:0]wd;
reg en_write;
wire [31:0]rd1,rd2;
RegisterFile rf(ra1,ra2,wa,wd,en_write,rd1,rd2);
initial begin
	en_write=0;
	wd=32'b11010101110011100101001000010011;
	wa=5'b10110;
	ra1=5'bz;
	ra2=5'bz;
	#1en_write=1;
	#4 wa=5'b01001;en_write=0;
	wd=32'b01011001101011010101000110110101;
	#5 en_write=1;
	ra1=5'b10110;
	ra2=5'b01001;
	#5 $finish;
end
endmodule