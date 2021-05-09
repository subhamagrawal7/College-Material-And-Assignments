;Program3: To Subtract Two 8 Bit BCD Numbers
lda 2051h
mov b,a
mvi a,99h
sub b
inr a
mov c,a
lda 2050h
add c
daa
sta 2052h
hlt


