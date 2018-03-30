#ifndef __INSTRUCTIONMEMORY_CPP__
#define __INSTRUCTIONMEMORY_CPP__


#include "InstructionMemory.h"
#include <string>

InstructionMemory::InstructionMemory()  {}
InstructionMemory::InstructionMemory(std::string arrayofinstructions[100][2])  {
	for(int i=0;i<100;i++){
		thearray[i][2] = arrayofinstructions[i][2];
}
	
}
InstructionMemory::~InstructionMemory() {}

std::string InstructionMemory::getInstruction(std::string   theAddress){
	std::string Instruction = thearray[10][1];
	// for(int i=0;i<100;i++){
	// 	Instruction = thearray[i][1];
	// 	if(thearray[i][0]==theAddress)
	// 		Instruction = thearray[i][1];
	// }
	return thearray [5][1];
}


 
 
 #endif
