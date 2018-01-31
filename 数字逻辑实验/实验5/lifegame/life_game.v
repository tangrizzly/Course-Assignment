`timescale 1ns / 1ps

module life_game(
	input clock,
	input enable,								//是否活动
	input circlize,
	input pointer_ready,						//按下键即为有效
	input [8:0] pointer_delta_x,				//目标各自deltax值
	input [8:0] pointer_delta_y,
	input pointer_select,						
	input [9:0] x_position,						//显示区内坐标 640×480
	input [8:0] y_position,
	input inside_video,							//显示区内
	output reg [11:0] color						//8位rgb
	);

	//以下是UI端口
	parameter BLOCK_SIZE = 20;					//格子大小
	parameter BLOCK_COUNT_X = 640 / BLOCK_SIZE;	//行格子数
	parameter BLOCK_COUNT_Y = 480 / BLOCK_SIZE;	//列格子数

	parameter COLOR_POINTER = 12'b0000_1100_1000;	//颜色
	parameter COLOR_EMPTY = 12'b1111_1111_1111;
	parameter COLOR_BLACK = 12'b0000_0000_0000;

	reg [9:0] pointer_x = 320;					//初始目标坐标
	reg [8:0] pointer_y = 240;
	wire [4:0] pointer_x_index;					//目标索引
	wire [4:0] pointer_y_index;
	wire pointer_select_on [0:BLOCK_COUNT_X - 1] [0:BLOCK_COUNT_Y - 1];
	reg map_0 [0:BLOCK_COUNT_X - 1] [0:BLOCK_COUNT_Y - 1];
	reg map_1 [0:BLOCK_COUNT_X - 1] [0:BLOCK_COUNT_Y - 1];
	reg map_index = 0;
	wire [3:0] neighbor_count_0 [0:BLOCK_COUNT_X - 1] [0:BLOCK_COUNT_Y - 1];	//周围细胞数量
	wire [3:0] neighbor_count_1 [0:BLOCK_COUNT_X - 1] [0:BLOCK_COUNT_Y - 1];
	wire [4:0] x_index;
	wire [4:0] y_index;
	wire block_current;
	wire [11:0] color_life;
	wire [11:0] color_empty;
	wire [11:0] color_block;
	wire [11:0] color_block_circlized;

	initial begin
		map_0[1][0] = 1;
		map_0[2][1] = 1;
		map_0[0][2] = 1;
		map_0[1][2] = 1;
		map_0[2][2] = 1;
	end

	// FIXME: Should use system clock here.
	always @(posedge clock) begin
		if (pointer_ready) begin						//若监测到按键
			if (pointer_delta_x[8]) begin				//左右移动
				pointer_x <= pointer_x - pointer_delta_x[7:0];
			end else begin
				pointer_x <= pointer_x + pointer_delta_x[7:0];
			end
			if (pointer_delta_y[8]) begin				//上下移动
				pointer_y <= pointer_y - pointer_delta_y[7:0];
			end else begin
				pointer_y <= pointer_y + pointer_delta_y[7:0];
			end
		end
	end

	assign pointer_x_index = pointer_x / BLOCK_SIZE;	//目标块索引
	assign pointer_y_index = pointer_y / BLOCK_SIZE;

	always @(posedge clock) begin						
		if (enable) begin								//刷新屏幕，开始运动
			map_index <= ~map_index;
		end
	end

genvar i, j;
generate
	for (i = 0; i < BLOCK_COUNT_X; i = i + 1) begin
		for (j = 0; j < BLOCK_COUNT_Y; j = j + 1) begin

	assign pointer_select_on[i][j] = i == pointer_x_index && j == pointer_y_index && pointer_select;		//选中目标块
	//计算细胞周围生存的细胞数的数量
	assign neighbor_count_0[i][j] = map_0[(i - 1 + BLOCK_COUNT_X) % BLOCK_COUNT_X][(j - 1 + BLOCK_COUNT_Y) % BLOCK_COUNT_Y] + map_0[i][(j - 1 + BLOCK_COUNT_Y) % BLOCK_COUNT_Y] + map_0[(i + 1) % BLOCK_COUNT_X][(j - 1 + BLOCK_COUNT_Y) % BLOCK_COUNT_Y]
			+ map_0[(i - 1 + BLOCK_COUNT_X) % BLOCK_COUNT_X][j] + map_0[(i + 1) % BLOCK_COUNT_X][j]
			+ map_0[(i - 1 + BLOCK_COUNT_X) % BLOCK_COUNT_X][(j + 1) % BLOCK_COUNT_Y] + map_0[i][(j + 1) % BLOCK_COUNT_Y] + map_0[(i + 1) % BLOCK_COUNT_X][(j + 1) % BLOCK_COUNT_Y];
	assign neighbor_count_1[i][j] = map_1[(i - 1 + BLOCK_COUNT_X) % BLOCK_COUNT_X][(j - 1 + BLOCK_COUNT_Y) % BLOCK_COUNT_Y] + map_1[i][(j - 1 + BLOCK_COUNT_Y) % BLOCK_COUNT_Y] + map_1[(i + 1) % BLOCK_COUNT_X][(j - 1 + BLOCK_COUNT_Y) % BLOCK_COUNT_Y]
			+ map_1[(i - 1 + BLOCK_COUNT_X) % BLOCK_COUNT_X][j] + map_1[(i + 1) % BLOCK_COUNT_X][j]
			+ map_1[(i - 1 + BLOCK_COUNT_X) % BLOCK_COUNT_X][(j + 1) % BLOCK_COUNT_Y] + map_1[i][(j + 1) % BLOCK_COUNT_Y] + map_1[(i + 1) % BLOCK_COUNT_X][(j + 1) % BLOCK_COUNT_Y];
	
	always @(posedge clock) begin
		if (map_index == 0) begin			//两个地图切换以实现刷新
			map_0[i][j] <= pointer_select_on[i][j] ^ map_0[i][j];	//生成或消除目标快内细胞
			if (map_0[i][j]) begin
				map_1[i][j] <= neighbor_count_0[i][j] == 2 | neighbor_count_0[i][j] == 3;	//若原细胞为存活，周围生存细胞数为2或3，则细胞仍为生存状态
			end else begin
				map_1[i][j] <= neighbor_count_0[i][j] == 3;		//若原细胞为死亡，周围细胞数为3，则细胞变为生存状态
			end
		end else begin
			map_1[i][j] <= pointer_select_on[i][j] ^ map_1[i][j];	//同上
			if (map_1[i][j]) begin
				map_0[i][j] <= neighbor_count_1[i][j] == 2 | neighbor_count_1[i][j] == 3;
			end else begin
				map_0[i][j] <= neighbor_count_1[i][j] == 3;
			end
		end
//		map_0[i][j] <= 1;
//		map_1[i][j] <= 1;
	end

		end
	end
endgenerate

	assign x_index = x_position / BLOCK_SIZE;		//x轴格子索引
	assign y_index = y_position / BLOCK_SIZE;
	assign block_current = map_index == 0 ? map_0[x_index][y_index] : map_1[x_index][y_index];	//当前格子状态
	//颜色生成模块
	color_generator color_generator(x_index, y_index, color_life);
	assign color_empty = x_index == pointer_x_index && y_index == pointer_y_index ? COLOR_POINTER : COLOR_EMPTY;	//不填充颜色
	assign color_block = block_current ? color_life : color_empty;	//填充颜色
	//超出屏幕处理
	color_circlizer #(BLOCK_SIZE) color_circlizer (x_position - x_index * BLOCK_SIZE, y_position - y_index * BLOCK_SIZE, color_block, color_empty, color_block_circlized);

	always @(*) begin//颜色处理
		if (inside_video) begin
			if (x_position <= BLOCK_SIZE * BLOCK_COUNT_X) begin
				color = circlize ? color_block : color_block_circlized;
			end else begin
				color = COLOR_BLACK;
			end
		end else begin
			color = 0;
		end
	end

endmodule


