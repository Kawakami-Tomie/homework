transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/_ks {E:/Quartusexperiment/_ks/ks.v}

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/_ks/simulation/modelsim {E:/Quartusexperiment/_ks/simulation/modelsim/ks.vt}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  ks_vlg_tst

add wave *
view structure
view signals
run -all
