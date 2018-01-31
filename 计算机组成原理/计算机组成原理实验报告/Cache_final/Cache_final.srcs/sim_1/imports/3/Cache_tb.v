 module Cache_tb();
	reg				T2;
	reg				CLR;
	reg 	[7:0]	A;
	reg				RD;
	wire	[7:0]	D1;
	reg		[7:0]	MD;
	reg     [7:0]   D;
	initial
	begin
		T2=0;
		forever #1 T2=~T2;
	end
	initial
	begin
		CLR=1;
		A = 8'b1000_0001;
		RD = 1;
		MD = 8'b1111_1111;
		#5 CLR=0;
	end
	Cache   U3(T2, CLR, MD, A ,RD, D1);
endmodule