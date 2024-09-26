module wys_lab_8(clk, f0, p, sta, f1, f2);
 
input clk;    //50MHz的高精度时钟源输入
input f0;    //虫后的发光信号，信虫电路的输入
input p;        //位置信息：0表示不在边界地区，1表示在边界地区
input sta;    //状态安全信息：0表示安全，1表示敌人来犯
 
//f1与虫后的f0同频同相
output f1;    //信虫电路的输出，哨虫电路的输入
output f2;    //哨虫电路的输出
reg f1,f2;
 
parameter N0 = 2500;    
//0.1毫秒的脉冲走过多少个时钟信号：0.1ms/(1/50MHz) = 0.1ms/20ns = 5000个
//防卫信号的脉冲宽度是0.1毫秒
//该信号是根据信虫信号f1进行的同步反馈
//如果安全(sta==0)，防卫信号是一个与f1同相的双脉冲信号f2a
//当敌人来犯(sta==1)，防卫信号是三脉冲信号f2b
 
reg [14: 0] cnt;    //计数
reg temp;    //寄存上一clk时刻f0值
reg flag;    //用以判断f0是否为上升沿给出的标志信号
    
always @ (posedge clk)
    begin
    
    if(!temp & f0)    //temp为上一clk时刻f0值
            flag <= 1'b1;    //判断f0上升沿，并给出标志信号
            
        if(flag)
            begin
                casex({p,sta})    //拼接在一起
                    2'b0_x:    //哨虫不在边界地区，职能为信虫
                    begin
                        if(cnt < 4*N0)
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
                                flag <= 1'b0;    //脉冲产生结束，标志信号置0
                            end
                    end
						  2'b1_0:  //哨虫在边界地区，且边界安全
                    begin
                        if(cnt < N0)
                            begin
                                f1 <= 1'b1;
                                f2 <= 1'b1;        //对应f2a的第一处高电平区
                                cnt <= cnt + 1'd1;
                            end
                        else if(cnt < 2*N0)
                            begin
                                f1 <= 1'b1;
                                f2 <= 1'b0;        //对应f2a的低电平区
                                cnt <= cnt + 1'd1;
                            end
                        else if(cnt < 3*N0)
                            begin
                                f1 <= 1'b1;
                                f2 <= 1'b1;        //对应f2a的第二处高电平区
                                cnt <= cnt + 1'd1;
                            end
                        else if(cnt < 4*N0)
                            begin
                                f1 <= 1'b1;
                                f2 <= 1'b0;        //对应f2a的第二处低电平区
                                cnt <= cnt + 1'd1;
                            end    
                        else
                            begin
                                f1 <= 1'b0;
                                f2 <= 1'b0;
                                cnt <= 15'd0;
                                flag <= 1'b0;    //脉冲产生结束，标志信号置0
                            end
                    end
						    2'b1_1:  //哨虫在边界地区，且边界不安全
                    begin
                        if(cnt < N0)
                            begin
                                f1 <= 1'b1;
                                f2 <= 1'b1;        //对应f2b的第一处高电平区
                                cnt <= cnt + 1'd1;
                            end
                        else if(cnt < 2*N0)
                            begin
                                f1 <= 1'b1;
                                f2 <= 1'b0;        //对应f2b的第一处低电平区
                                cnt <= cnt + 1'd1;
                            end
                        else if(cnt < 3*N0)
                            begin
                                f1 <= 1'b1;
                                f2 <= 1'b1;        //对应f2b的第二处高电平区
                                cnt <= cnt + 1'd1;
                            end
                        else if(cnt < 4*N0)
                            begin
                                f1 <= 1'b1;
                                f2 <= 1'b0;        //对应f2b的第二处低电平区
                                cnt <= cnt + 1'd1;
                            end
                        else if(cnt < 5*N0)
                            begin
                                f1 <= 1'b0;
                                f2 <= 1'b1;        //对应f2b的第三处高电平区
                                cnt <= cnt + 1'd1;
                            end
                        else
                            begin
                                f1 <= 1'b0;
                                f2 <= 1'b0;
                                cnt <= 15'd0;
                                flag <= 1'b0;    //脉冲产生结束，标志信号置0
                            end
                    end
                endcase
            end
        else    cnt <= 15'd0;    
    
    temp <= f0;
    
    end
 
endmodule