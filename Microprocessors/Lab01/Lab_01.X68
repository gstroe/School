*---------------------------------------------------------------------------------------
* Microprocessors Lab - EEE 3231 - Spring 2016
* Exercise: Experiment 1
* Description : Introduction to the Assembly Program Development Procedure
* Written by : <Your name here>
* Date : <Today's date here>
*---------------------------------------------------------------------------------------
* Constant Definitions
ORWELL      equ     1984            ; Numeric constant (No prefix: Decimal)

* Data Definitions
            org     $1000           ; Starting address
            dcb.b   16,0            ; Initial memory clean-up

            org     $1000           ; Reset Location Counter to starting address
bMyByte     dc.b    %1001           ; Byte definition ('%': Binary)
wMyWord     dc.w    ORWELL          ; Word definition (Uses constant)
lMyLong     dc.l    $5043F840       ; Long definition ('$': Hexadecimal)
lMyResult   ds.l    1               ; Definition of one uninitialized long

* Program Code
Start       move.l  #@370,d0        ; Initialize D0 ('@': Octal)
            add.b   bMyByte,d0      ; Add bytes (upper 3 bytes unchanged)
            clr.l   d1              ; Clear entire D1 register
            move.w  wMyWord,d1      ; Load wMyWord to D1
            add.l   lMyLong,d1      ; Add longs (all 4 bytes involved)
            subq.w  #1,d1           ; Decrement lower 2 bytes of D1
            lea     lMyResult,a0    ; Pointer to lMyResult long variable
            move.l  d1,(a0)         ; Store result in lMyResult
            stop    #$2700          ; Terminate program (simpler version)
            end     Start           ; Start execution at label "Start"


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
