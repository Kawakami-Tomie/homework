`timescale 10 ns/ 1 ns
module jmw_1763_7_test();

reg clk;
reg key_in;
reg rst_n;
// wires                                               
wire CO;
wire [3:0]  Q;
wire [6:0]  codeout;
wire key_flag;
wire key_state;

// assign statements (if any)                          
jmw_1763_7 i1 (
// port map - connection between master ports and signals/registers   
	.CO(CO),
	.Q(Q),
	.clk(clk),
	.codeout(codeout),
	.key_flag(key_flag),
	.key_in(key_in),
	.key_state(key_state),
	.rst_n(rst_n)
);
initial                                                
begin                                                  
			clk	=1'b0;
			rst_n =1'b0;
			key_in=1'b1;
			//wait 100ns for global reset to finish
			#200
			rst_n=1'b1;
$display("Running testbench");                       
end                                                    
always                                                 
// optional sensitivity list                           
// @(event1 or event2 or .... eventn)                  
begin                                                  
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#(50*1000000);
			
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#1000000;
			key_in=1'b0;#1000000;
			key_in=1'b1;#(50*1000000);
end 
always
begin
#10 clk=~clk;
end                                                   
endmodule

 