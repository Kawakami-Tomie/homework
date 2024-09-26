module wys_lab_7(clk, rst_n, key_in, key_flag, key_state, codeout, Q, CO);
 
input clk;        //时钟50MHz
input rst_n;      //复位信号
input key_in;     //按键输入
 
 
output key_state;		//按键状态，高电平为未按下，低电平为按下状态
output key_flag;		//经消抖后可确认的按下动作
 
output CO;		//进位信号
output reg [6: 0] codeout;
output reg [3: 0] Q;	
  
 
parameter   S1 = 2'b00,		//松开稳定时
            S2 = 2'b01,		//按下毛刺时
            S3 = 2'b10,		//按下稳定时
            S4 = 2'b11;		//松开毛刺时
				
 
 
/*===============================================================20ms计数器=============================================================*/
reg en_counter;	//计数使能
reg [19:0] cnt;	//计数
reg cnt_full;
 
//只有当计数使能为高电平的时候，计数器才会计数
always@(posedge clk or negedge rst_n)
	begin
		if(!rst_n)
			cnt <= 0;
		else if(en_counter)
			cnt <= cnt + 1'b1;
		else 
			cnt <= 0;
	end
	
//计数满信号（数数到1000000计数满时间到。1000000是1M，当基于clk信号频率进行计数时，cnt_full走过(1/50M)s*1M的时间，即20ms）
always@(posedge clk or negedge rst_n)	//当clk接50MHz的信号时，相当于clk在1s内进行了50M次计数，相邻上升沿相间(1/50M)s
begin
	if(!rst_n)
		cnt_full <= 1'b0;
	else if(cnt == 20'd1000000)	//1000000的二进制数有20位（2^20=1048576）
		cnt_full <= 1'b1;
	else 
		cnt_full <= 1'b0;
end
 
 
 
/*==============================================================判断边沿模块=============================================================*/
reg key_tmp0,key_tmp1;
 
always@(posedge clk or negedge rst_n)
	begin
		if(!rst_n)
			begin
				key_tmp0 <= 1'b1;
				key_tmp1 <= 1'b1;
			end
			
		else
			begin
				key_tmp0 <= key_in;		//key_in按键输入
				key_tmp1 <= key_tmp0;	
			end
			
	end
 
wire pedge,nedge;
assign nedge = (!key_tmp0) & key_tmp1;        //下降沿（下一clk时为0，上一clk时为1）
assign pedge = key_tmp0 & (!key_tmp1);        //上升沿（下一clk时为1，上一clk时为0）
 
 
 
/*=============================================================状态机模块================================================================*/
reg [1:0] state;
reg key_flag;		//经消抖后可确认的按下动作
reg key_state;		//按键状态，高电平为未按下，低电平为按下状态
 
always@(posedge clk or negedge rst_n)
	begin
		
		if(!rst_n)
			begin
				state      <= S1; 
				en_counter <= 1'b0;	//计数器归零
				key_state  <= 1'b1;	//按键未按下
				key_flag   <= 1'b0;
			end
		
		else 
			begin
				case(state)
					
					S1:	//高电平（松开稳定）
						begin
							key_flag   <= 1'b0;	//按键未按下，不计
							key_state  <= 1'b1;	//按键松开状态
							en_counter <= 1'b0;	//计数器归零
							
							if(nedge)	//检测到下降沿，进入下一个状态同时打开计数器
								begin
									state      <= S2;
									en_counter <= 1'b1;	//计数器使能
								end
							
							else 
								state <= state;	//保持目前状态    
						end
					
					S2:	//下降沿抖动（按下毛刺）
						if(cnt_full)	//计数满，说明达到稳定状态，关闭计数器，进入下一个状态
							begin
								state      <= S3;
								en_counter <= 1'b0;	//计数器归零
								key_flag   <= 1'b1;	//按键可确认已按下
								key_state  <= 1'b0;	//按键按下状态
							end
						
						else if(pedge)	//检测到上升沿（毛刺），跳回S1状态同时关闭计数器
							begin
								en_counter <= 1'b0;	//计数器归零
								state      <= S1;
							end
						
						else 
							state <= state;	//保持目前状态
							
					S3:	//低电平（按下稳定）
						begin
							key_flag <= 1'b0;	//一个按键周期测到一次就行，现在可清零了（后面代码编写只在意其posedge）
							
							if(pedge)	//检测到上升沿，进入下一个状态同时打开计数器
								begin
									state      <= S4;
									en_counter <= 1'b1;	//计数器使能
								end
							
							else 
								state <= state;	//保持目前状态
						end
					
					S4:	//上升沿抖动（松开毛刺）
						if(cnt_full)
							begin
								state     <= S1;
								key_state <= 1'b1;
							end
						
						else 
							if(nedge)
								begin
									en_counter <= 1'b0;	//计数器归零
									state      <= S3;					 		
								end 
							else 
								state <= state;	//保持目前状态
					
					default:
						state <= S1;
						
					endcase
	
			end
	
	end
 
	
 
/*===========================================================计数值输出与译码器模块========================================================*/
always@(posedge key_flag,negedge rst_n)	//key_flag：经消抖后可确认的按下动作
	if(!rst_n)
		Q <= 0;
	else
		begin
			if(Q < 4'd9)
				Q <= Q + 1'b1;
			else
				Q <= 4'b0;
		end
	
	assign CO = (rst_n & Q == 4'd9);
	
always@(Q)
	begin
		case(Q)
			4'd0:codeout <= 7'b1111110;
			4'd1:codeout <= 7'b0110000;
			4'd2:codeout <= 7'b1101101;
			4'd3:codeout <= 7'b1111001;
			4'd4:codeout <= 7'b0110011;
			4'd5:codeout <= 7'b1011011;
			4'd6:codeout <= 7'b1011111;
			4'd7:codeout <= 7'b1110000;
			4'd8:codeout <= 7'b1111111;
			4'd9:codeout <= 7'b1111011;
		default:codeout <= 7'bx;
	endcase
end
 
 
 
endmodule