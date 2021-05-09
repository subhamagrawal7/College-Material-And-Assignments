;Multiplication of Two 8-Bit Numbers using Call and Subroutine
lda 3000h
mov b,a
lda 3001h
mov c,a
call multiply
sta 3002h
hlt

multiply: dcr b
jz rt
add c
jmp multiply
rt: ret