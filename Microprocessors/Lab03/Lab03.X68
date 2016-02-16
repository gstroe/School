*---------------------------------------------------------------------------------------
* Program Number: EEE3231 Experiment 3
* Description : Understanding the Addressing Modes
* Written by : <Your name here>
* Date : <Today's date here>
*---------------------------------------------------------------------------------------
* Data Definitions
    org $1000
    dc.b 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
* Program Code
Start 
    moveq   #-2,d0
    movea.l #$1000,a0
    move.l  #-65533,d1
    adda.w  d1,a0
    move.b  (a0)+,d2
    add.b   d2,d0
    move.l  d0,5(a0,d1.w)
    move.w  d0,d2
    sub.l   d2,d0
    neg.w   $1006
    move.l  d2,-(a0)
    stop    #$2700
    
    end     Start 
*~Font name~Courier New~
*~Font size~10~
*~Tab type~1~
*~Tab size~4~
