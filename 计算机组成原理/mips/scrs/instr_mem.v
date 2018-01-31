`timescale 1ns / 1ps
 module instr_mem(
  input           [15:0]     pc,
  output wire     [15:0]     instruction
 );
      wire [3 : 0] rom_addr = pc[5 : 2];
      reg [15:0] rom[15:0];
      initial
      begin     

                rom[0] = 16'b001_010_001_000_0111;//slti reg1 = 1;
                rom[1] = 16'b000_011_001_010_0000;//reg3 = reg1 + reg2
                rom[2] = 16'b000_011_001_010_0000;//reg2 = reg1 + reg3
                rom[3] = 16'b000_010_011_001_0000;//reg1 = reg2 + reg3
                rom[4] = 16'b000_001_010_011_0000;//reg3 = reg1 + reg2
                rom[5] = 16'b000_001_010_011_0001;//subu reg3 = reg1 - reg2
                rom[6] = 16'b000_011_001_010_0010;//and reg2 = reg1 & reg3
                rom[7] = 16'b000_111_000_000_1000;//Jr
                rom[8] = 16'b101_010_001_0000111;//sw
                rom[9] = 16'b000_010_011_0010000;//reg1 = reg2 + reg3
                rom[10] = 16'b100_010_001_0000111;//lw
                rom[11] = 16'b110_001_010_0000111;//beq
                rom[12] = 16'b111_010_001_0000111;//addi
                rom[13] = 16'b0000000000000000;
                rom[14] = 16'b0000000000000000;
                rom[15] = 16'b0000000000000000;
      end
      assign instruction = (pc[15:0] < 64 )? rom[rom_addr[3:0]]: 16'd0;
 endmodule