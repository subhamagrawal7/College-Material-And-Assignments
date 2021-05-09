;Fibonacci Series using Call and Subroutine
mvi b,01h
mvi c,01h
mvi d,00h
lda 3000h
lxi h,3001h
mvi m,01h
dcr a
jz end
inx h
mvi m,01h
dcr a
jz end
mov e,a
call fibonacci
end: hlt

fibonacci: mov a,b
mov b,c
add c
mov c,a
inx h
mov m,a
dcr e
jz rt
call fibonacci
rt: ret
