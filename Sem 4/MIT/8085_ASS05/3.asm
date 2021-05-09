;Program3
;search an 8-bit number from the array of 8-bit data
lxi h,2000h
lda 2008h
mvi c,08h
mvi b,00h
loop: cmp m
jnz next
mvi b,01h
jmp exit
next: inx h
dcr c
jz exit
jmp loop

exit: mov a,b
sta 2009h
hlt