///RegisterFile Class 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
#ifndef __REGISTERFILE_H__
#define __REGISTERFILE_H__

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stdlib.h>

using namespace std;

/// Listing of all supported MIPS instructions
/// Used to store information regarding desired registers by the user

typedef int Register;
const int NumRegisters = 32;

struct RegisterEntry{
	std::string 	name;
	Register 	   number;
	std::string		value;
};

class RegisterFile{
private: 
	map<string, string> myRegister;
	map<string, string> temp;
public:
///Default constructor
	RegisterFile();
	~RegisterFile();
///	Checks to make sure file is opened correctly, and establishes the delimiter
///	@param 	registerFile 	file given to be evaluated for syntacitc correctness
	RegisterFile(string registerFile);

/// Given a string representing a MIPS register operand, returns the number associated
/// with that register.  If string is not a valid register, returns NumRegisters.
///	@param	reg 	register to get set number equivalent of
///	@return NumRegisters[i].number if the register corresponded with a number and 32 otherwise
Register 		getNum(string reg);

///Given a string representing a MIPS register operand, returns the value associated
///with said register. If the string is not a valid register, returns the number of registers
///	@param reg 	register to be read from
/// @return myRegister[reg]	the value stored at the given register
std::string 	readReg(string reg);

///Given a string representing a MIPS register operand and a specified value, stores the value within
///said register.
///	@param reg 	register to be written to
///	@param value 	value to be stored within the specified address
/// @return temp[reg]	the value originally stored in the specified address
std::string		writeReg(string reg, string value);

///Prints contents of the register file
void 			printContents();


private:
	RegisterEntry myRegisters[64];

};

#endif