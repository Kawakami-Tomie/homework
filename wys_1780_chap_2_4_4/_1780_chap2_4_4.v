module _1780_chap2_4_4(A, B, SEL, L);
input A, B, SEL;
output L;
reg L; //define register variable
always @(SEL or A or B)
if (SEL == 1) L = B; //也可以写成 if (SEL) L=B;
else L = A;
endmodule
