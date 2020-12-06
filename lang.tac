.table
.code
somatorio:
mov $2, 0
mov $3, 0
mov $4, 1
sub $5, $2, $4
mov $3, $5
return 0
param $3
call somatorio, 1
pop $2
add $6, #0, $2
mov $2, $6
return $2
main:
mov $8, 0
scani $8
print $8
mema $9, 2
mov $9[0], 10
mov $9[1], 0
mov $10, 0
L1:
mov $11, $9[$10]
seq $12, $11, 0
brnz L2, $12
inttoch $11, $11
print $11
add $10, $10, 1
jump L1
L2:
nop

