dosseg
model small
.8086
.stack 100H
.data
arr1 db 04h,03h,01h,02h,05h

.code
start:
mov ax,@data
mov ds,ax

mov ch,04h  ;outer loop count
back2:	lea si,arr1
		mov cl,04h  ;inner loop count
		back1:	mov al,[si]
				mov bl,[si+1]
				cmp al,bl
				jz skip
				jc skip
				mov [si+1],al
				mov [si],bl
				skip:	inc si
						dec cl
						jnz back1
				
				dec ch
				jnz back2

mov ch,05h
lea si,arr1
disp:	mov dl,[si]
		add dl,30h
		mov ah,02h
		int 21h
                ;mov dl,0dh
                ;mov ah,02h
                ;int 21h
		inc si
		dec ch
		jnz disp
		
mov ax,4c00h
int 21h
end start
		
