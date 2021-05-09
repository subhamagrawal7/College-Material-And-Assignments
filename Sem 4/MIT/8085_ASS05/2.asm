;Program2
;find smallest/largest number from the array 
mvi c,07h
lxi h,3000h
mov a,m
call largest
sta 3008h
mvi c,07h
lxi h,3000h
mov a,m
call smallest
sta 3009h
hlt


largest: inx h
cmp m
jnc noCarry
mov a,m
noCarry: dcr c
jz zero
call largest 
zero: ret

smallest: inx h
cmp m
jc Carry
mov a,m
Carry: dcr c
jz zer
call smallest
zer: ret

