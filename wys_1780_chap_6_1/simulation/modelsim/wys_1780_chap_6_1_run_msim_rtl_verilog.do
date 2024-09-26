transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_1780_chap_6_1 {E:/Quartusexperiment/wys_1780_chap_6_1/wys_1780_chap_6_1.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_1780_chap_6_1 {E:/Quartusexperiment/wys_1780_chap_6_1/wys_1780_chap_6_2.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_1780_chap_6_1 {E:/Quartusexperiment/wys_1780_chap_6_1/wys_1780_chap_6_3.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_1780_chap_6_1 {E:/Quartusexperiment/wys_1780_chap_6_1/wys_1780_chap_6_4.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_1780_chap_6_1 {E:/Quartusexperiment/wys_1780_chap_6_1/wys_1780_chap_6_5.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_1780_chap_6_1 {E:/Quartusexperiment/wys_1780_chap_6_1/wys_1780_chap_6_6.v}

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_1780_chap_6_1/simulation/modelsim {E:/Quartusexperiment/wys_1780_chap_6_1/simulation/modelsim/wys_1780_chap_6_1.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  wys_1780_chap_6_1_vlg_tst

add wave *
view structure
view signals
run -all
