;Program6
mvi b,42h
mvi c,69h
mov a,b
cmp c
jc isNegative
sub c
jmp exit
isNegative: sub c
cma
adi 01h
exit: out 01h
hlt