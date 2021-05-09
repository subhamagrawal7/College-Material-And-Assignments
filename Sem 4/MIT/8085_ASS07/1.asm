;Program 1
;save the bytes in the range of 30H to 39H (both inclusive) in memory
; the end of the string is indicated by the byte 0DH.
lxi h,2070H
lxi d,2090H
next: mov a,m
inx H
cpi 0DH
jz END
cpi 030H
jc next
cpi 039H
jnc next
stax D
inx D
jmp next
END: hlt