module wys_1780_4(clkin, clr, Q, CO, upd, en, load, data);   //十进制计数器
	input  clkin, clr, upd, en, load;
	input  [3: 0] data;
	output [3: 0] Q;
	reg [3: 0] Q;
	output wire CO;
	always@(posedge clkin, negedge clr)
		if(!clr)			//异步清零
			Q <= 4'd0;
		else if(!load)		//同步置数（若为低电平则直接赋值，数码管显示本时刻数值）
			Q <= data;
		else if(en)		    //使能（en高电平）
			begin
				if(upd)			//同步置数，加法计数（upd=1）
					begin
						if(Q == 4'd9)
							Q <= 4'd0;
						else
							Q <= Q + 4'd1;
					end
				else			//同步置数，减法计数（upd=0）
					begin
						if(Q == 4'd0)
							Q <= 4'd9;
						else
							Q <= Q - 4'd1;
					end
			end
	assign CO = (upd & (Q == 4'd9)) | (~upd & (Q == 4'd0) & clr); 	//（upd为高电平且Q为9）或者（upd为低电平且Q为0且clk为0）
endmodule