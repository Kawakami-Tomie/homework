transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/code6/code6 {E:/Quartusexperiment/code6/code6/py_1810_6.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/code6/code6 {E:/Quartusexperiment/code6/code6/py_1810_6_1.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/code6/code6 {E:/Quartusexperiment/code6/code6/py_1810_6_2.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/code6/code6 {E:/Quartusexperiment/code6/code6/py_1810_6_3.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/code6/code6 {E:/Quartusexperiment/code6/code6/py_1810_6_4.v}
vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/code6/code6 {E:/Quartusexperiment/code6/code6/py_1810_6_5.v}

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/code6/code6/simulation/modelsim {E:/Quartusexperiment/code6/code6/simulation/modelsim/py_1810_6.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  py_1810_6_vlg_tst

add wave *
view structure
view signals
run -all
