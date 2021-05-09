;Program1 - ”Microprocessor And Interface”
;Count Occurrences Of Each Character In Given String: Ended With ‘0dh’
;Output Is Displayed From Memory Location 2000
LXI H,1000H
LOOP: MOV A,M
CALL ASCII
MOV A,M
INX H
CPI 0DH
JNZ LOOP
hlt

ASCII: CPI 41H 	;ASCII OF A=65 =41H
RC 		;IF WHITE SPACE I.E. ASCII=32 IS ENCOUNTERED 		
                ;THEN 02H-41H < 0 => C=1 & RETURN
SUI 41H
JMP STORE
RET

STORE: LXI D,2000H
MOV E,A
LDAX D
INR A
STAX D
RET
