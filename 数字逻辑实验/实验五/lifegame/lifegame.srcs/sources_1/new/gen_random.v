module RanGen(
    input   gen,    
    input   clk,     
    output  num
);

reg [7:0]rand_num;
reg [7:0]ran_num = 8'b10001101; 

assign num = rand_num[7];

always@(posedge clk or negedge gen)
begin
    if(gen)
        num    <=0;
    else
        begin
            rand_num[0] <= rand_num[7];
            rand_num[1] <= rand_num[0];
            rand_num[2] <= rand_num[1];
            rand_num[3] <= rand_num[2];
            rand_num[4] <= rand_num[3]^rand_num[7];
            rand_num[5] <= rand_num[4]^rand_num[7];
            rand_num[6] <= rand_num[5]^rand_num[7];
            rand_num[7] <= rand_num[6];
        end
            
end
endmodule
