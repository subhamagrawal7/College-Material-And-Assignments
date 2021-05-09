dosseg
model small
.8086
.stack 100H

.data
cr equ 0ah
lf equ 0dh
arr1 db 05h,04h,07h,08h,01h
msg1 db "The largest number is: $"
msg2 db cr,lf,"The smallest number is: $"

.code
start:
mov ax,@data
mov ds,ax

lea si,arr1
mov al,00h    ;for highest number
mov cx,0005h

label1:	cmp al,[si]
		jnc skip
		mov al,[si]
skip:	inc si
		dec cx
		jnz label1

mov ah,09h
lea dx,msg1
int 21h

call print

lea si,arr1
mov al,0ffh  ;for smallest number
mov cx,0005h

label2: cmp al,[si]
		jc skip3
		mov al,[si]
skip3:	inc si
		dec cx
		jnz label2

mov ah,09h
lea dx,msg2
int 21h
	
call print

mov ax,4c00h
int 21h

print PROC
;mov ch,02h
mov cl,04h
mov bl,al
mov dl,al
rol dl,cl
and dl,0fh
cmp dl,09
jz skip2
jc skip2
add dl,07
skip2:	add dl,30h
		mov ah,02h
		int 21h
mov dl,bl
and dl,0fh
cmp dl,09
jz skip4
jc skip4
add dl,07
skip4:	add dl,30h
		mov ah,02h
		int 21h
ret
print ENDP

end start