;Program 1
;Adding numbers from 3000h to 3007h
lxi h,3000h
mvi c,08h
mvi a,00h
mvi d,00h
loop: add m
inx h
jnc noCarry
inr d
noCarry: dcr c
jnz loop
mov e,a
xchg
shld 3008h
hlt