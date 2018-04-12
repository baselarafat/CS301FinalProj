#ifndef __INSTRUCTIONMEMORY_CPP__
#define __INSTRUCTIONMEMORY_CPP__


#include "InstructionMemory.h"
#include <string>
#include <iostream>

InstructionMemory::InstructionMemory()  {}
InstructionMemory::InstructionMemory(std::vector<std::vector<std::string> > thevector) {
	vec = thevector;
}
	

InstructionMemory::~InstructionMemory() {}

std::string InstructionMemory::getInstruction(std::string   theAddress){
	// std::string Instruction = thearray[10][1];
	// for(int i=0;i<100;i++){
	// 	Instruction = thearray[i][1];
	// 	if(thearray[i][0]==theAddress)
	// 		Instruction = thearray[i][1];
	// }
 		 int i=0;
 while(vec[i][0].compare(theAddress)!=0){
 	i++;

 }
 return vec[i][1];
}



 
 
 #endif
