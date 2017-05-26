
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
.model small

.data
number db 2

.code
main proc
    .startup
     mov CL, 1
     ;mov AL, number
     
table:

    

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
     
     INC CL
      
     CMP CL, 11
     JNE table
     
          
    
endp
end main

ret