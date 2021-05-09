class mom 
mom int proc greet{
$self inst var age
puts "$age years old man says how are you?"
}
class kid-superclass mom
kid inst proc greent{
$self int var age
puts "large old kid says i am fine "
}
set a [new mom]
$a set age 50
set b [new kid]
$b set age 16
$a greet
$b greet













#example.tcl       (ANSWERS)
#50 years old man says how are you
#16 old kid says i am fine