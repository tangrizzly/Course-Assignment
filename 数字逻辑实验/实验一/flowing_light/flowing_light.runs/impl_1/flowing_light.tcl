proc start_step { step } {
  set stopFile ".stop.rst"
  if {[file isfile .stop.rst]} {
    puts ""
    puts "*** Halting run - EA reset detected ***"
    puts ""
    puts ""
    return -code error
  }
  set beginFile ".$step.begin.rst"
  set platform "$::tcl_platform(platform)"
  set user "$::tcl_platform(user)"
  set pid [pid]
  set host ""
  if { [string equal $platform unix] } {
    if { [info exist ::env(HOSTNAME)] } {
      set host $::env(HOSTNAME)
    }
  } else {
    if { [info exist ::env(COMPUTERNAME)] } {
      set host $::env(COMPUTERNAME)
    }
  }
  set ch [open $beginFile w]
  puts $ch "<?xml version=\"1.0\"?>"
  puts $ch "<ProcessHandle Version=\"1\" Minor=\"0\">"
  puts $ch "    <Process Command=\".planAhead.\" Owner=\"$user\" Host=\"$host\" Pid=\"$pid\">"
  puts $ch "    </Process>"
  puts $ch "</ProcessHandle>"
  close $ch
}

proc end_step { step } {
  set endFile ".$step.end.rst"
  set ch [open $endFile w]
  close $ch
}

proc step_failed { step } {
  set endFile ".$step.error.rst"
  set ch [open $endFile w]
  close $ch
}

set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
set_msg_config -id {Synth 8-256} -limit 10000
set_msg_config -id {Synth 8-638} -limit 10000

start_step init_design
set rc [catch {
  create_msg_db init_design.pb
  set_property design_mode GateLvl [current_fileset]
  set_property webtalk.parent_dir C:/Users/gyl/Vivado/DigitalLogic/flowing_light/flowing_light.cache/wt [current_project]
  set_property parent.project_path C:/Users/gyl/Vivado/DigitalLogic/flowing_light/flowing_light.xpr [current_project]
  set_property ip_repo_paths c:/Users/gyl/Vivado/DigitalLogic/flowing_light/flowing_light.cache/ip [current_project]
  set_property ip_output_repo c:/Users/gyl/Vivado/DigitalLogic/flowing_light/flowing_light.cache/ip [current_project]
  add_files -quiet C:/Users/gyl/Vivado/DigitalLogic/flowing_light/flowing_light.runs/synth_1/flowing_light.dcp
  read_xdc C:/Users/gyl/Vivado/DigitalLogic/flowing_light/flowing_light.srcs/constrs_1/new/top_xdc.xdc
  link_design -top flowing_light -part xc7a35tcsg324-1
  close_msg_db -file init_design.pb
} RESULT]
if {$rc} {
  step_failed init_design
  return -code error $RESULT
} else {
  end_step init_design
}

start_step opt_design
set rc [catch {
  create_msg_db opt_design.pb
  catch {write_debug_probes -quiet -force debug_nets}
  opt_design 
  write_checkpoint -force flowing_light_opt.dcp
  report_drc -file flowing_light_drc_opted.rpt
  close_msg_db -file opt_design.pb
} RESULT]
if {$rc} {
  step_failed opt_design
  return -code error $RESULT
} else {
  end_step opt_design
}

start_step place_design
set rc [catch {
  create_msg_db place_design.pb
  catch {write_hwdef -file flowing_light.hwdef}
  place_design 
  write_checkpoint -force flowing_light_placed.dcp
  report_io -file flowing_light_io_placed.rpt
  report_utilization -file flowing_light_utilization_placed.rpt -pb flowing_light_utilization_placed.pb
  report_control_sets -verbose -file flowing_light_control_sets_placed.rpt
  close_msg_db -file place_design.pb
} RESULT]
if {$rc} {
  step_failed place_design
  return -code error $RESULT
} else {
  end_step place_design
}

start_step route_design
set rc [catch {
  create_msg_db route_design.pb
  route_design 
  write_checkpoint -force flowing_light_routed.dcp
  report_drc -file flowing_light_drc_routed.rpt -pb flowing_light_drc_routed.pb
  report_timing_summary -warn_on_violation -max_paths 10 -file flowing_light_timing_summary_routed.rpt -rpx flowing_light_timing_summary_routed.rpx
  report_power -file flowing_light_power_routed.rpt -pb flowing_light_power_summary_routed.pb
  report_route_status -file flowing_light_route_status.rpt -pb flowing_light_route_status.pb
  report_clock_utilization -file flowing_light_clock_utilization_routed.rpt
  close_msg_db -file route_design.pb
} RESULT]
if {$rc} {
  step_failed route_design
  return -code error $RESULT
} else {
  end_step route_design
}

