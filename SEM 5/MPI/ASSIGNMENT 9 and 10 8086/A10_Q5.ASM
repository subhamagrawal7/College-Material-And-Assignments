dosseg
model small
.8086
.stack 100h
.data
cr equ 0ah
lf equ 0dh
msg1 db "Enter the string:$"
msg2 db cr,lf,"The reverse of the string is:$"
string db 	99
	   db 	100 dup('$')
copy db 	99
	 db 	100 dup('$')
	   
.code
start:
mov ax,@data
mov ds,ax

mov ah,09h
lea dx,msg1
int 21h

mov ah,0ah
lea dx,string
int 21h

mov ah,09h
lea dx,msg2
int 21h

lea bx,string
mov al,[bx]
lea si,copy
mov [si],al
inc si
inc bx
mov al,[bx]
mov [si],al

call reverse

mov ah,09h
lea dx,copy+2
int 21h

mov ax,4c00h
int 21h

reverse PROC
	lea bx,string+2
	mov cx,0000h
	xor ah,ah
	label1:	mov al,[bx]
			cmp al,'$'
			jz label2
			push ax
			inc bx
			inc cx
			jmp label1
			
	label2: lea bx,copy+1
	
	label3: cmp cx,0000h
			jz label4
			pop ax
			mov [bx],al
			inc bx
			dec cx
			jmp label3
			
	label4: ret
reverse ENDP
end start
