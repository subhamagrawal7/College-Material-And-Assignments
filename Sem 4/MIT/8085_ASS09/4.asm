;Program4
;To Convert 8 Bit BCD Number To Its Respective ASCII Code.
lda 2000h
mvi b,00h
mvi c,00h
call bintobcd
adi 30h ;add 48 in decimal 
sta 2001h
mov a,c
adi 30h ;add 48 in decimal 
sta 2002h
mov a,b
adi 30h ;add 48 in decimal 
cpi 30h
jz end
sta 2003h
end: hlt

bintobcd: cpi 64h
jc s1
inr b
sui 64h
jmp bintobcd

s1: cpi 0Ah
jc exit
inr c
sui 0Ah
jmp s1
exit: ret

