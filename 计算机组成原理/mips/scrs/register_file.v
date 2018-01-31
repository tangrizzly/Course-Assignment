`timescale 1ns / 1ps
 module register_file
 (
      input                     clk,
      input                     rst,
      input                     reg_write_en,
      input          [2:0]      reg_write_dest,
      input          [15:0]     reg_write_data,
      input          [2:0]      reg_read_addr_1,
      output         [15:0]     reg_read_data_1,
      input          [2:0]      reg_read_addr_2,
      output         [15:0]     reg_read_data_2,
      output reg        [15:0]     reg1,reg2,reg3
 );
      reg     [15:0]     reg_array [7:0];
                  always @ (posedge clk or posedge rst) begin
           if(rst) begin
                reg_array[0] <= 15'b0;
                reg_array[1] <= 15'b0;
                reg_array[2] <= 15'b0;
                reg_array[3] <= 15'b0;
                reg_array[4] <= 15'b0;
                reg_array[5] <= 15'b0;
                reg_array[6] <= 15'b0;
                reg_array[7] <= 15'b0;
           end
           else begin
                if(reg_write_en) begin
                     reg_array[reg_write_dest] <= reg_write_data;
                end
           end
           reg1 <= reg_array[1];
           reg2 <= reg_array[2];
           reg3 <= reg_array[3];
      end
      assign reg_read_data_1 = ( reg_read_addr_1 == 0)? 15'b0 : reg_array[reg_read_addr_1];
      assign reg_read_data_2 = ( reg_read_addr_2 == 0)? 15'b0 : reg_array[reg_read_addr_2];
 endmodule