dosseg
model small
.8086
.stack 100h
.data
cr equ 0ah
lf equ 0dh
a dw 0048
b dw 0024
c dw ?
msg2 db "The GCD is: $"
msg1 db cr,lf,"The LCM is: $"

.code
start:
mov ax,@data
mov ds,ax
mov ax,a
mov bx,b
CALL gcd

mov ah,09h
lea dx,msg2
int 21h

mov ax,cx
mov c,cx
mov bx,ax
mov ch,04h
mov cl,04h
disp:	rol bx,cl
		mov dl,bl
		and dl,0fh
		cmp dl,09
		jz skip
		jc skip
		add dl,07
		skip:	add dl,30h
				mov ah,02h
				int 21h
				dec ch
				jnz disp

mov ah,09h
lea dx,msg1
int 21h

mov ax,a
mov bx,b
mul bx
mov bx,c
div bx

mov bx,ax
mov ch,04h
mov cl,04h
disp2:	rol bx,cl
		mov dl,bl
		and dl,0fh
		cmp dl,09
		jz skip2
		jc skip2
		add dl,07
		skip2:	add dl,30h
				mov ah,02h
				int 21h
				dec ch
				jnz disp2

mov ax,4c00h
int 21h

gcd PROC
	cmp bx,0
	jnz continue
	mov cx,ax
	ret
	continue:	mov dx,0
				div bx
				mov ax,bx
				mov bx,dx
	CALL gcd
	ret
gcd ENDP
end start
