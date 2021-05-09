;transfer the block of data in reverse order 
lxi h,3045h
lxi d,304Ah
call reverse
hlt

reverse: mov b,m
xchg
mov c,m
mov m,b
xchg
mov m,c
inx h
dcx d
stc 
cmc
mov a,e
sub l
rz
rc
jmp reverse