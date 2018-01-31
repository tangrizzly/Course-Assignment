`timescale 1ns / 1ps

module mult(
    input [7:0]a,
    input [7:0]b,
    output reg [15:0]p
);

reg [15:0]pv;
reg [15:0]ap;
integer i;

always@(*) begin
    pv = 16'h0000;
    ap = {8'h00,a};
    for (i=0;i<8;i=i+1) begin
        if (b[i] == 1) begin
            pv = ap+pv;
        end
        ap = ap<<1;
    end
    p = pv;
end        
endmodule