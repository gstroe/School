*-----------------------------------------------------------
* Title      : Lab 4
* Written by : Mostapha Baydoun - Gabe Stroe
* Date       : 2/11/2016
* Description:  
*-----------------------------------------------------------
        ORG    $3000
START:                  ; first instruction of program
        LEA     TBL1,A0
        LEA     TBL2,A1
        MOVE.W  #63,D1
* Put program code here
LOOP    MOVE.W  (A0)+,(A1)+
        SUB.W   #2,D1
        CMP.B   #0,D1
        BGE     LOOP
        SIMHALT             ; halt simulator

* Put variables and constants here
        ORG     $1000
TBL1    DC.B    'Everything should be made as simple as possible, but not simpler. (Albert Einstein)',0
        ORG     $1080
TBL2    DCB.B   64,0   
        END    START        ; last line of source


*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
