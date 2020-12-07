.table
.code
fatorial:
mov $2, 0
mov $3, 0
mov $4, #0
mov $5, 1
sub $6, $4, $5
mov $3, $6
mov $7, 0
mov $8, 0
sleq $8, $3, $7
brz L1, $8
return 1
L1:
param $3
call fatorial, 1
pop $2
mov $9, #0
mul $10, $9, $2
mov $2, $10
return $2
main:
mov $12, 0
mema $13, 19
mov $13[0], 68
mov $13[1], 105
mov $13[2], 103
mov $13[3], 105
mov $13[4], 116
mov $13[5], 101
mov $13[6], 32
mov $13[7], 117
mov $13[8], 109
mov $13[9], 32
mov $13[10], 110
mov $13[11], -61
mov $13[12], -70
mov $13[13], 109
mov $13[14], 101
mov $13[15], 114
mov $13[16], 111
mov $13[17], 10
mov $13[18], 0
mov $14, 0
L2:
mov $15, $13[$14]
seq $16, $15, 0
brnz L3, $16
inttoch $15, $15
print $15
add $14, $14, 1
jump L2
L3:
scani $12
param $12
call fatorial, 1
pop $12
print $12
mema $17, 2
mov $17[0], 10
mov $17[1], 0
mov $18, 0
L4:
mov $19, $17[$18]
seq $20, $19, 0
brnz L5, $20
inttoch $19, $19
print $19
add $18, $18, 1
jump L4
L5:
nop

