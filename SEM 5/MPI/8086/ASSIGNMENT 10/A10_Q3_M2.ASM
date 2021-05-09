dosseg
.model small
.8086
.stack 100H

.data
cr equ 0ah
lf equ 0dh
arr1 db 05h,12h,2Eh,3Eh,01h
larg_ db ?
;msg1 db "The largest Number is: $"
cd db cr,lf,"$"
;msg2 db cr,lf,"The smallest Number is: $"

.code
start:
mov ax,@data
mov ds,ax

mov ch,04h
up2:	mov cl,04h
lea si,arr1
up1:	mov al,[si]
mov ah,[si+1]
cmp al,ah
jc skip
je skip
mov [si+1],al
mov [si],ah
skip:	inc si
dec cl
jnz up1
dec ch
jnz up2

print macro var
mov dl,var
mov bl,var
mov cl,04h
rol dl,cl
and dl,0fh
cmp dl,9
jc skip2
je skip2
add dl,07h
skip2:  add dl,30h
        mov ah,02h
        int 21h

mov dl,bl
and dl,0fh
cmp dl,9
jc skip3
je skip3
add dl,07h
skip3:  add dl,30h
        mov ah,02h
        int 21h
endm

mov cx,0005h
lea si,arr1
label2:	push cx
		print [si]
		mov ah,02h
		mov dl,cd
		int 21h
		inc si
		pop cx
		loop label2

mov ax,4c00h
int 21h
end start
