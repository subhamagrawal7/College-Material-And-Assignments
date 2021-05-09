;Program3
;Data present at 3003h,3004h,3005h – 3,4,5 (all in decimal) respectively
lda 3003h
mov b,a
lda 3004h
mov c,a
lda 3005h
mov e,a
; AND Operation
ana c
ana b
sta 3000h
; OR Operation
mov a,e
ora c
ora b
sta 3001h
; XOR Operation
mov a,e
xra c
xra b
sta 3002h
hlt