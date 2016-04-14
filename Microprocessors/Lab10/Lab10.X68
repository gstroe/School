*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
    ORG     $500
    DS.L    1    

    ORG     $1000
START:                  ; first instruction of program



waitTemp
    MOVE.B #$00, $E00010
    MOVE.W #8, D0
    TRAP #15
    MOVE.L D1,$500
   
waitLoop
    MOVE.W #8, D0
    TRAP #15
    MOVE.L $500,D2
    SUB.L D2,D1
    DIVU #100, D1
EIGHT
    CMP.W #8,D1
    BLT SEVEN
    MOVE.B #$FF, $E00010
    BRA waitLoop
SEVEN
    CMP.W #7,D1
    BLT SIX
    MOVE.B #$7F, $E00010
    BRA waitLoop
SIX
    CMP.W #6,D1
    BLT FIVE
    MOVE.B #$3F, $E00010
    BRA waitLoop
FIVE
    CMP.W #5,D1
    BLT FOUR
    MOVE.B #$1F, $E00010
    BRA waitLoop
FOUR
    CMP.W #4,D1
    BLT THREE
    MOVE.B #$0F, $E00010
    BRA waitLoop
THREE
    CMP.W #3,D1
    BLT TWO
    MOVE.B #$07, $E00010
    BRA waitLoop
TWO
    CMP.W #2,D1
    BLT ONE
    MOVE.B #$03, $E00010
    BRA waitLoop
ONE
    CMP.W #1,D1
    BLT ZERO
    MOVE.B #$01, $E00010
    BRA waitLoop
ZERO
    MOVE.B #$00, $E00010
    BRA waitLoop

    SIMHALT             ; halt simulator

* Put variables and constants here

    END    START        ; last line of source

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
