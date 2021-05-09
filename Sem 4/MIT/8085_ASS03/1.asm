;Program1
;Masking higher order bits
mvi c,0A8h
mov a,c
ani 0Fh
sta 3000h
hlt