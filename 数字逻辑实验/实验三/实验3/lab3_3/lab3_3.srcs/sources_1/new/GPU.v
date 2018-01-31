`timescale 1ns / 1ps

module GPU(
    input clk3hz,
    input clk12hz,
    input main_switch,
    input start_stop_switch,
    input high_low_switch,                               //control high four number or low four number input
    input [3:0]control,                                       //up,right,down,left
    output enable,                                              //scroll or input
    output [15:0]dataBus1,                                //for output 
    output [15:0]dataBus2,                                //for input
    output [15:0]dataBusInfo
);

    reg en;
    reg[31:0]constant_msg;
    reg [3:0]msgIn = 0;
    reg [31:0]msg = 0;                                            //left for output
    reg [15:0]msgArrayInfo = 0;                            //left for information
    reg [15:0]msgArray = 0;                                  //right for input
    reg [1:0]position = 2'b11;                               //HSB to LSB
    
    assign enable = en;
    assign dataBus1 = msg[31:16];
    assign dataBusInfo = msgArrayInfo;
    assign dataBus2 = msgArray;
    
    always @ (posedge clk12hz)           //change the target input number
        if (!start_stop_switch && main_switch) begin
            if (control[0] && msgIn !=9) msgIn = msgIn+1;
            else if (control[0] && msgIn == 9) msgIn = 0;
            else if (control[2] && msgIn != 0) msgIn = msgIn-1;
            else if (control[2] && msgIn == 0) msgIn = 9;
            else if (control[1] ) begin msgIn = 0; position = position-1; end
            else if (control[3] ) begin msgIn = 0; position = position+1; end
        end
    
    always @ (posedge clk3hz)  begin
        if (!main_switch ) begin                               //main_switch off
            en = 0;
            msgArrayInfo = 16'haaaa;
            msgArray = 16'hffff;
        end
        if(main_switch) begin       
            if (!start_stop_switch) begin                    //main_switch on,  stop
                en = 0;
                if (high_low_switch) begin                 //four high-number
                    msgArray = constant_msg[31:16];
                    msgArrayInfo = 16'haaaa;
                    msg = constant_msg;
                    case (position)                             //save the input number in every bit
                            3: begin constant_msg[31:28] = msgIn; msgArray[15:12] = msgIn;  end
                            2: begin constant_msg[27:24] = msgIn; msgArray[11:8] = msgIn; end
                            1: begin constant_msg[23:20] = msgIn; msgArray[7:4] = msgIn; end
                            0: begin constant_msg[19:16] = msgIn; msgArray[3:0] = msgIn; end
                   endcase
                end
                else if (!high_low_switch) begin                                             //four low-number
                    msgArray = constant_msg[15:0];
                    msgArrayInfo = 16'hffff;
                    msg = constant_msg;
                    case (position) 
                            3: begin constant_msg[15:12] = msgIn; msgArray[15:12] = msgIn; end
                            2: begin constant_msg[11:8] = msgIn; msgArray[11:8] = msgIn; end
                            1: begin constant_msg[7:4] = msgIn; msgArray[7:4] = msgIn; end
                            0: begin constant_msg[3:0] = msgIn; msgArray[3:0] = msgIn; end
                    endcase
                end
            end
            else if (start_stop_switch) begin                                                  //start    
                en = 1;
                msg[3:0] <= msg[31:28];
                msg[31:4] <= msg[27:0];
            end
        end
  end
endmodule


