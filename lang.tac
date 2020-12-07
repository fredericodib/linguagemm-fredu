.table
.code
test:
mov $2, 0
mov $3, #0
mov $4, #0
mov $5, #1
inttofl $4, $4
mul $6, $5, $4
mov $7, 5.5
mov $8, 10
mov $9, #0
mul $10, $9, $8
inttofl $10, $10
add $11, $7, $10
add $12, $6, $11
inttofl $3, $3
add $13, $3, $12
mov $2, $13
return $2
main:
mema $16, 17
mov $16[0], 78
mov $16[1], 105
mov $16[2], 99
mov $16[3], 101
mov $16[4], 32
mov $16[5], 116
mov $16[6], 111
mov $16[7], 32
mov $16[8], 109
mov $16[9], 101
mov $16[10], 101
mov $16[11], 116
mov $16[12], 32
mov $16[13], 121
mov $16[14], 111
mov $16[15], 117
mov $16[16], 0
mov $15, $16
mov $19, 0
mema $20, 25
mov $20[0], 100
mov $20[1], 111
mov $20[2], 32
mov $20[3], 121
mov $20[4], 111
mov $20[5], 117
mov $20[6], 32
mov $20[7], 108
mov $20[8], 105
mov $20[9], 107
mov $20[10], 101
mov $20[11], 32
mov $20[12], 98
mov $20[13], 108
mov $20[14], 117
mov $20[15], 101
mov $20[16], 98
mov $20[17], 101
mov $20[18], 114
mov $20[19], 114
mov $20[20], 105
mov $20[21], 101
mov $20[22], 115
mov $20[23], 63
mov $20[24], 0
mov $17, $20
mema $21, 3
mov $21[0], 44
mov $21[1], 32
mov $21[2], 0
mema $22, 2
mov $22[0], 10
mov $22[1], 0
mema $23, 200
mov $25, 0
mov $24, 0
L1:
mov $26, $17[$24]
seq $27, $26, 0
brnz L2, $27
mov $23[$25], $26
add $24, $24, 1
add $25, $25, 1
jump L1
L2:
mov $24, 0
L3:
mov $26, $22[$24]
seq $27, $26, 0
brnz L4, $27
mov $23[$25], $26
add $24, $24, 1
add $25, $25, 1
jump L3
L4:
mov $23[$25], 0
mema $28, 200
mov $30, 0
mov $29, 0
L5:
mov $31, $21[$29]
seq $32, $31, 0
brnz L6, $32
mov $28[$30], $31
add $29, $29, 1
add $30, $30, 1
jump L5
L6:
mov $29, 0
L7:
mov $31, $23[$29]
seq $32, $31, 0
brnz L8, $32
mov $28[$30], $31
add $29, $29, 1
add $30, $30, 1
jump L7
L8:
mov $28[$30], 0
mema $33, 200
mov $35, 0
mov $34, 0
L9:
mov $36, $15[$34]
seq $37, $36, 0
brnz L10, $37
mov $33[$35], $36
add $34, $34, 1
add $35, $35, 1
jump L9
L10:
mov $34, 0
L11:
mov $36, $28[$34]
seq $37, $36, 0
brnz L12, $37
mov $33[$35], $36
add $34, $34, 1
add $35, $35, 1
jump L11
L12:
mov $33[$35], 0
mov $18, $33
mov $38, 0
L13:
mov $39, $18[$38]
seq $40, $39, 0
brnz L14, $40
inttoch $39, $39
print $39
add $38, $38, 1
jump L13
L14:
param 4
param 5.5
call test, 2
pop $19
print $19
mema $41, 2
mov $41[0], 10
mov $41[1], 0
mov $42, 0
L15:
mov $43, $41[$42]
seq $44, $43, 0
brnz L16, $44
inttoch $43, $43
print $43
add $42, $42, 1
jump L15
L16:
mema $45, 16
mov $45[0], 101
mov $45[1], 110
mov $45[2], 116
mov $45[3], 114
mov $45[4], 101
mov $45[5], 32
mov $45[6], 50
mov $45[7], 48
mov $45[8], 32
mov $45[9], 101
mov $45[10], 32
mov $45[11], 49
mov $45[12], 48
mov $45[13], 48
mov $45[14], 10
mov $45[15], 0
mov $46, 0
L17:
mov $47, $45[$46]
seq $48, $47, 0
brnz L18, $48
inttoch $47, $47
print $47
add $46, $46, 1
jump L17
L18:
mema $49, 14
mov $49[0], 109
mov $49[1], 101
mov $49[2], 110
mov $49[3], 111
mov $49[4], 114
mov $49[5], 32
mov $49[6], 113
mov $49[7], 117
mov $49[8], 101
mov $49[9], 32
mov $49[10], 50
mov $49[11], 48
mov $49[12], 10
mov $49[13], 0
mov $50, 0
L19:
mov $51, $49[$50]
seq $52, $51, 0
brnz L20, $52
inttoch $51, $51
print $51
add $50, $50, 1
jump L19
L20:
mema $53, 15
mov $53[0], 109
mov $53[1], 97
mov $53[2], 105
mov $53[3], 111
mov $53[4], 114
mov $53[5], 32
mov $53[6], 113
mov $53[7], 117
mov $53[8], 101
mov $53[9], 32
mov $53[10], 49
mov $53[11], 48
mov $53[12], 48
mov $53[13], 10
mov $53[14], 0
mov $54, 0
L21:
mov $55, $53[$54]
seq $56, $55, 0
brnz L22, $56
inttoch $55, $55
print $55
add $54, $54, 1
jump L21
L22:
mov $57, 1
inttofl $57, $57
add $58, $19, $57
mov $19, $58
print $19
mema $59, 2
mov $59[0], 10
mov $59[1], 0
mov $60, 0
L23:
mov $61, $59[$60]
seq $62, $61, 0
brnz L24, $62
inttoch $61, $61
print $61
add $60, $60, 1
jump L23
L24:
mov $63, 0
scani $63
print $63
mema $64, 2
mov $64[0], 10
mov $64[1], 0
mov $65, 0
L25:
mov $66, $64[$65]
seq $67, $66, 0
brnz L26, $67
inttoch $66, $66
print $66
add $65, $65, 1
jump L25
L26:
nop

