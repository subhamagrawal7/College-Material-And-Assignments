;Program4
stc
cmc
mvi b,0FFh
inr b
jnc carryZero
mvi b,01h
carryZero: mov a,b
out 01h
hlt