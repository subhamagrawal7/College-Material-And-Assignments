;Program2
mvi d,8Eh
mvi e,0F7h
mov a,d
ani 0Fh
xri 0Fh
sta 3000h
mov a,e
ani 0Fh
xri 0Fh
sta 3001h
hlt