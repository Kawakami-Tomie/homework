module jmw_1763_8(clk, f0, p, sta, f1, f2);
 
input clk;	//25MHZ的高精度时钟源
input f0;	//虫后的发光信号
input p;		//0表示不在边界地区，1表示在边界地区
input sta;	//0表示安全，1表示敌人来犯
output f1;	//信虫电路的输出，哨虫电路的输入
output f2;	//哨虫电路的输出
reg f1,f2;
reg [14: 0] cnt;	//计数器
reg temp;	//寄存上一clk时刻f0值
reg flag;	//标志信号
	
always @ (posedge clk)
	begin
	
	if(temp==1'b0&&f0==1'b1)	
			flag <= 1'b1;	//判断f0上升沿，并给出标志信号
			
		if(flag)
			begin
				casex({p,sta})	//拼接在一起
					2'b0_x:	//哨虫不在边界地区，职能为信虫
					begin
						if(cnt < 15'd10000)//脉冲宽度为 0.4 毫秒
							begin
								f1 <= 1'b1;
								f2 <= 1'b1;
								cnt <= cnt + 1'd1;
							end
						else 
							begin
								f1 <= 1'b0;
								f2 <= 1'b0;
								cnt <= 15'd0;
								flag <= 1'b0;	//脉冲产生结束，标志信号置0
							end
					end
					2'b1_0:  //哨虫在边界地区，且边界安全，f2a
					begin
						if(cnt < 15'd2500)	//对应f2a的第一处高电平区
							begin
								f1 <= 1'b1;
								f2 <= 1'b1;		
								cnt <= cnt + 1'd1;
							end
						else if(cnt < 15'd5000)	//对应f2a的低电平区
							begin
								f1 <= 1'b1;
								f2 <= 1'b0;		
								cnt <= cnt + 1'd1;
							end
						else if(cnt < 15'd7500)	//对应f2a的第二处高电平区
							begin
								f1 <= 1'b1;
								f2 <= 1'b1;		
								cnt <= cnt + 1'd1;
							end
						else if(cnt < 15'd10000)	//对应f2a的第二处高电平区
							begin
								f1 <= 1'b1;
								f2 <= 1'b0;		
								cnt <= cnt + 1'd1;
							end
						else
							begin
								f1 <= 1'b0;
								f2 <= 1'b0;
								cnt <= 15'd0;
								flag <= 1'b0;	//脉冲产生结束，标志信号置0
							end
					end
					2'b1_1:  //哨虫在边界地区，且边界不安全，f2b
					begin
						if(cnt < 15'd2500)
							begin
								f1 <= 1'b1;
								f2 <= 1'b1;		//对应f2b的第一处高电平区
								cnt <= cnt + 1'd1;
							end
						else if(cnt < 15'd5000)
							begin
								f1 <= 1'b1;
								f2 <= 1'b0;		//对应f2b的第一处低电平区
								cnt <= cnt + 1'd1;
							end
						else if(cnt < 15'd7500)
							begin
								f1 <= 1'b1;
								f2 <= 1'b1;		//对应f2b的第二处高电平区
								cnt <= cnt + 1'd1;
							end
						else if(cnt < 15'd10000)
							begin
								f1 <= 1'b1;
								f2 <= 1'b0;		//对应f2b的第二处低电平区
								cnt <= cnt + 1'd1;
							end
						else if(cnt < 15'd12500)
							begin
								f1 <= 1'b0;
								f2 <= 1'b1;		//对应f2b的第三处高电平区
								cnt <= cnt + 1'd1;
							end
						else
							begin
								f1 <= 1'b0;
								f2 <= 1'b0;
								cnt <= 15'd0;
								flag <= 1'b0;	//脉冲产生结束，标志信号置0
							end
					end
				endcase
			end
		else	cnt <= 15'd0;	
	
	temp <= f0;
	
	end
 
endmodule
