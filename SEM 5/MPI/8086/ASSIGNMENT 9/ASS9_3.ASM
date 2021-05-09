dosseg
.model small
.8086

.data
num1 dw 0100h
num2 dw 0100h

.code
start:
mov ax,@data
mov ds,ax

mov ax,num1
mul num2

int 03h
end start
