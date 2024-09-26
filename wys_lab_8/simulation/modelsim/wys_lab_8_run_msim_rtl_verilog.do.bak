transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_lab_8 {E:/Quartusexperiment/wys_lab_8/wys_lab_8.v}

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/wys_lab_8/simulation/modelsim {E:/Quartusexperiment/wys_lab_8/simulation/modelsim/wys_lab_8.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  wys_lab_8_vlg_tst

add wave *
view structure
view signals
run -all
