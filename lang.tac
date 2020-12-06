.table
.code
test:
mov $2, 0
mov $3, #0
mov $4, #1
inttofl $3, $3
mul $5, $4, $3
mov $6, 5.5
add $7, $6, $5
mov $8, #0
inttofl $8, $8
add $9, $8, $7
mov $2, $9
return $2
main:
mema $12, 17
mov $12[0], 78
mov $12[1], 105
mov $12[2], 99
mov $12[3], 101
mov $12[4], 32
mov $12[5], 116
mov $12[6], 111
mov $12[7], 32
mov $12[8], 109
mov $12[9], 101
mov $12[10], 101
mov $12[11], 116
mov $12[12], 32
mov $12[13], 121
mov $12[14], 111
mov $12[15], 117
mov $12[16], 0
mov $11, $12
mov $15, 0
mema $16, 25
mov $16[0], 100
mov $16[1], 111
mov $16[2], 32
mov $16[3], 121
mov $16[4], 111
mov $16[5], 117
mov $16[6], 32
mov $16[7], 108
mov $16[8], 105
mov $16[9], 107
mov $16[10], 101
mov $16[11], 32
mov $16[12], 98
mov $16[13], 108
mov $16[14], 117
mov $16[15], 101
mov $16[16], 98
mov $16[17], 101
mov $16[18], 114
mov $16[19], 114
mov $16[20], 105
mov $16[21], 101
mov $16[22], 115
mov $16[23], 63
mov $16[24], 0
mov $13, $16
mema $17, 2
mov $17[0], 10
mov $17[1], 0
mema $18, 200
mov $20, 0
mov $19, 0
L1:
mov $21, $13[$19]
seq $22, $21, 0
brnz L2, $22
mov $18[$20], $21
add $19, $19, 1
add $20, $20, 1
jump L1
L2:
mov $19, 0
L3:
mov $21, $17[$19]
seq $22, $21, 0
brnz L4, $22
mov $18[$20], $21
add $19, $19, 1
add $20, $20, 1
jump L3
L4:
mov $18[$20], 0
mema $23, 3
mov $23[0], 44
mov $23[1], 32
mov $23[2], 0
mema $24, 200
mov $26, 0
mov $25, 0
L5:
mov $27, $23[$25]
seq $28, $27, 0
brnz L6, $28
mov $24[$26], $27
add $25, $25, 1
add $26, $26, 1
jump L5
L6:
mov $25, 0
L7:
mov $27, $18[$25]
seq $28, $27, 0
brnz L8, $28
mov $24[$26], $27
add $25, $25, 1
add $26, $26, 1
jump L7
L8:
mov $24[$26], 0
mema $29, 200
mov $31, 0
mov $30, 0
L9:
mov $32, $11[$30]
seq $33, $32, 0
brnz L10, $33
mov $29[$31], $32
add $30, $30, 1
add $31, $31, 1
jump L9
L10:
mov $30, 0
L11:
mov $32, $24[$30]
seq $33, $32, 0
brnz L12, $33
mov $29[$31], $32
add $30, $30, 1
add $31, $31, 1
jump L11
L12:
mov $29[$31], 0
mov $14, $29
mov $34, 0
L13:
mov $35, $14[$34]
seq $36, $35, 0
brnz L14, $36
inttoch $35, $35
print $35
add $34, $34, 1
jump L13
L14:
param 4
param 5.5
call test, 2
pop $15
print $15
mema $37, 2
mov $37[0], 10
mov $37[1], 0
mov $38, 0
L15:
mov $39, $37[$38]
seq $40, $39, 0
brnz L16, $40
inttoch $39, $39
print $39
add $38, $38, 1
jump L15
L16:
mema $41, 16
mov $41[0], 109
mov $41[1], 97
mov $41[2], 105
mov $41[3], 111
mov $41[4], 114
mov $41[5], 32
mov $41[6], 111
mov $41[7], 117
mov $41[8], 32
mov $41[9], 105
mov $41[10], 103
mov $41[11], 117
mov $41[12], 97
mov $41[13], 108
mov $41[14], 10
mov $41[15], 0
mov $42, 0
L17:
mov $43, $41[$42]
seq $44, $43, 0
brnz L18, $44
inttoch $43, $43
print $43
add $42, $42, 1
jump L17
L18:
mema $45, 7
mov $45[0], 109
mov $45[1], 101
mov $45[2], 110
mov $45[3], 111
mov $45[4], 114
mov $45[5], 10
mov $45[6], 0
mov $46, 0
L19:
mov $47, $45[$46]
seq $48, $47, 0
brnz L20, $48
inttoch $47, $47
print $47
add $46, $46, 1
jump L19
L20:
mov $49, 1
inttofl $49, $49
add $50, $15, $49
mov $15, $50
print $15
mema $51, 2
mov $51[0], 10
mov $51[1], 0
mov $52, 0
L21:
mov $53, $51[$52]
seq $54, $53, 0
brnz L22, $54
inttoch $53, $53
print $53
add $52, $52, 1
jump L21
L22:
mov $55, 0
scani $55
print $55
mema $56, 2
mov $56[0], 10
mov $56[1], 0
mov $57, 0
L23:
mov $58, $56[$57]
seq $59, $58, 0
brnz L24, $59
inttoch $58, $58
print $58
add $57, $57, 1
jump L23
L24:
nop

