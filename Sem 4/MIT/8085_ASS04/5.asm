;Split 8 bit HEX data into two nibbles and store it in memory
;Program5
mvi a,9Fh
mov b,a
ani 0F0h
rrc
rrc
rrc
rrc
sta 3000h
mov a,b
ani 0Fh
sta 3001h
hlt