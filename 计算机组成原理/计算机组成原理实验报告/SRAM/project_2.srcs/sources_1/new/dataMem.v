module DataMemory(
	input clk, 
 	input [31:0]DataIn, 
	input WrEn, 
	input [31:0]Adr, 
	output [31:0]Out
	); 
reg [31:0]DM[5:0]; 
assign Out=WrEn?32'hzzzzzzzz:DM[Adr];
integer i; 
initial begin 
   for(i=0;i<32;i=i+1) 
     DM[i]<=0; 
end 

always @(posedge clk) begin
  	if(WrEn) 
  		DM[Adr]<=DataIn;
end
endmodule