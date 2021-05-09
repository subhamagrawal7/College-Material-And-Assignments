;Program7
;Larger value is stored in 2000h
mvi b,02h
mvi c,05h
mov a,b
cmp c
jnc noCarry
mov a,c
noCarry: sta 2000h
hlt
