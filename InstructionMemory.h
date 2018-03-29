#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__
//Get an address then release out data from memory that corresponds to that instruction

#include <string>
class InstructionMemory{





private :
 std::string           thearray[100][2];

public : 
 InstructionMemory();
 InstructionMemory(std::string  thearray[100][2]);
 ~InstructionMemory();

 std::string getInstruction(std::string address);

};

#endif