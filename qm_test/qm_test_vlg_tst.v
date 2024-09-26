// Copyright (C) 2018  Intel Corporation. All rights reserved.
// Your use of Intel Corporation's design tools, logic functions 
// and other software and tools, and its AMPP partner logic 
// functions, and any output files from any of the foregoing 
// (including device programming or simulation files), and any 
// associated documentation or information are expressly subject 
// to the terms and conditions of the Intel Program License 
// Subscription Agreement, the Intel Quartus Prime License Agreement,
// the Intel FPGA IP License Agreement, or other applicable license
// agreement, including, without limitation, that your use is for
// the sole purpose of programming logic devices manufactured by
// Intel and sold by Intel or its authorized distributors.  Please
// refer to the applicable agreement for further details.

// *****************************************************************************
// This file contains a Verilog test bench template that is freely editable to  
// suit user's needs .Comments are provided in each section to help the user    
// fill out necessary details.                                                  
// *****************************************************************************
// Generated on "06/05/2024 23:45:46"
                                                                                
// Verilog Test Bench template for design : qm_test
// 
// Simulation tool : ModelSim-Altera (Verilog)
// 

`timescale 10 ns/ 1 ns
module qm_test_vlg_tst();
// constants                                           
// general purpose registers

// test vector input registers
reg cp;
// wires                                               
wire out;

// assign statements (if any)                          
qm_test i1 (
// port map - connection between master ports and signals/registers   
	.cp(cp),
	.out(out)
);
initial                                                
begin                                                  
// code that executes only once                        
// insert code here --> begin                          
//      out=1'b0; 
		cp=1'b0;
// --> end                                             
//$display("Running testbench");                       
end                                                    
always                                                 
// optional sensitivity list                           
// @(event1 or event2 or .... eventn)                  
begin                                                  
// code executes for every event on sensitivity list   
// insert code here --> begin                          
                                                       
	#1
	cp=~cp;                                             
// --> end                                             
end                                                    
endmodule

