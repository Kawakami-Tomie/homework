transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/Users/A/Documents/Tencent\ Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0 {C:/Users/A/Documents/Tencent Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0/gsq_1783_6_0.v}
vlog -vlog01compat -work work +incdir+C:/Users/A/Documents/Tencent\ Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0 {C:/Users/A/Documents/Tencent Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0/gsq_1783_6_1.v}
vlog -vlog01compat -work work +incdir+C:/Users/A/Documents/Tencent\ Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0 {C:/Users/A/Documents/Tencent Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0/gsq_1783_6_2.v}
vlog -vlog01compat -work work +incdir+C:/Users/A/Documents/Tencent\ Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0 {C:/Users/A/Documents/Tencent Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0/gsq_1783_6_3.v}
vlog -vlog01compat -work work +incdir+C:/Users/A/Documents/Tencent\ Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0 {C:/Users/A/Documents/Tencent Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0/gsq_1783_6_4.v}
vlog -vlog01compat -work work +incdir+C:/Users/A/Documents/Tencent\ Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0 {C:/Users/A/Documents/Tencent Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0/gsq_1783_6_5.v}

vlog -vlog01compat -work work +incdir+C:/Users/A/Documents/Tencent\ Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0 {C:/Users/A/Documents/Tencent Files/2971508120/FileRecv/gsq_1783_6_0/gsq_1783_6_0/test_gsq_1783_6_0.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L cycloneive_ver -L rtl_work -L work -voptargs="+acc"  gsq_1783_6_0_vlg_tst

add wave *
view structure
view signals
run -all
