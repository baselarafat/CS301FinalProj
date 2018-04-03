#ifndef __INSTRUCTIONMEMORY_CPP__
#define __INSTRUCTIONMEMORY_CPP__


#include "InstructionMemory.h"
#include <string>
using namespace std;

InstructionMemory::InstructionMemory()  {}
InstructionMemory::InstructionMemory(unsinged& arrayofinstructions[100][2])  {
	for(int i=0;i<100;i++){
		this->thearray[i][2] = arrayofinstructions[i][2];
}
	
}
InstructionMemory::~InstructionMemory() {}

string InstructionMemory::getInstruction(string   theAddress){
	unsinged Instruction = thearray[10][1];
	// for(int i=0;i<100;i++){
	// 	Instruction = thearray[i][1];
	// 	if(thearray[i][0]==theAddress)
	// 		Instruction = thearray[i][1];
	// }

	// return thearray [5][1];
	return "";
}


 
 
 #endif
