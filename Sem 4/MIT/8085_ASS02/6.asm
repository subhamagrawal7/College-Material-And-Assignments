;Program6
;Data present at 3000h and 3001h
lda 3000h
mov e,a
mvi d,00h
lda 3001h
mov c,a
lxi h,0000h
loop: dad d
dcr c
jnz loop
shld 3002h
hlt