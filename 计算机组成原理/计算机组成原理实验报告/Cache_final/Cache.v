module	Cache(
	// 控制信号
	input				T2,					// 时钟信号
	input				CLR,				// 系统清零信号
	// 与主存通信信号
	input		[7:0]	MD,					// 读数据
	// 与cpu通信信号
	input		[7:0]	A,					// cpu给出的主存地址
	input				RD,					// cpu访问主存读信号
	output reg	[7:0]	D					// Cache送cpu数据
	);

	parameter			X1 = 0;
	parameter			X2 = 1;

	reg					Y;					//状态机
	wire				M;					//Cache失效信号
	wire		[7:0]	Cache_out;
	reg			[7:0]	Cache_in;
	reg			[4:0]	Cache_addr;			//Cache地址，即CA
	wire				Cache_RW;			//Cache读写
	wire				Area_RW;			//Area读写
	reg			[1:0]	LA;					//块内地址
	wire		[2:0]	Compare_addr;
	reg			[2:0]	Compare_in;


	always@(posedge T2)
	begin
		if(!CLR)
		begin
			if(!M)						//从Cache送入cpu
			begin
				Cache_addr = A[4:0];
				D = Cache_out;
			end
			else if(RD)						// 从主存取数据放入
			begin
				Compare_in <= MD[7:5];
				for(LA = 0; LA < 4 ; LA = LA + 1)
				begin
					Cache_addr = {A[4:0],LA[1:0]};
					Cache_in = MD;
				end
			end

		end
	end


	always@(posedge T2)						//状态机
	begin
		if(CLR)
			Y	<=	X1;
		else
			case(Y)
				X1:	if(M)
						Y	<=	X2;
					else
						Y	<=	X1;
				X2:	if(!M)
						Y	<= 	X1;
					else
						Y	<=	X2;
				default:	Y	<=	X1;
			endcase
	end

	assign Compare_addr = A[4:2];			//输入AreaMem的地址一直是cpu请求内存的地址
	assign Cache_RW = ~(Y == X2);
	assign Area_RW = ~(Y == X2);			//从主存写入AreaMem
	assign RD =	Y == X2 ;

	Compare		U1 (CLR,Compare_addr,Compare_in,Area_RW,M);
	CacheMem	U2 (Cache_out,Cache_in,Cache_addr,CLR,Area_RW);

endmodule

