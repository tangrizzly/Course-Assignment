`timescale 1ns / 1ps
module seg(
    input clk,
    input [2:0]floor,//1-4层
    input [1:0]updown,//0停止2上升1下降
    input open,//1开0闭
    input [2:0]y,//状态1-6个状态
    output reg[3:0]pos,
    output reg[7:0]seg
    );
    reg[1:0] posC;
    reg[3:0] dataP;
    always@(posedge clk)
    begin 
        case(posC)
        //楼层显示在第一个数码管上
            0:begin
                pos<=4'b0001;
                dataP<={1'b0,floor};
              end
            //电梯状态显示在第二个数码管上
            1:begin
                pos<=4'b0010;
                dataP<={2'b00,updown};
              end
            //电梯门开合显示在第三个数码管上
            2:begin
                pos<=4'b0100;
                dataP<={3'b000,open};
              end
            //y状态显示在第四个数码管上
            3:begin
                pos<=4'b1000;
                dataP<={1'b0,y};
              end
        endcase
        posC=posC+1;
    end
    //解码数据来控制数码管的每一段（这里取了0-9十个数字外加三个特殊显示）
    always@(dataP)
        case(dataP)
            0:seg=8'b0011_1111;
            1:seg=8'b0000_0110;
            2:seg=8'b0101_1011;
            3:seg=8'b0100_1111;
            4:seg=8'b0110_0110;
            5:seg=8'b0110_1101;
            6:seg=8'b0111_1101;
            7:seg=8'b0000_0111;
            8:seg=8'b0111_1111;
            9:seg=8'b0110_1111;
            10:seg=8'b0100_0000;
            11:seg=8'b0000_0000;
            default:seg=8'b0000_1000;
        endcase
endmodule