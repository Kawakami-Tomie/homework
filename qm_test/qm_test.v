//module qm_test(cp,out);
//	input cp;
//	output reg out;
//	
//	reg [2:0] counter;
//	
//	always@(posedge cp)
//	begin
//		if(counter < 3'b101)
//
//			begin
//			 counter <= counter + 3'b001;
//			 case (counter)
//			 3'b000:out<=1'b1;
//			 3'b001:out<=1'b1;
//			 3'b010:out<=1'b0;
//			 3'b011:out<=1'b1;
//			 3'b100:out<=1'b0;
//			 3'b101:out<=1'b0;
//			 endcase 
//			end
//			else
//			begin
//				counter <=3'b000;
//			end
//		end
//endmodule


module qm_test(  
    input clk,     
    input Key1,    
    output reg P_out 
);  
  
 
    reg [23:0] counter = 0;    
    reg [6:0] duty_cycle = 90; 
    reg key_pressed = 0;       
  
  
    localparam FREQ_DIV = 50000 - 1;  
  

    always @(posedge clk) begin  
        if (!key_pressed && Key1) begin  

            key_pressed <= 1;  
            if (duty_cycle > 10) begin  
                duty_cycle <= duty_cycle - 10;  
            end else begin  
                duty_cycle <= 90; 
            end  
        end else if (key_pressed && !Key1) begin  
    
            key_pressed <= 0;  
        end  
    end  
 
    always @(posedge clk) begin  
        if (counter == FREQ_DIV) begin  
            
            counter <= 0;  
            if (P_out) begin  
                P_out <= 0;  
            end else if (counter < (duty_cycle * (FREQ_DIV / 100))) begin  
                P_out <= 1;  
            end  
        end else begin  
            counter <= counter + 1;  
        end  
    end  
  
endmodule