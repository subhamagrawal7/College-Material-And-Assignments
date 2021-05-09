;Program2
;save the bytes that are higher than 60 and lower
;than 100 in memory locations starting from 2060H.
lxi h,2050h
mvi c,0Ah
lxi d,2060h
loop: mov a,m
cpi 3Ch
jc next
cpi 64h
jnc next
stax d
inx d
next: inx h
dcr c
jz end
jmp loop
end: hlt
