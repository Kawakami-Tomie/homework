transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/qm_test {E:/Quartusexperiment/qm_test/qm_test.v}

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/qm_test/simulation/modelsim {E:/Quartusexperiment/qm_test/simulation/modelsim/qm_test.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  qm_test_vlg_tst

add wave *
view structure
view signals
run -all
