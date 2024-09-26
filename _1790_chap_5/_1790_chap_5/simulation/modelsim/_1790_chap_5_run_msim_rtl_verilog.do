transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/_1790_chap_5/_1790_chap_5 {E:/Quartusexperiment/_1790_chap_5/_1790_chap_5/_1790_chap_5.v}

vlog -vlog01compat -work work +incdir+E:/Quartusexperiment/_1790_chap_5/_1790_chap_5 {E:/Quartusexperiment/_1790_chap_5/_1790_chap_5/_1790_chap_5_test.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  _1790_chap_5_test

add wave *
view structure
view signals
run -all
