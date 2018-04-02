#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__
//Get an address then release out data from memory that corresponds to that instruction

#include <string>
using namespace std;
class InstructionMemory{

private :
 unsigned           thearray[100][2];

public : 
 InstructionMemory();
 InstructionMemory(unsigned  array[100][2]);
 ~InstructionMemory();

std::string getInstruction(string address);

};

#endif