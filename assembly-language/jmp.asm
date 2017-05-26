
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
.stack 100h

.data
myVar db 12h

.code
mov ax, 3h

label:
mov dl,al
mov ah,2
int 21h
jmp label

ret




