; program to check the 4th bit of 8-numbers stored from location 2000H.
;Program1
mvi b,8h
lxi h,2000h
lxi d,2008h
loop: mov a,m
ani 10h
rrc
rrc
rrc
rrc
stax d
inx d
inx h
dcr b
mov a,b
jnz loop
hlt