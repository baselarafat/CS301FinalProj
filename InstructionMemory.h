///InstructionMemory Class 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
#ifndef __INSTRUCTIONMEMORY_H__
#define __INSTRUCTIONMEMORY_H__
///Get an address then release out data from memory that corresponds to that instruction

#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include "Instruction.h"
#include "Parser.h"
#include "Converter.h"

using namespace std;
class InstructionMemory{

private :
 std::map<string,Instruction> instructions;

public : 
/// Default constructor
 InstructionMemory();

/// Accesses and parses through the Instruction memory
/// @param   filename    file to be accessed and store given instructions
 InstructionMemory(std::string filename);
 ~InstructionMemory();

/// Given an address, will get the instruction associated with the specified address
/// @param theAddress  Address given to access and get the associated Instruction
/// @return Instruction associated with given address
Instruction getInstruction(std::string address);

/// Checks to make sure that a valid instruction is given
/// @param theAddress  Address given to check if it's instruction is valid
/// @return false if the instruction at the given address is invalid, and true otherwise
bool isValidInstruction(std::string theAddress);

/// Initializes iterator and iterates through myInstructionMapping, gathering the contents
/// at each Instruction address and printing them out
void printContents();


void imemPrintFinal(string OutputFile);



};

#endif
