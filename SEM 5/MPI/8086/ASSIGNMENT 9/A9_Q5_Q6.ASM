dosseg
.model small
.8086
.stack 100H

.data
cr equ 0ah
lf equ 0dh
a db 24
b db 48
gcd_ db ?
lcm_ db ?
msg1 db "The GCD is: $"
msg2 db cr,lf,"The LCM is: $"

.code
start:
mov ax,@data
mov ds,ax

mov ah,a
mov al,b
cmp ah,al
jc label1
xchg ah,al

label1:	call gcd_no

mov ah,09h
lea dx,msg1
int 21h

print macro var
mov dl,var
mov bl,var
mov cl,04h
rol dl,cl
and dl,0fh
mov ah,02h
add dl,30h
int 21h

mov dl,bl
and dl,0fh
mov ah,02h
add dl,30h
int 21h
endm


print gcd_


call lcm_no

mov ah,09h
lea dx,msg2
int 21h

print lcm_

mov ax,4c00h
int 21h

gcd_no PROC
	or ah,ah
	jz skip1
	up1:	mov dx,ax
			mov ah,00h
			div dh
			mov al,dh
			or ah,ah
			jnz up1
	skip1:	mov gcd_,al
	ret
gcd_no ENDP

lcm_no PROC
	mov al,a
	mul b
	div gcd_
	mov lcm_,al
	ret
lcm_no ENDP
end start
