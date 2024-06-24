iaddq $num %reg 
==> 
irmovq  $num, %reg_temp
addq    %reg_temp, %reg

|stage|iaddq num rB|
|---|---|
|fetch  |icode: ifun <- M1[PC]  |
|       |rA:rB <- M1[PC+1]      |
|       |valC <- M8[PC+2]       |
|       |valP <- PC + 10        |
|decode |valB <- R[rB]          |
|execute|valE <- valB + valC    |
|memory |                       |
|write back |R[rB] <- valE      |
|update pc  |PC <- valP         |