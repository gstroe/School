*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
X EQU $950
Y EQU $954
Z EQU $958

*   EXCEPTIONS
    ORG $14
    DC.L $00000700
    ORG $1C
    DC.L $00000800
    
    
    ;DIVIDE BY ZERO
    ORG $700
    MOVE.B  #13,D0
    MOVEA   #$550,A1
    TRAP    #15
    RTE
    
    ; OVERFLOW
    ORG $750
VTRAP
    MOVE.B  #13,D0
    MOVEA   #$500,A1
    TRAP    #15
    RTS    
    
    ;COVERSION OVERFLOW
    ORG $800
    MOVE.B  #13,D0
    MOVEA   #$600,A1
    TRAP    #15
    RTE
    
    org     $500
    DC.B    'Error! Overflow Detected. Answer may be incorrect!',0
    org     $550
    DC.B    'Error! Divide by Zero Detected. Answer may be incorrect!',0
    org     $600
    DC.B    'Error! Conversion Overflow Detected. Answer may be incorrect!',0
    
*   Variables
    ORG     $0950
    DS.L    1   ; FOR X
    DS.L    1   ; FOR Y
    DS.L    1   ; FOR Z

    ORG     $1000
    ds.l    1   ; 1000 Storage for f
    ds.l    1   ; 1004 Storage for g
    ds.l    1   ; 1008 Storage for h
    
    ORG     $1300
    DC.B    '',0
    ORG     $1400
    DC.B    'PLEASE ENTER X: ',0
    ORG     $1500
    DC.B    'PLEASE ENTER Y: ',0
    ORG     $1600
    DC.B    'PLEASE ENTER Z: ',0
    ORG     $1700
    DC.B    'THE VALUE OF F = ',0
    ORG     $1800
    DC.B    'THE VALUE OF G = ',0
    ORG     $1900
    DC.B    'THE VALUE OF H = ',0
    
    
    
    org     $2000
START:                  ; first instruction of program
* Program Starts below
    
    *PROMPT USER FOR X
    MOVE.B  #14,D0
    MOVEA   #$1400,A1
    TRAP    #15
    MOVE.B  #4,D0             
    TRAP    #15
    MOVE.L  D1, $950

    *PROMPT USER FOR Y
    MOVE.B  #14,D0
    MOVEA   #$1500,A1
    TRAP    #15
    MOVE.B  #4,D0             
    TRAP    #15
    MOVE.L  D1, $954

    *PROMPT USER FOR Z
    MOVE.B  #14,D0
    MOVEA   #$1600,A1
    TRAP    #15
    MOVE.B  #4,D0             
    TRAP    #15
    MOVE.L  D1, $958    
    
    * Math stuff
    * FOR F  
    MOVE.L  X,D7
    MOVE.L  Z,D4
    MOVE.L  Y,D5 
    MULS    D4,D7
    DIVS    #3,D7
    TRAPV
    AND.L   #$0000FFFF,D7
    MOVE.L  #100,D6
    MULS    D5,D6
    MULS    D4,D6
    SUB.L   D6,D7
    MOVE.L  D7,$1000
    CLR     D7
    CLR     D6
    CLR     D5
    CLR     D4
    
    * FOR G
    MOVE.L  X,D7
    MOVE.L  Z,D4
    MOVE.L  Y,D5 
    DIVS    #10,D7
    TRAPV
    AND.L   #$0000FFFF,D7
    MOVE.L  D4,D6
    MULS    #200,D6
;    MOVE.L #$FFFFFFFF,D7
    ADD.L   D6,D7
    BCC NEXT
    BSR VTRAP
NEXT
    DIVS    D5,D7
    TRAPV
    AND.L   #$0000FFFF,D7
    MOVE.L  D7,$1004
    CLR     D7
    CLR     D6
    CLR     D5
    CLR     D4
    
    * FOR H
    MOVE.L  X,D4
    MOVE.L  $1004,D7
    MULS    #3,D7
    SUB.L   #4,D7
    MULS    D4,D7
    MOVE.L  D7,$1008
    
    *PRINT F
    MOVE.B  #14,D0
    MOVEA   #$1700,A1
    TRAP    #15
    MOVE.B  #3,D0
    MOVE.L  ($1000),D1
    TRAP    #15
    MOVE.B  #13,D0
    MOVEA   #$1300,A1
    TRAP    #15
    
    *PRINT G
    MOVE.B  #14,D0
    MOVEA   #$1800,A1
    TRAP    #15
    MOVE.B  #3,D0
    MOVE.L  ($1004),D1
    TRAP    #15
    MOVE.B  #13,D0
    MOVEA   #$1300,A1
    TRAP    #15
        
    *PRINT H
    MOVE.B  #14,D0
    MOVEA   #$1900,A1
    TRAP    #15
    MOVE.B  #3,D0
    MOVE.L  ($1008),D1
    TRAP    #15
    MOVE.B  #13,D0
    MOVEA   #$1300,A1
    TRAP    #15
   

* Put program code here

    SIMHALT             ; halt simulator

* Put variables and constants here

    END    START        ; last line of source





*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
