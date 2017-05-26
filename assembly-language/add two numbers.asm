
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
.model small

.data
value1 db 2
value2 db 10

.code
main proc
    .startup
    
     mov al, value1
     add al, value2
     
     aam
     
     add ax, 3030h
    
     mov dh, al
     mov dl, ah
     
     mov ah, 02h
     int 21h
     
     mov dl, dh
     
     mov ah, 02h
     int 21h
    
          
    
endp
end main

ret




