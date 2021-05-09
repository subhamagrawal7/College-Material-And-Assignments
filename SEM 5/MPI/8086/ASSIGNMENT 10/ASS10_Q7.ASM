dosseg
.model small
.8086
.stack 100H

data segment 
cr equ 0ah
lf equ 0dh
msg1 db "Enter string1: $"
msg2 db cr,lf,"Enter string2: $"
msg3 db cr,lf,"Merged string: $"
str1 db 09 dup('$')
str2 db 09 dup('$')
data ends

extra segment 
str3 db 20 dup('$')
extra ends

code segment
Assume cs:code,ds:data,es:extra
start:
mov ax,data
mov ds,ax
mov ax,extra
mov es,ax

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

call merge

mov ax,extra
mov ds,ax
mov ah,09h
lea dx,str3
int 21h

mov ax,4c00h
int 21h

merge PROC
	lea si,str1+2
	lea di,str3
	mov cx,0005h
	rep movsb
	lea si,str2+2
	mov cx,0005h
	rep movsb
	ret
merge ENDP
code ends
end start