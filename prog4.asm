#Hi this is a comment
add $1, $2, $3
addi $2, $5, 10
addi $1, $2, 3
sub $6, $5, $3
lw	$1, 0($2)
sw  $17, 0($4)
beq $1, $2, 0x200
j 0x4000001c
