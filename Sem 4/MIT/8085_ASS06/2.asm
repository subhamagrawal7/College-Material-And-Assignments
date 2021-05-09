;square of the given numbers from memory
lxi h,6100h
lxi d,7000h
call square
hlt

square: mvi a,00h
mov c,m
mov b,m
rep: add c
dcr b
jnz rep
stax d
inx d
inx h
mov a,e
cpi 05h
rz
jmp square