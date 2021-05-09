 ;Program2: find substring 'sub' from sting 'main'
LXI H,2000H	;main string starting location
LDA 3000H	;substring to find location
MOV B,A		;starting character of substring 
LOOP: MOV A,M	
CMP B
CZ CHECK  
MOV A,M	
INX H
CPI 0DH	
JNZ LOOP
hlt


CHECK:	PUSH H
LXI D,3000H	
REPEAT:	LDAX D		
CMP M		
JNZ NOTEQUAL	
INX D		
INX H
LDAX D	
CPI 0DH
JNZ REPEAT 
POP H
XCHG
INX H
INX H
MOV M,E			
INX H
MOV M,D
HLT


NOTEQUAL: POP H	 
	RET


;Hello World= 72 101 108 108 111 32 87 111 114 108 100
;0d=13
;Wor= 87 111 114
