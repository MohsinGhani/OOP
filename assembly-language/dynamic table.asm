
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
.model small

.data
number db ?

.code
main proc
    .startup
     mov CL, 1
     ;mov AL, number
     
     mov ah, 1h ; keyboard input subprogram
     int 21h ; read character into al
     ;mov dl, al ; copy character to dl
     ;mov ah, 2h ; character output subprogram
     ;int 21h ; display character in dl
     sub al,48
     mov number, AL
     
     MOV dl, 10 ; for line break
     MOV ah, 02h
     INT 21h
     
     MOV dl, 13 ; for left align
     MOV ah, 02h
     INT 21h
     
table:
     
     MOV AL, number
     ADD AL, 48
     MOV DL, AL     
     MOV AH, 02h
     INT 21h   
     
     MOV DL, ' '     
     MOV AH, 02h
     INT 21h
     
     MOV DL, 'x'     
     MOV AH, 02h
     INT 21h
     
     MOV DL, ' '     
     MOV AH, 02h
     INT 21h
     
     MOV AL, CL
     ADD AL, 48
     MOV DL, AL     
     MOV AH, 02h
     INT 21h  
     
     MOV DL, ' '     
     MOV AH, 02h
     INT 21h
     
     MOV DL, '='     
     MOV AH, 02h
     INT 21h
     
     MOV DL, ' '     
     MOV AH, 02h
     INT 21h
    

     MOV AL, number
     MOV BL, CL
     MUL BL
     
     AAM
     
     ADD AX, 3030h
    
     mov DH, AL
     
     MOV DL, AH     
     MOV AH, 02h
     INT 21h
     
     MOV DL, DH     
     MOV AH, 02h
     INT 21h
     
     MOV DL, ' '     
     MOV AH, 02h
     INT 21h
     
     MOV dl, 10
     MOV ah, 02h
     INT 21h
     
     MOV dl, 13
     MOV ah, 02h
     INT 21h
     
     INC CL
      
     CMP CL, 11
     JNE table
     
          
    
endp
end main

ret