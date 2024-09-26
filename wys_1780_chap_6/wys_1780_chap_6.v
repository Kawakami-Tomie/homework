module wys_1780_chap_6(
	input clk,
	input rstn,
	output reg [6:0] seg, // 数码管
	output reg [7:0] sel, // 选择位数
	output reg [3:0] tub, // 输出的数
	output reg [1:0] con // 控制赋值哪位
);
	reg [31:0] cnt; // 16位寄存器，用于计数
	reg clk1k; // 时钟信号，1kHz的时钟
	reg flag;
	reg [3:0] k1 = 4'd7;
	reg [3:0] k2 = 4'd8;
	reg [3:0] k3 = 4'd0;
	always @ (posedge clk or negedge rstn) // 时钟上沿或下沿
	begin
		if (!rstn) // 如果复位信号为低电平
		begin
			cnt <= 0; // 计数器复位为0
			clk1k <= 0; // 1kHz时钟信号复位为低电平
		end 
		else if (cnt >= 24999999) // 如果计数达到24999（1kHz频率下1秒的计数值）
		begin
			clk1k <= !clk1k; // 切换1kHz时钟信号的状态
			cnt <= 0; // 计数器复位为0
		end
		else
			cnt <= cnt + 1; // 计数器递增
	end
	always @ (posedge clk1k or negedge rstn)
	begin
		if (!rstn) // 如果复位信号为低电平
		begin
			tub <= 0; // 七段数码管显示值复位为0
			con <= 0; // 控制信号复位为0
			sel <= 0; // 选择信号复位为0
			seg <= 0; // 段选信号复位为0
			flag <= 0;
		end
		else
		begin
			if (con < 2 && flag == 1)
				con = con + 1'd1; // 控制信号递增
			else
				begin
				
				con = 0; // 控制信号复位为0
				flag = 1'd1;
				end
			case(con) // 根据控制信号值进行不同的操作
			2'b00:begin sel = 8'b0000_0100;tub = k1;end
			2'b01:begin sel = 8'b0000_0010;tub = k2;end
			2'b10:begin sel = 8'b0000_0001;tub = k3;end
			endcase 
			//调用数码管
			
			case(tub) // 根据七段数码管显示值进行不同的操作
			4'd0: seg = 7'b1111110;
			4'd1: seg = 7'b0110000;
			4'd2: seg = 7'b1101101;
			4'd3: seg = 7'b1111001;
			4'd4: seg = 7'b0110011;
			4'd5: seg = 7'b1011011;
			4'd6: seg = 7'b1011111;
			4'd7: seg = 7'b1110000;
			4'd8: seg = 7'b1111111;
			4'd9: seg = 7'b1111011; 
			default: seg = 7'b0000001; // 将大于9的数显示为-负号
			endcase
		end
	end
endmodule 