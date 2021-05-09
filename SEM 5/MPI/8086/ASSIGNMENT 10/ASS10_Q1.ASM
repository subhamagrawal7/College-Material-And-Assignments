dosseg
.model small
.8086
.stack 100H

.data
cr equ 0ah
lf equ 0dh
arr1 dw 1000h,2000h,3000h,0010h,0002h
sum1 dw 0000h
carry db 00h
msg1 db "The sum is: $"
msg2 db cr,lf,"The carry is: $"

.code
start:
mov ax,@data
mov ds,ax

lea si,arr1
mov cx,0005h
label1:	mov ax,[si]
		add ax,sum1
		mov sum1,ax
		jnc skip2
		inc carry
skip2:	inc si
		inc si      ;for 16bit addition increment si 2 times
		loop label1
		
mov ah,09h
lea dx,msg1
int 21h

mov bx,sum1
mov ch,04h
mov cl,04h
disp:	rol bx,cl
		mov dl,bl
		and dl,0fh
		cmp dl,09
		jz skip
		jc skip
		add dl,07
		skip:	add dl,30h
				mov ah,02h
				int 21h
				dec ch
				jnz disp



mov ax,4c00h
int 21h
end start