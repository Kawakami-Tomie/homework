//八进制计数器子模块（底层文件）
module CW_2301_9_1 (Q, clk, en);
	input clk, en;
	output reg [2:0] Q;

	always@(posedge clk)
	begin
		if(en == 1'b1)   //使能时Q++
		begin
			if(Q < 3'd7)
				Q <= Q + 1'b1;
			else
				Q <= 0;
		end
		else            //没有使能时Q被锁定
		Q <= Q;
	end

endmodule
