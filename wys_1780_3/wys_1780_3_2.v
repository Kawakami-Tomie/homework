module wys_1780_3_2(codeout, Q);
	input[2: 0] Q;			
	output reg[5: 0] codeout;		
	
	always @ (*)			//用always块语句描述逻辑
	begin
		case (Q)  //根据计数器信号输出相应信号
		3'd0: codeout <= 6'b100000;
		3'd1: codeout <= 6'b110000;
		3'd2: codeout <= 6'b111000;
		3'd3: codeout <= 6'b011100;
		3'd4: codeout <= 6'b001110;
		3'd5: codeout <= 6'b000111;
		3'd6: codeout <= 6'b000011; 
		
		default: codeout <= 6'bx;	
		endcase
	end
endmodule