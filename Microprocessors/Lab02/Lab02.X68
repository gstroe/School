*---------------------------------------------------------------------------------------
* Program Number: EEE3231 Experiment 2
* Description : Introduction to Advanced Debug Features (Bubble Sort)
* Written by : <Your name here>
* Date : <Today's date here>
*---------------------------------------------------------------------------------------
* Constant Definitions
NUMVALS equ 16                  ; Number of values to be sorted
INITCNT equ NUMVALS-2           ; Initial value of countdown
* Data Definitions
            org $1000           ; Starting address
vubSort dc.b 254,52,15,202,9,171,37,186,63,190,86,141,186,8,141,1
                                ; Unsigned byte vector to be sorted
* Program Code
BubSort     move.w #INITCNT,d0  ; Sweep Loop countdown
SweepLp     lea vubSort,a0      ; Running pointer: beginning of vector
            move.w d0,d1        ; Swap Loop countdown
SwapLp      move.b (a0)+,d2     ; Fetch element & move pointer
            cmp.b (a0),d2       ; Compare elements
            bls NoSwap          ; Preceding <= current: no swap!
            move.b (a0),-1(a0)  ; Bump current element 1 position down
            move.b d2,(a0)      ; Preceding elt. to current position
NoSwap      dbf d1,SwapLp       ; Next Swap Loop iteration
            dbf d0,SweepLp      ; Next Sweep Loop iteration
            stop #$2700         ; Terminate program (simpler version)
    end     BubSort             ; Start execution at label "BubSort" 

*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
