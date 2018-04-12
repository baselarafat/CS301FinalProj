#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__
//Get an address then release out data from memory that corresponds to that instruction

#include <string>
#include<vector>
class InstructionMemory{

private :
 std::vector<std::vector<std::string> > vec;

public : 
 InstructionMemory();
 InstructionMemory(std::vector<std::vector<std::string> > myvec );
 ~InstructionMemory();

std::string getInstruction(std::string address);

};

#endif
