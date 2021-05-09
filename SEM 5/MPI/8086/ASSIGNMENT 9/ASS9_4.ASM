dosseg
.model small
.8086

.data
num1 dw 0011h
num2 db 00h
quo db 00h
rem db 00h
msg db "Divisor is zero$"
.code
start:
mov ax,@data
mov ds,ax

mov al,num2
or al,al
jnz next
mov ah,09h
lea dx,msg
int 21h
jmp last

next:
mov ax, num1
div num2

mov quo,al
mov rem,ah

last:
int 03h
end start

