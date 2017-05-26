
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h
.model small

.data
number db ?
msg1 db 'Press 1 if you want to add two numbers. $'
msg2 db 'Press 3 if you want to print a table. $'
msg7 db 'Press 2 if you want to multiply two number. $'
msg3 db 'Enter the First Number: $'
msg4 db 'Enter the Second Number: $'
msg5 db 'The sum of two numbers is: $'
msg6 db 'The multiplication of two numbers is: $'
msg8 db 'Please Enter a valid input: $'
firstNumber db ?
secondNumber db ?  

.code
main proc
    .startup

manu:  
        MOV AX, @DATA           ; initialize DS
        MOV DS, AX 
        
        LEA DX, msg1            ; load & display the msg1  
        MOV AH, 9            
        INT 21H 
        
        MOV dl, 10              ; for new line
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13              ; for algn
        MOV ah, 02h
        INT 21h
        
        LEA DX, msg7            ; load & display the msg7  
        MOV AH, 9            
        INT 21H
        
        MOV dl, 10              ; for new line
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13              ; for algn
        MOV ah, 02h
        INT 21h
        
        LEA DX, msg2            ; load & display the msg2  
        MOV AH, 9            
        INT 21H
        
        mov ah, 1h              ; keyboard input subprogram
        int 21h                 ; read character into al
        sub al,48
        
        CMP AL,1
        JZ call addTwoNumbers 
        
        CMP AL,2
        JZ call multiplyTwoNumbers
        
        CMP AL,3
        JZ call printTable
        
                
        MOV dl, 10              ; for new line
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13              ; for algn
        MOV ah, 02h
        INT 21h        
        
        MOV dl, 10              ; for new line
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13              ; for algn
        MOV ah, 02h
        INT 21h 
        
        LEA DX, msg8            ; load & display the msg7  
        MOV AH, 9            
        INT 21H
        
        MOV dl, 10              ; for new line
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13              ; for algn
        MOV ah, 02h
        INT 21h
        JMP manu
                     
endp
ret
        
        
printTable proc
     MOV dl, 10 ; for line break
     MOV ah, 02h
     INT 21h
     
     MOV dl, 13 ; for left align
     MOV ah, 02h
     INT 21h
     
     
     MOV CL, 1
     
     mov ah, 1h ; keyboard input subprogram
     int 21h ; read character into al
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
     
     AAM ;ASCII Adjust after Multiplication.
         ;Corrects the result of multiplication of two BCD values. 
     
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
ret
endp

addTwoNumbers proc
        MOV dl, 10      ; for line break
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13      ; for left align
        MOV ah, 02h
        INT 21h
             
        LEA DX, msg3    ; load & display the msg3  
        MOV AH, 9            
        INT 21H 
        
        mov ah, 1h      ; keyboard input subprogram
        int 21h         ; read character into al
        sub al,48
        mov firstNumber, AL
     
        MOV dl, 10      ; for line break
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13      ; for left align
        MOV ah, 02h
        INT 21h
        
        LEA DX, msg4    ; load & display the msg4  
        MOV AH, 9            
        INT 21H
        
        mov ah, 1h      ; keyboard input subprogram
        int 21h         ; read character into al
        sub al,48
        mov secondNumber, AL
     
        MOV dl, 10      ; for line break
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13      ; for left align
        MOV ah, 02h
        INT 21h
        
        LEA DX, msg5    ; load & display the msg5  
        MOV AH, 9            
        INT 21H
        
        MOV AL, firstNumber
        ADD AL, secondNumber
        
        AAM             ;ASCII Adjust after Multiplication. 
     
        ADD AX, 3030h   ; MANAGE Ah AND Al
        
        MOV DH, AL
     
        MOV DL, AH     
        MOV AH, 02h
        INT 21h
     
        MOV DL, DH     
        MOV AH, 02h
        INT 21h 
ret
endp

multiplyTwoNumbers proc
        MOV dl, 10      ; for line break
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13      ; for left align
        MOV ah, 02h
        INT 21h
             
        LEA DX, msg3    ; load & display the msg3  
        MOV AH, 9            
        INT 21H 
        
        mov ah, 1h      ; keyboard input subprogram
        int 21h         ; read character into al
        sub al,48
        mov firstNumber, AL
     
        MOV dl, 10      ; for line break
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13      ; for left align
        MOV ah, 02h
        INT 21h
        
        LEA DX, msg4    ; load & display the msg4  
        MOV AH, 9            
        INT 21H
        
        mov ah, 1h      ; keyboard input subprogram
        int 21h         ; read character into al
        sub al,48
        mov secondNumber, AL
     
        MOV dl, 10      ; for line break
        MOV ah, 02h
        INT 21h
     
        MOV dl, 13      ; for left align
        MOV ah, 02h
        INT 21h
        
        LEA DX, msg6    ; load & display the msg6  
        MOV AH, 9            
        INT 21H
        
        MOV AL, firstNumber
        MOV BL, secondNumber
        MUL BL
        
        AAM ;ASCII Adjust after Multiplication.
            ;Corrects the result of multiplication of two BCD values. 
     
        ADD AX, 3030h
    
        mov DH, AL
     
        MOV DL, AH     
        MOV AH, 02h
        INT 21h
     
        MOV DL, DH     
        MOV AH, 02h
        INT 21h
ret
endp