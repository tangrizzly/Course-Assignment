module Compare(
	input				CLR,
	input		[2:0]	Compare_addr,
	input		[2:0]	Compare_in,
	input				Area_RW,
	output				M
	);

	wire		[3:0]	Area_out;
	reg			[2:0]	Area_addr;
	wire				V;

	assign V = Area_out[0];
	assign M =  ~(Area_out[3:1] == Compare_addr[2:0]);

	AreaMem		U3 (Area_out,Compare_in,Compare_addr,CLR,Area_RW);			//read1,write0

endmodule