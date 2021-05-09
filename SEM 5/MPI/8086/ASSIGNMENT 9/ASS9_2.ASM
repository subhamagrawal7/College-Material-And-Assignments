dosseg
.model small
.8086

.data
num1 dw 1020h
num2 dw 1081h
sum dw 0000h
carry dw 0000h
diff dw 0000h
borrow dw 0000h

.code
start:
mov ax,@data
mov ds,ax

mov ax,num1
add ax,num2
jnc skip1
inc carry
skip1: mov sum,ax

mov ax,num1
sub ax,num2
jnc skip2
inc borrow
skip2: mov diff,ax

mov ax,4c00h
int 21h

end start
