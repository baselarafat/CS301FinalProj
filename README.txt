CS301 Programming Assignment:

Completed by. Will Saada, Basil Arafat, Vincent Camp and Nick Biffis

This purpose of the project is to a create a 32 bit MIPS assembly 
processor with ADD, SUB, ADDI, SLT, LW, SW, BEQ, J instructions 
implemented.  The input config file contains paraments important to 
running the program.  program_input must have a file of mips code in it,
memory_contents_input should have a file with the current memory contents in
it.  register_file_input must have a file with the current contents of the register
file.  output_mode can have two different inputs, single step and batch.  Single
step asks for the user to hit 'y' before moving between the instructions.  Batch
will complete every instruction all at once.  Print_memory_contents is set to true if 
the user wants to print the state of the registers, the state of memory and the 
control signals for each instruction.  write_to_file is a boolean that if true 
is placed after the equal it will print all of the output to a file specified by the output_file point.  Debug mode causes a bunch of print statements to be shown that depict what is going 
on in the data path if it is set to true.

How to Run:
make
./finalproj [input.config]




