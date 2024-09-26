module wys_1780_3_1(clk,en,Q);
input clk,en; //输入时钟使能
output reg[2:0] Q; //寄存器输出
 
always@(posedge clk)
begin
	if(en == 1'b1)//脉冲信号为1时执行
	begin
		if(Q < 3'd6) //如果Q没有到7
		Q <= Q + 1'b1;  //增加1
		else
		Q <= 0;
	end
	else
	Q <=Q;
end
endmodule