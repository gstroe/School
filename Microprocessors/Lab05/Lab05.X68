*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
X EQU 10
Y EQU 10
Z EQU 10
    
    
*   Variables
    ORG     $0950
    DS.L    1   ; FOR X
    DS.L    1   ; FOR Y
    DS.L    1   ; FOR Z

    ORG     $1000
    ds.l    1   ; 1000 Storage for f
    ds.l    1   ; 1004 Storage for g
    ds.l    1   ; 1008 Storage for h
    
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
    
    *PROMPT USER
    MOVE.B  #14,D0
    MOVEA   #$1400,A1
    TRAP    #15
    
    
    
    * Math stuff
    * FOR F
    MOVE.W  #X,D7 
    MULS    #Z,D7
    DIVS    #3,D7
    AND.L   #$0000FFFF,D7
    MOVE.L  #100,D6
    MULS    #Y,D6
    MULS    #Z,D6
    SUB.L   D6,D7
    MOVE.L  D7,$1000
    CLR     D7
    CLR     D6
    
    * FOR G
    MOVE.L  #X,D7
    DIVS    #3,D7
    AND.L   #$0000FFFF,D7
    MOVE.L  #Z,D6
    MULS    #200,D6
    ADD.L   D6,D7
    DIVS    #Y,D7
    AND.L   #$0000FFFF,D7
    MOVE.L  D7,$1004
    CLR     D7
    CLR     D6
    
    * FOR H
    MOVE.L  $1004,D7
    MULS    #3,D7
    SUB.L   #4,D7
    MULS    #X,D7
    MOVE.L  D7,$1008
    
    
    
    


* Put program code here

    SIMHALT             ; halt simulator

* Put variables and constants here

    END    START        ; last line of source


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
