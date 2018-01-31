`timescale 1ns / 1ps

module segMsg(
    input clk190hz,                
    input [15:0]dataBus1,      //out
    input [15:0]dataBus2,      //in
    input [15:0]dataBusInfo,
    input en,                        //1 represent start
    output reg[3:0]pos,      //left for out
    output reg[3:0]sop,      //right for in
    output reg[7:0]seg1,    //left for seg
    output reg[7:0]seg2     //right for seg
    );
    
reg [1:0]posC1;                //refresh digital tube
reg [1:0]posC2;
reg [3:0]dataP1;
reg [3:0]dataP2;

always @(posedge clk190hz) begin
    if (en) begin
        case (posC1)
            0:begin
                pos <= 4'b0001;     
                dataP1 <= dataBus1[3:0];
            end
            1:begin
                pos <= 4'b0010;
                dataP1 <= dataBus1[7:4];
            end
            2:begin
                pos <=4'b0100;
                dataP1 <=dataBus1[11:8];
            end
            3:begin
                 pos <=4'b1000;
                 dataP1 <=dataBus1[15:12];
            end            
        endcase
        posC1 = posC1 +1;
    end
    else if (!en) begin
        case (posC1)
                0:begin
                    pos <= 4'b0001;     
                    dataP1 <= dataBusInfo[3:0];
                end
                1:begin
                    pos <= 4'b0010;
                    dataP1 <= dataBusInfo[7:4];
                end
                2:begin
                    pos <=4'b0100;
                    dataP1 <=dataBusInfo[11:8];
                end
                3:begin
                     pos <=4'b1000;
                     dataP1 <=dataBusInfo[15:12];
                end
        endcase
        posC1 = posC1 + 1;
    end
   end
    
   always @(posedge clk190hz) begin
       if (en) begin
           case (posC2)
               0:begin 
                     sop <=4'b0001;
                     dataP2 <=4'ha;
               end
               1:begin 
                     sop <=4'b0010;
                     dataP2 <=4'ha;
               end
               2:begin 
                     sop <=4'b0100;
                     dataP2 <=4'ha;
               end
               3:begin
                     sop <= 4'b1000;
                    dataP2 <= 4'ha;
               end
           endcase
           posC2 = posC2 +1;
       end
       else if (!en) begin
           case (posC2)
                  0:begin
                        sop <= 4'b0001;     
                        dataP2 <= dataBus2[3:0];
                   end
                   1:begin
                       sop <= 4'b0010;
                       dataP2 <= dataBus2[7:4];
                   end
                   2:begin
                       sop <=4'b0100;
                       dataP2 <=dataBus2[11:8];
                   end
                   3:begin
                       sop <=4'b1000;
                       dataP2 <=dataBus2[15:12];
                   end
           endcase
           posC2 = posC2 + 1;
       end
      end

always @ (dataP1) 
    case(dataP1)
        0: seg1 = 8'b0011_1111;
        1: seg1 = 8'b0000_0110; 
        2: seg1 = 8'b0101_1011; 
        3: seg1 = 8'b0100_1111; 
        4: seg1 = 8'b0110_0110; 
        5: seg1 = 8'b0110_1101; 
        6: seg1 = 8'b0111_1101; 
        7: seg1 = 8'b0000_0111; 
        8: seg1 = 8'b0111_1111; 
        9: seg1 = 8'b0110_1111; 
        10: seg1 = 8'b0100_0000;
        11: seg1 = 8'b0000_0000; 
        default : seg1 = 8'b0000_1000; 
    endcase
    
always @ (dataP2)
        case(dataP2)
            0: seg2 = 8'b0011_1111; 
            1: seg2 = 8'b0000_0110; 
            2: seg2 = 8'b0101_1011; 
            3: seg2 = 8'b0100_1111; 
            4: seg2 = 8'b0110_0110; 
            5: seg2 = 8'b0110_1101; 
            6: seg2 = 8'b0111_1101; 
            7: seg2 = 8'b0000_0111; 
            8: seg2 = 8'b0111_1111; 
            9: seg2 = 8'b0110_1111; 
            10: seg2 = 8'b0100_0000; 
            11: seg2 = 8'b0000_0000; 
            default : seg2 = 8'b0000_1000; 
        endcase
        
endmodule
