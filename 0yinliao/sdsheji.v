module sdsheji(one,half,reset,clk,ydrink,ymoney,seg,out);
parameter s0=3'b000,s1=3'b001,s2=3'b010,s3=3'b011,s4=3'b100;
input one,half,reset,clk; //1元，0.5元，重置，时钟
output ydrink,ymoney; //接LED0灯，提示饮料输出;接LED1灯，提示找零
output seg;//控制某个数目管亮
output out;//控制数码管的显示
reg[7:0]seg;
reg[7:0]out;
reg[4:0]sum;
reg[4:0]change;
reg[4:0]temp;
reg ydrink,ymoney;
reg[4:0]state1;
reg[3:0]state2;
reg j,k;

//状态机
always @(negedge reset, posedge one, posedge half, posedge clk)
begin
	if(!reset)
			begin
			ydrink=0;
			ymoney=0;
			state1=0;
		   j=0;k=0;
			sum=0; change=0;
			end 
    else if(half) j=1;                                         
    else if(one)  k=1;
    else
        begin 
              case(state1)
				  s0:begin ymoney=0;ydrink=0;
					   sum=0; change=0;
					   if(j==1)begin //投入0.5元，进入状态s1
							state1=s1;j=0; end
					   else if(k==1)begin // 投入1元，进入状态s2
							state1=s2;k=0; end
                     else state1 = s0; 
					  end
				  s1: begin ymoney=0;ydrink=0; //已投0.5元
					  sum=5'd5; change=0;
					   if(j==1)begin 
							state1=s2;j=0; end
						else if(k==1)begin
	                  state1=s3;k=0; end
                     else state1 = s1; 
					  end
				  s2: begin ymoney=0;ydrink=0; //已投1元
					  sum=5'd10; change=0;
					   if(j==1)begin  
							state1=s3;j=0; end  
					   else if(k==1)begin 
							state1=s4;k=0; end  
                    else state1 = s2; 
					   end
//已经投入1.5元，售出饮料，找零为0元
				  s3: begin ymoney=0;ydrink=1;  					  					   	 
				     sum=5'd15; change=0;
					  j=0; k=0;
                    state1 = s3;
					  end  
 //已经投入2元，则售出饮料，找零0.5元
              s4: begin ymoney=1;ydrink=1;  
					  sum=5'd20; change=5'd5;
					  j=0; k=0;
                   state1 = s4;
					  end
             endcase
        end
end          

//用于控制哪个数码管亮，在这几个状态之间一直循环，形成同时亮的视觉现象

always@(posedge clk)
begin
	case(state2)  
	0:	begin //显示找零值
			begin
			seg=8'b0000_0001; out[7]=0; 
			if(change==0) temp=0;
			else temp=5'd5;
			end
			state2=1;
		end
	1:	begin //显示投币总额的个位数
			seg=8'b0001_0000; out[7]=0;
			if(sum==0 || sum==5'd10 || sum==5'd20) temp=0;
			else temp=5'd5;
			state2=2;
		end
	2:	begin	//显示投币总额的十位数
			seg=8'b0010_0000;out[7]=1;
			if(sum==0 || sum==5'd5) temp=0;
			else if(sum==5'd10 || sum==5'd15) temp =5'd1;
			else temp = 5'd2;
			state2=3;
		end
	3: begin
			seg=8'b0000_0010; out[7]=1; 
			temp=0;
			state2=0;
			end
	default:state2=0;
	endcase
end
always@(temp) begin  //接数码管
	case(temp)  //共就四种显示
		5'd0:out[6:0]=7'b111_1110;
		5'd1:out[6:0]=7'b011_0000;
		5'd2:out[6:0]=7'b110_1101;
		5'd5:out[6:0]=7'b101_1011;
	endcase
end

endmodule