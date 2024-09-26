transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_a6 {E:/Quartusexperiment/wys_a6/wys_1780_6_5.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_a6 {E:/Quartusexperiment/wys_a6/wys_1780_6_4.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_a6 {E:/Quartusexperiment/wys_a6/wys_1780_6_3.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_a6 {E:/Quartusexperiment/wys_a6/wys_1780_6_2.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_a6 {E:/Quartusexperiment/wys_a6/wys_1780_6_1.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_a6 {E:/Quartusexperiment/wys_a6/wys_1780_6.v}

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_a6/simulation/modelsim {E:/Quartusexperiment/wys_a6/simulation/modelsim/wys_1780_6.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  wys_1780_6_vlg_tst

add wave *
view structure
view signals
run -all
