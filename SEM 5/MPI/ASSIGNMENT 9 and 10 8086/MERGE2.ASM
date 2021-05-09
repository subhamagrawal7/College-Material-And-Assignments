dosseg
model small
.8086
.stack 100h

.data
cr equ 0ah
lf equ 0dh
msg1 db "Enter the first string: $"
msg2 db cr,lf,"Enter the second string: $"
msg3 db cr,lf,"Merged String: $"
str1 db 99
	 db 100 dup('$')
str2 db 99
	 db 100 dup('$')
str3 db 199
	 db 200 dup('$')

.code
start:
mov ax,@data
mov ds,ax

mov ah,09h
lea dx,msg1
int 21h

mov ah,0ah
lea dx,str1
int 21h

mov ah,09h
lea dx,msg2
int 21h

mov ah,0ah
lea dx,str2
int 21h

mov ah,09h
lea dx,msg3
int 21h

lea bx,str1
mov al,[bx]
lea si,str3
mov [si],al
inc bx
inc si
mov al,[bx]
mov [si],al

lea bx,str1+2
lea si,str3+1
label1:	mov al,[bx]
		cmp al,'$'
		jz skip
		mov [si],al
		inc bx
		inc si
		jmp label1
skip:	lea bx,str2+2
		dec si
label2:	mov al,[bx]
		cmp al,'$'
		jz skip2
		mov [si],al
		inc bx
		inc si
		jmp label2
	
skip2:	mov ah,09h
		lea dx,str3+1
		int 21h
		
mov ax,4c00h
int 21h
end start