#ifndef __INSTRUCTIONMEMORY_CPP__
#define __INSTRUCTIONMEMORY_CPP__


#include "InstructionMemory.h"

#include <string>
InstructionMemory::InstructionMemory()  {}
InstructionMemory::InstructionMemory(std::string arrayofinstructions[100][2])  {
	this->thearray[100][2] = arrayofinstructions[100][2];
}
InstructionMemory::~InstructionMemory() {}

std::string InstructionMemory::getInstruction(std::string   theAddress){
	std::string Instruction ="";
	for(int i=0;i<100;i++){
		if(theAddress==thearray[i][0])
			Instruction=thearray[i][1];
	}
	return Instruction;
}


 
 
 #endif
