dosseg
.model small
.8086

.data
num1 db 10h
num2 db 12h
sum db 00h
carry db 00h
diff db 00h
borr db 00h
.code
start:
mov ax,@data
mov ds,ax

mov al,num1
add al,num2
jnc skip
inc carry
skip: mov sum,al

mov al,num1
sub al,num2
jnc skip1
inc borr
skip1: mov diff,al


int 03h
end start

