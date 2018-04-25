#This works
add	$3, $4, $8
addi	$2, $1, 0x100
sub	$2, $3, $9
j	0x4000018
slt	$1, $2, $10
slt	$1, $2, $3
lw	$1, 700($2)
sw  $17, 500($4)
j	0x40000
beq	$1, $2, 0x200
beq	$1, $2, 0x1e00
