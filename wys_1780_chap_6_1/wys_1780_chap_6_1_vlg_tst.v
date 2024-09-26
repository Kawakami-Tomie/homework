`timescale 10 ns/ 1 ns
module wys_1780_chap_6_vlg_tst();
 
reg clk_in;
// wires                                               
wire [7:0]  DIG;
wire [6:0]  SEG;
wire [1:0]  SEL;
wire clk_1khz;
wire [3:0]  data;                       
wys_1780_chap_6_1 i1 (
  
	.DIG(DIG),
	.SEG(SEG),
	.SEL(SEL),
	.clk_1khz(clk_1khz),
	.clk_in(clk_in),
	.data(data)
);
initial                                                
begin                                                                           
          clk_in=1'b0;                                             
end                                                    
always                                                                  
begin                                                  
  #1
clk_in=~clk_in;                                                                                                                                              
end                                                    
endmodule

