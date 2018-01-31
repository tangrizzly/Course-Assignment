`timescale 1ns / 1ps
module ctrl(
	input [4:2]downn,
	input [3:1]upn,
	input [4:1]bn,
	input clr,clk,//清零端低电平有效，恢复至一层
	output reg[4:2]downnfb,
	output reg[3:1]upnfb,
	output reg[4:1]bnfb,
	output reg [2:0]floor,
	output reg [1:0]updown,
	output reg open,
	output reg [2:0]y//状态
	);
reg[2:0]temp;
reg [3:0]count;
always @(posedge clk or negedge clr) begin
	if (!clr) begin
		open=0;
		y=1;temp=1;
		upnfb=0;bnfb=0;downnfb=0;
		count=0;
	end
	else begin
		case(y)
			1://一层
			begin
				temp=1;
				if(upn[1]||bn[1])y=5;
				else if(upn[3:2]||bn[4:2]||downn[4:2])y=2;
				else y=1;
			end
			2://二层上升状态
			begin
				temp=2;
				if(upn[2]||bn[2])y=5;
				else if(upn[3]||bn[4:3]||downn[4:3])y=3;
				else if(upn[1]||bn[1]||downn[2])y=6;
				else y=2;
			end
			3://三层上升状态
			begin
				temp=3;
				if(upn[3]||bn[3])y=5;
				else if(bn[4]||downn[4])y=4;
				else if(upn[2:1]||downn[3:2]||bn[2:1])y=7;
				else y=3;
			end
			4://四层
			begin
				temp=4;
				if(downn[4]||bn[4])y=0;
				else if(upn[3:1]||downn[3:2]||bn[3:1])y=7;
				else y=4;
			end			
			7://三层下降状态
			begin
				temp=7;
				if(downn[3]||bn[3])y=0;
				else if(bn[2:1]||upn[2:1]||downn[2])y=6;
				else if(bn[4]||upn[3]||downn[4])y=3;
				else y=7;
			end
			6://二层下降状态
			begin
				temp=6;
				if(downn[2]||bn[2])y=0;
				else if(upn[1]||bn[1])y=1;
				else if(upn[3:2]||downn[4:3]||bn[4:3])y=2;
				else y=6;
			end
			5://上升过程中的开门状态
			begin
				if(count!=10) begin
				open=1;
				upnfb[temp%4]=1;//反馈高电平，使按键清零
				if(temp%4==0)bnfb[4]=1;
				else bnfb[temp%4]=1;//反馈高电平，使按键清零
				count=count+1;
				end
				else if(count==10)begin
					open=0;
					count=0;
					upnfb[temp%4]=0;
				    if(temp%4==0)bnfb[4]=0;
                    else bnfb[temp%4]=0;
					y=temp;
				end
			end
			0://下降过程中的开门状态
			begin
				if(count!=10) begin
				open=1;
				if(temp%4==0)
					begin downnfb[4]=1;bnfb[4]=1;end
				else begin downnfb[temp%4]=1;bnfb[temp%4]=1;end//反馈高电平，使按键清零
				count=count+1;
				end
				else if(count==10)begin
					open=0;
					count=0;
					if(temp%4==0)
                        begin downnfb[4]=0;bnfb[4]=0;end
                    else begin downnfb[temp%4]=0;bnfb[temp%4]=0;end
					y=temp;
				end
			end
		endcase
	end
end

always @(posedge clk or posedge clr) begin
	if(!clr)begin
		floor=0; updown=0;
	end
	else begin
		if(y==1)begin
			floor=1;
			if(upn[3:2]||bn[4:2]||downn[4:2]) updown=2'b10;
			else updown=2'b00;
		end
		if(y==2)begin
			floor=2;
			if(upn[3:2]||bn[4:3]||downn[4:3]) updown=2'b10;
			else updown=2'b00;
		end
		if(y==3)begin
			floor=3;
			if(bn[4]||downn[4]) updown=2'b10;
			else updown=2'b00;
		end
		if(y==4)begin
			floor=4;
			if(upn[3:1]||downn[3:2]||bn[3:1]) updown=2'b01;
			else updown=2'b00;
		end
		if(y==7)begin
			floor=3;
			if(bn[2:1]||upn[2:1]||downn[2]) updown=2'b01;
			else updown=2'b00;
		end
		if(y==6)begin
			floor=2;
			if(upn[1]||bn[1]) updown=2'b01;
			else updown=2'b00;
		end
		if(y==5)begin
			updown=2'b00;
		end
	end
end
endmodule