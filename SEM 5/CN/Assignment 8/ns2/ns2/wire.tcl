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
#Create 40 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]
set n9 [$ns node]
set n10 [$ns node]
set n11 [$ns node]
set n12 [$ns node]
set n13 [$ns node]
set n14 [$ns node]
set n15 [$ns node]
set n21 [$ns node]
set n22 [$ns node]
set n23 [$ns node]
set n24 [$ns node]
set n25 [$ns node]
set n26 [$ns node]
set n27 [$ns node]
set n28 [$ns node]
set n29 [$ns node]
set n30 [$ns node]
set n31 [$ns node]
set n32 [$ns node]
set n33 [$ns node]
set n34 [$ns node]
set n35 [$ns node]
set n37 [$ns node]
set n39 [$ns node]
set n42 [$ns node]
set n43 [$ns node]
set n45 [$ns node]
set n46 [$ns node]
set n47 [$ns node]
set n48 [$ns node]
set n49 [$ns node]
set n50 [$ns node]

#===================================
#        Links Definition        
#===================================
#Createlinks between nodes
$ns duplex-link $n0 $n1 100.0Mb 10ms DropTail
$ns queue-limit $n0 $n1 50
$ns duplex-link $n1 $n6 100.0Mb 10ms DropTail
$ns queue-limit $n1 $n6 50
$ns duplex-link $n6 $n7 100.0Mb 10ms DropTail
$ns queue-limit $n6 $n7 50
$ns duplex-link $n7 $n8 100.0Mb 10ms DropTail
$ns queue-limit $n7 $n8 50
$ns duplex-link $n8 $n9 100.0Mb 10ms DropTail
$ns queue-limit $n8 $n9 50
$ns duplex-link $n9 $n10 100.0Mb 10ms DropTail
$ns queue-limit $n9 $n10 50
$ns simplex-link $n2 $n11 100.0Mb 10ms DropTail
$ns queue-limit $n2 $n11 50
$ns simplex-link $n11 $n12 100.0Mb 10ms DropTail
$ns queue-limit $n11 $n12 50
$ns simplex-link $n12 $n13 100.0Mb 10ms DropTail
$ns queue-limit $n12 $n13 50
$ns simplex-link $n14 $n13 100.0Mb 10ms DropTail
$ns queue-limit $n14 $n13 50
$ns simplex-link $n15 $n14 100.0Mb 10ms DropTail
$ns queue-limit $n15 $n14 50
$ns simplex-link $n1 $n2 100.0Mb 10ms DropTail
$ns queue-limit $n1 $n2 50
$ns simplex-link $n6 $n11 100.0Mb 10ms RED
$ns queue-limit $n6 $n11 50
$ns simplex-link $n7 $n12 100.0Mb 10ms FQ
$ns queue-limit $n7 $n12 50
$ns simplex-link $n8 $n13 100.0Mb 10ms DRR
$ns queue-limit $n8 $n13 50
$ns simplex-link $n9 $n14 100.0Mb 10ms SFQ
$ns queue-limit $n9 $n14 50
$ns simplex-link $n10 $n15 100.0Mb 10ms CBQ
$ns queue-limit $n10 $n15 50

#Give node position (for NAM)
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n6 orient right
$ns duplex-link-op $n6 $n7 orient right
$ns duplex-link-op $n7 $n8 orient right
$ns duplex-link-op $n8 $n9 orient right
$ns duplex-link-op $n9 $n10 orient right
$ns simplex-link-op $n2 $n11 orient right
$ns simplex-link-op $n11 $n12 orient right
$ns simplex-link-op $n12 $n13 orient right
$ns simplex-link-op $n14 $n13 orient left

$ns simplex-link-op $n15 $n14 orient left

$ns simplex-link-op $n1 $n2 orient left-down
$ns simplex-link-op $n6 $n11 orient right-down
$ns simplex-link-op $n7 $n12 orient right-down
$ns simplex-link-op $n8 $n13 orient right-down
$ns simplex-link-op $n9 $n14 orient right-down
$ns simplex-link-op $n10 $n15 orient right-down

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
