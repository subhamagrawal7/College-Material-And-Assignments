;Program 2
;shift the data string by five memory locations
lxi h,205FH
lxi d,2064H
mvi b,16H

loop: mov a,m
stax d
dcx h
dcx d
dcr b
jnz loop

lxi h,2050h
mvi c,05h
mvi b,01h
addNo: mov m,b
inx h
inr b
dcr c
jnz addNo
hlt