*-----------------------------------------------------------
* Title      :
* Written by :
* Date       :
* Description:
*-----------------------------------------------------------
*    -----------------------------------------------------------
*         A
*       -----
*     F|     |B
*      |  G  |
*       -----
*     E|     |C
*      |  D  |
*       -----   .H
*
* Bit Number  7 6 5 4 3 2 1 0
* Segment     H G F E D C B A

* bit patterns to form digits on readout
    ORG 300
DIGITS:
    dc.b  $3F           digit 0
    dc.b  $06           digit 1
    dc.b  $5B           digit 2
    dc.b  $4F           digit 3
    dc.b  $66           digit 4
    dc.b  $6D           digit 5
    dc.b  $7D           digit 6
    dc.b  $07           digit 7
    dc.b  $7F           digit 8
    dc.b  $6F           digit 9
    dc.b  $00           digit off
    dc.b  $40           dash

    ds.w  0             force word boundary

    ORG     $500
    DS.L    1  

    ORG     $600
    DS.L    1  

    ORG     $1000
START:                  ; first instruction of program
    MOVE.B $E00012, D7
    
    * CLEAR THE 7SEG DISPLAY
    MOVE.L #$00000000,$E00000
    MOVE.L #$00000000,$E00002
    MOVE.L #$00000000,$E00004
    MOVE.L #$00000000,$E00006
    MOVE.L #$00000000,$E00008
    MOVE.L #$00000000,$E0000A
    MOVE.L #$00000000,$E0000C
    MOVE.L #$00000000,$E0000E
    
DISPLAY
    CLR.L D4
    CLR.L D5
    CLR.L D6
    MOVE.B D7,D4
    MOVE.B D7,D5
    MOVE.B D7,D6
    DIVU #100,D4
    DIVU #10,D5
    AND.L #$0000FFFF,D5
    DIVU #10,D5
    SWAP D5
    DIVU #10,D6
    SWAP D6
    MOVE.B D4,D3
    MOVE.L #$E0000A,A2
    BSR SEGMENT7
    MOVE.B D5,D3
    MOVE.L #$E0000C,A2
    BSR SEGMENT7
    MOVE.B D6,D3
    MOVE.L #$E0000E,A2
    BSR SEGMENT7

waitTemp
    MOVE.B #$00, $E00010
    MOVE.W #8, D0
    TRAP #15
    MOVE.L D1,$500
   
waitLoop
    MOVE.W #23,D0
    MOVE.L #100,D1
    TRAP #15
    MOVE.W #8, D0
    TRAP #15
    MOVE.L $500,D2
    SUB.L D2,D1
    BRA TICK
    
EIGHT
    AND.L #$0000FFFF,D1
    DIVU #500, D1
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
    
    
SEGMENT7:
    MOVEM.L D3/A0,-(A7)     save registers
    LEA     DIGITS,A0           bit pattern table
    AND.L   #$00ff,D3
    MOVE.B  (A0,D3),(A2)    display digit
    ADDA.L  #2,A2
    MOVEM.L (A7)+,D3/A0     restore registers
    RTS
    
TICK:

    lea	    SOUND,a1
	move	#70,d0
	trap	#15	
	move.l	#0,d0
    CMP.B $E00012,D7
    BEQ OLD
NEW
    MOVE.B $E00012,D7
    BRA DISPLAY
OLD    
    BRA EIGHT

    SIMHALT             ; halt simulator

* Put variables and constants here

SOUND	dc.b	'TICK.wav',0	sound file     

    END    START        ; last line of source




*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
