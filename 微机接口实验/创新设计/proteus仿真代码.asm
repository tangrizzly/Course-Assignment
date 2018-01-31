      STACKS  SEGMENT   STACK
              DW        128 DUP(?)
      STACKS  ENDS

       DATAS  SEGMENT
 IO8255_MODE  EQU       0A006H
    IO8255_A  EQU       0A000H
    IO8255_B  EQU       0A002H
    IO8255_C  EQU       0A004H
    IO8253_0  EQU       8000H
    IO8253_1  EQU       8002H
    IO8253_2  EQU       8004H
 IO8253_MODE  EQU       8006H
          UP  DB        0
       LAYER  DB        1
       CHIEF  DB        0
       DATAS  ENDS

        CODE  SEGMENT   PUBLIC 'CODE'
              ASSUME    CS:CODE,DS:DATAS
      START:  MOV       AX,DATAS
              MOV       DS,AX
              MOV       DX,IO8255_MODE
              MOV       AL,8AH
              OUT       DX,AL
              MOV       DX,IO8255_A
              MOV       AL,06H
              OUT       DX,AL
              MOV       DX,IO8255_C
              MOV       AL,00H
              OUT       DX,AL
              OUT       DX,AL

              MOV       DX,IO8253_MODE
              MOV       AL,36H
              OUT       DX,AL
              MOV       DX,IO8253_0
              MOV       AX,1000
              OUT       DX,AL
              MOV       AL,AH
              OUT       DX,AL

        NCF:  MOV       DX,IO8255_C
              IN        AL,DX
              TEST      AL,80H      ;如果是厨师需要，则跳转厨师处理程序部分
              JNZ       TEMP
         T2:  TEST      AL,10H      ;二楼call
              JZ        T3
              CALL      UP2
        ST2:  MOV       DX,IO8255_C
              IN        AL,DX
              TEST      AL,80H      ;检查是不是厨师需要，需要则回一层
              JZ        CK2
              CALL      DOWN2
              JMP       L1IN
        CK2:  TEST      AL,10H      ;二楼是不是用完了,没用完则继续
              JNZ       ST2
              MOV       DX,IO8255_C
              IN        AL,DX
              TEST      AL,20H      ;三层继续call了没
              JNZ       UUP3
              TEST      AL,40H      ;四层继续call了没
              JNZ       UUP24
              CALL      DOWN2
              JMP       NCF
         T3:  TEST      AL,20H      ;三楼call
              JZ        T4
              CALL      UP2
       UUP3:  CALL      UP3
        ST3:  MOV       DX,IO8255_C
              IN        AL,DX
              TEST      AL,80H      ;检查是不是厨师需要，需要则回一层
              JZ        CK3
              CALL      DOWN3
              CALL      DOWN2
       TEMP:  JMP       L1IN
        CK3:  TEST      AL,20H      ;三楼是不是用完了,没用完则继续
              JNZ       ST3
              MOV       DX,IO8255_C
              IN        AL,DX
              TEST      AL,40H      ;四层继续call了没
              JNZ       UUP4
              CALL      DOWN3
              JMP       ST2
         T4:  TEST      AL,40H      ;四楼call
              JZ        REC
              CALL      UP2
      UUP24:  CALL      UP3
       UUP4:  CALL      UP4
        ST4:  MOV       DX,IO8255_C
              IN        AL,DX
              TEST      AL,80H      ;检查是不是厨师需要，需要则回一层
              JZ        CK4
              CALL      DOWN4
              CALL      DOWN3
              CALL      DOWN2
              JMP       L1IN
        CK4:  TEST      AL,40H      ;四楼是不是用完了,没用完则继续
              JNZ       ST4
              MOV       DX,IO8255_C
              IN        AL,DX
              CALL      DOWN4
              JMP       ST3
        REC:  JMP       NCF

       L1IN:  CALL      GETKEY
              CALL      UP2
              TEST      UP,02H      ;0000 0010
              JZ        CUP3
              MOV       LAYER,02H
              CALL      WAITING
              AND       UP,0FDH     ;1111 1101
       CUP3:  AND       UP,0CH
              JE        D2
              CALL      UP3
              TEST      UP,04H
              JZ        CUP4
              MOV       LAYER,04H
              CALL      WAITING
              AND       UP,0FBH     ;1111 1011
       CUP4:  AND       UP,08H
              JZ        D3
              CALL      UP4
              MOV       LAYER,08H
              CALL      WAITING
              AND       UP,0F7H     ;1111 0111
         D4:  CALL      DOWN4
              MOV       LAYER,04H
         D3:  CALL      DOWN3
              MOV       LAYER,02H
         D2:  CALL      DOWN2
              MOV       LAYER,01H
              JMP       NCF

              MOV       AX,4C00H
              INT       21H
    ENDLESS:
              JMP       ENDLESS
     WAITING  PROC
              MOV       DX,IO8253_MODE
              MOV       AL,0B0H
              OUT       DX,AL
              MOV       DX,IO8253_2
              MOV       AX,5000
              OUT       DX,AL
              MOV       AL,AH
              OUT       DX,AL

      STOP1:  MOV       DX,IO8255_B
              IN        AL,DX
              TEST      AL,80H
              JNZ       R
        LL2:  TEST      LAYER,02H
              JZ        LL3
              TEST      AL,02H
              JZ        R
        LL3:  TEST      LAYER,04H
              JZ        LL4
              TEST      AL,04H
              JZ        R
        LL4:  TEST      LAYER,08H
              JZ        JJMP
              TEST      AL,08H
              JZ        R
              JJMP:     JMP STOP1
          R:  RET
     WAITING  ENDP

       DELAY  PROC
              MOV       CX,0FFFFH
        LPD:  LOOP      LPD
              RET
       DELAY  ENDP

         UP2  PROC
              PUSH      AX
              CALL      DELAY
              MOV       DX,IO8255_A
              MOV       AL,02H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,00H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,08H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,4CH
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,5BH
              OUT       DX,AL
              POP       AX
              RET
         UP2  ENDP

         UP3  PROC
              PUSH      AX
              CALL      DELAY
              MOV       DX,IO8255_A
              MOV       AL,61H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,01H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,08H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,4CH
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,4FH
              OUT       DX,AL
              POP       AX
              RET
         UP3  ENDP

         UP4  PROC
              PUSH      AX
              CALL      DELAY
              MOV       DX,IO8255_A
              MOV       AL,43H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,01H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,00H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,1CH
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,66H
              OUT       DX,AL
              POP       AX
              RET
         UP4  ENDP

       DOWN4  PROC
              PUSH      AX
              CALL      DELAY
              MOV       DX,IO8255_A
              MOV       AL,1CH
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,00H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,01H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,43H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,4FH
              OUT       DX,AL
              POP       AX
              RET
       DOWN4  ENDP

       DOWN3  PROC
              PUSH      AX
              CALL      DELAY
              MOV       DX,IO8255_A
              MOV       AL,4CH
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,08H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,01H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,61H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,5BH
              OUT       DX,AL
              POP       AX
              RET
       DOWN3  ENDP

       DOWN2  PROC
              PUSH      AX
              CALL      DELAY
              MOV       DX,IO8255_A
              MOV       AL,4CH
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,08H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,00H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,02H
              OUT       DX,AL
              CALL      DELAY
              MOV       AL,06H
              OUT       DX,AL
              POP       AX
              RET
       DOWN2  ENDP

      GETKEY  PROC
              MOV       UP,0
              MOV       DX,IO8255_B
        IN1:  IN        AL,DX
         L2:  TEST      AL,02H
              JNZ       L3
              OR        UP,02H
         L3:  TEST      AL,04H
              JNZ       L4
              OR        UP,04H
         L4:  TEST      AL,08H
              JNZ       STA
              OR        UP,08H
        STA:  TEST      AL,01H
              JZ        RR
              JMP       IN1
         RR:  RET
      GETKEY  ENDP

        CODE  ENDS
              END       START
