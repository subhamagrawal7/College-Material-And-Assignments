;Factorial of a given number using Call and Subroutine.
;Program4
lhld 3000h
mvi d,0
mvi e,0
xchg
mov b,e
start: dcr b
mov a,b
cpi 01
jz end
mov c,b
call factorial
mov d,h
mov e,l
mov b,c
mvi h,0
mvi l,0
jmp start
end: xchg
shld 3002h
hlt

factorial: dad d
dcr b
jz rt
call factorial
rt: ret