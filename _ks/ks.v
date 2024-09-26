module ks(drinkout,changemoney,one,half,reset,clk,seg,out);

parameter s0=3'b000,s1=3'b001,s2=3'b010,s3=3'b011,s4=3'b100;//状态机，五个状态，要三位

output drinkout,changemoney; //饮料;找零

input one,half,reset,clk; //1，0.5

output seg;//位选
output out;//段选

reg[7:0]seg;
reg[7:0]out;
reg[4:0]sum;
reg[4:0]change;//找零标志位
reg[4:0]temp;

reg[4:0]state1;//状态
reg[3:0]state2;//数码管

reg drinkout,changemoney;

reg puth,puti;

//状态机
always @(negedge reset, posedge one, posedge half, posedge clk)
begin
	if(!reset)
			begin
			drinkout=0;
			changemoney=0;
			state1=0;//s0
		   puth=0;
			puti=0;
			sum=0;
			change=0;
			end 
    else if(half) puth=1; // 0.5                                       
    else if(one)  puti=1; // 1
    else
        begin 
              case(state1)
				  s0:begin 
						drinkout=0;
						changemoney=0;
					   sum=0; 
						change=0;
					   if(puth==1)
							begin //投0.5->s1
							state1=s1;puth=0;
							end
					   else if(puti==1)
								begin // 投1元->s2
								state1=s2;puti=0;
								end
								else state1 = s0; 
					   end
				  s1: begin 
						drinkout=0;
						changemoney=0; 
					   sum=5'd5; //sum=0.5
					   change=0;
					   if(puth==1)//投0.5->s2
							begin 
							state1=s2;puth=0;
							end
						else if(puti==1)//投1->s3
							begin
	                  state1=s3;puti=0;
							end
                     else state1 = s1; 
					   end
				  s2: begin 
						drinkout=0;
						changemoney=0; 
						sum=5'd10;//sum=1
						change=0;
					   if(puth==1)//投0.5->s3
							begin  
							state1=s3;puth=0;
							end  
					   else if(puti==1)//投1->s4,需要找零
							begin 
							state1=s4;puti=0; 
							end  
                    else state1 = s2; 
					   end
				  s3: begin 
				      drinkout=1;//出饮料，不找零
						changemoney=0;  					  					   	 
						sum=5'd15;
						change=0;
						puth=0;
						puti=0;
                  state1 = s3;//s3回到初始态
					   end  
              s4: begin 
						drinkout=1;//出饮料，找零
						changemoney=1;  
						sum=5'd20;
						change=5'd5;
						puth=0; 
						puti=0;
                  state1 = s4;//s4回到初始态
					   end
             endcase
        end
end          


//译码器
always@(temp) begin  
	case(temp)  
		5'd0:out[6:0]=7'b111_1110;
		5'd1:out[6:0]=7'b011_0000;
		5'd2:out[6:0]=7'b110_1101;
		5'd5:out[6:0]=7'b101_1011;
	endcase
end


//数码管模块，循环显示（频率由clk控制），前四位显示总额，后四位显示找零
always@(posedge clk)
begin
	case(state2)  
	0:	begin //找零值
			begin
			seg=8'b0000_0001; out[7]=0; 
			if(change==0) temp=0;
			else temp=change;
			end
			state2=1;
		end
	1:	begin //总额个位
			seg=8'b0001_0000; out[7]=0;
			if(sum==0 || sum==5'd10 || sum==5'd20) temp=0;
			else temp=5'd5;
			state2=2;
		end
	2:	begin	//总额十位
			seg=8'b0010_0000;out[7]=1;//显示小数点
			if(sum==0 || sum==5'd5) temp=0;
			else if(sum==5'd10 || sum==5'd15) temp =5'd1;
			else temp = 5'd2;
			state2=3;
		end
	3: begin
			seg=8'b0000_0010; out[7]=1; //显示小数点
			temp=0;
			state2=0;
			end
	default:state2=0;
	endcase
end



endmodule