# This script is created by NSG2 beta1
# <http://wushoupong.googlepages.com/nsg>

#===================================
#     Simulation parameters setup
#===================================
set val(stop)   10.0                         ;# time of simulation end

#===================================
#        Initialization        
#===================================
#Create a ns simulator
set ns [new Simulator]

#Open the NS trace file
set tracefile [open out.tr w]
$ns trace-all $tracefile

#Open the NAM trace file
set namfile [open out.nam w]
$ns namtrace-all $namfile

#===================================
#        Nodes Definition        
#===================================
#Create 5 nodes
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

#===================================
#        Links Definition        
#===================================
#Createlinks between nodes
$ns duplex-link $n1 $n2 100.0Mb 10ms DropTail
$ns queue-limit $n1 $n2 50
$ns duplex-link $n2 $n3 100.0Mb 10ms DropTail
$ns queue-limit $n2 $n3 50
$ns duplex-link $n5 $n3 100.0Mb 10ms DropTail
$ns queue-limit $n5 $n3 50
$ns duplex-link $n5 $n4 100.0Mb 10ms DropTail
$ns queue-limit $n5 $n4 50
$ns duplex-link $n4 $n1 100.0Mb 10ms DropTail
$ns queue-limit $n4 $n1 50
$ns duplex-link $n4 $n2 100.0Mb 10ms DropTail
$ns queue-limit $n4 $n2 50
$ns duplex-link $n2 $n5 100.0Mb 10ms DropTail
$ns queue-limit $n2 $n5 50
$ns duplex-link $n1 $n5 100.0Mb 10ms DropTail
$ns queue-limit $n1 $n5 50
$ns duplex-link $n4 $n3 100.0Mb 10ms DropTail
$ns queue-limit $n4 $n3 50
$ns duplex-link $n1 $n3 100.0Mb 10ms DropTail
$ns queue-limit $n1 $n3 50

#Give node position (for NAM)
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right-down
$ns duplex-link-op $n5 $n3 orient left-up
$ns duplex-link-op $n5 $n4 orient left

$ns duplex-link-op $n4 $n1 orient left-up
$ns duplex-link-op $n4 $n2 orient right-up
$ns duplex-link-op $n2 $n5 orient right-down
$ns duplex-link-op $n1 $n5 orient right-down
$ns duplex-link-op $n4 $n3 orient right-up
$ns duplex-link-op $n1 $n3 orient right

#===================================
#        Agents Definition        
#===================================

#===================================
#        Applications Definition        
#===================================

#===================================
#        Termination        
#===================================
#Define a 'finish' procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam out.nam &
    exit 0
}
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run
