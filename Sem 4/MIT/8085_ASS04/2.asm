;m to swap lower 4 bit nibble with upper 4 bit nibble of 8 bit data 
;Program2
lda 2100h
mov b,a
ani 0F0h
rrc
rrc
rrc
rrc
mov c,a
mov a,b
ani 0Fh
rlc
rlc
rlc
rlc
add c
sta 2101h
hlt