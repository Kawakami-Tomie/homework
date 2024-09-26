//译码器子模块（底层文件）
module CW_2301_9_2 (P_out, Q);
	input[2:0] Q;
	output reg [2:0] P_out;
	
	always@(Q)
	begin
		case(Q)
		3'd0: P_out<=3'b111;   //逆时针旋转
		3'd1: P_out<=3'b011;
		3'd2: P_out<=3'b101;
		3'd3: P_out<=3'b001;
		3'd4: P_out<=3'b000;
		3'd5: P_out<=3'b100;
		3'd6: P_out<=3'b010;
		3'd7: P_out<=3'b110;
		default: P_out<=3'bx;       //未知态
		endcase
	end
	
endmodule
