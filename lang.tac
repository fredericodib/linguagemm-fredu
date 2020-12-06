.table
.code
test:
mov $4, 0
mul $5, $3, $2
mov $6, 5.5
add $7, $6, $5
inttofl $2, $2
add $8, $2, $7
mov $4, $8
main:
mov $10, 0
mov $11, 4
mov $12, 5.5
mov $13, 0
mul $14, $12, $11
mov $15, 10
inttofl $15, $15
add $16, $15, $14
mov $13, $16
print $11
mema $17, 2
mov $17[0], 10
mov $17[1], 0
mov $18, 0
L1:
mov $19, $17[$18]
seq $20, $19, 0
brnz L2, $20
inttoch $19, $19
print $19
add $18, $18, 1
jump L1
L2:
print 3
mema $21, 2
mov $21[0], 10
mov $21[1], 0
mov $22, 0
L3:
mov $23, $21[$22]
seq $24, $23, 0
brnz L4, $24
inttoch $23, $23
print $23
add $22, $22, 1
jump L3
L4:
print 3.5
mema $25, 2
mov $25[0], 10
mov $25[1], 0
mov $26, 0
L5:
mov $27, $25[$26]
seq $28, $27, 0
brnz L6, $28
inttoch $27, $27
print $27
add $26, $26, 1
jump L5
L6:
print $13
mema $29, 2
mov $29[0], 10
mov $29[1], 0
mov $30, 0
L7:
mov $31, $29[$30]
seq $32, $31, 0
brnz L8, $32
inttoch $31, $31
print $31
add $30, $30, 1
jump L7
L8:
mema $34, 4
mov $34[0], 111
mov $34[1], 108
mov $34[2], 97
mov $34[3], 0
mov $33, $34
mema $36, 18
mov $36[0], 109
mov $36[1], 101
mov $36[2], 117
mov $36[3], 32
mov $36[4], 110
mov $36[5], 111
mov $36[6], 109
mov $36[7], 101
mov $36[8], 32
mov $36[9], -61
mov $36[10], -87
mov $36[11], 32
mov $36[12], 102
mov $36[13], 114
mov $36[14], 101
mov $36[15], 100
mov $36[16], 10
mov $36[17], 0
mov $35, $36
mov $37, 0
L9:
mov $38, $33[$37]
seq $39, $38, 0
brnz L10, $39
inttoch $38, $38
print $38
add $37, $37, 1
jump L9
L10:
mema $40, 3
mov $40[0], 44
mov $40[1], 32
mov $40[2], 0
mov $41, 0
L11:
mov $42, $40[$41]
seq $43, $42, 0
brnz L12, $43
inttoch $42, $42
print $42
add $41, $41, 1
jump L11
L12:
mov $44, 0
L13:
mov $45, $35[$44]
seq $46, $45, 0
brnz L14, $46
inttoch $45, $45
print $45
add $44, $44, 1
jump L13
L14:
mema $48, 3
mov $48[0], 44
mov $48[1], 32
mov $48[2], 0
mema $49, 200
mov $51, 0
mov $50, 0
L15:
mov $52, $48[$50]
seq $53, $52, 0
brnz L16, $53
mov $49[$51], $52
add $50, $50, 1
add $51, $51, 1
jump L15
L16:
mov $50, 0
L17:
mov $52, $35[$50]
seq $53, $52, 0
brnz L18, $53
mov $49[$51], $52
add $50, $50, 1
add $51, $51, 1
jump L17
L18:
mov $49[$51], 0
mema $54, 200
mov $56, 0
mov $55, 0
L19:
mov $57, $33[$55]
seq $58, $57, 0
brnz L20, $58
mov $54[$56], $57
add $55, $55, 1
add $56, $56, 1
jump L19
L20:
mov $55, 0
L21:
mov $57, $49[$55]
seq $58, $57, 0
brnz L22, $58
mov $54[$56], $57
add $55, $55, 1
add $56, $56, 1
jump L21
L22:
mov $54[$56], 0
mema $59, 11
mov $59[0], 84
mov $59[1], 117
mov $59[2], 100
mov $59[3], 111
mov $59[4], 32
mov $59[5], 98
mov $59[6], 111
mov $59[7], 109
mov $59[8], 63
mov $59[9], 32
mov $59[10], 0
mema $60, 200
mov $62, 0
mov $61, 0
L23:
mov $63, $59[$61]
seq $64, $63, 0
brnz L24, $64
mov $60[$62], $63
add $61, $61, 1
add $62, $62, 1
jump L23
L24:
mov $61, 0
L25:
mov $63, $54[$61]
seq $64, $63, 0
brnz L26, $64
mov $60[$62], $63
add $61, $61, 1
add $62, $62, 1
jump L25
L26:
mov $60[$62], 0
mov $47, $60
mov $65, 0
L27:
mov $66, $47[$65]
seq $67, $66, 0
brnz L28, $67
inttoch $66, $66
print $66
add $65, $65, 1
jump L27
L28:
mema $69, 200
mov $71, 0
mov $70, 0
L29:
mov $72, $47[$70]
seq $73, $72, 0
brnz L30, $73
mov $69[$71], $72
add $70, $70, 1
add $71, $71, 1
jump L29
L30:
mov $70, 0
L31:
mov $72, $47[$70]
seq $73, $72, 0
brnz L32, $73
mov $69[$71], $72
add $70, $70, 1
add $71, $71, 1
jump L31
L32:
mov $69[$71], 0
mov $68, $69
mov $74, 0
L33:
mov $75, $68[$74]
seq $76, $75, 0
brnz L34, $76
inttoch $75, $75
print $75
add $74, $74, 1
jump L33
L34:
nop

