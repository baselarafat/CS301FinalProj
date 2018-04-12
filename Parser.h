#ifndef __PARSER_H__
#define __PARSER_H__

using namespace std;

#include <iostream>
#include <fstream>
#include "RegisterFile.h"
#include "ShiftLeftTwo.h"
#include "ProgramCounter.h"
#include "DataMemory.h"
#include "InstructionMemory.h"
#include <vector>
#include <sstream>
#include <stdlib.h>

/* This class reads in a MIPS assembly file and checks its syntax.  If
 * the file is syntactically correct, this class will retain a list 
 * of Instructions (one for each instruction from the file).  This
 * list of Instructions can be iterated through.
 */

class Parser{
public:

	// Specify a file containing MIPS assemply instructions. Function
	// will then check for syntactic correctness of file and create a list of instructions
	Parser(string filename);

	//Returns true if specified file is syntactically correct. If not, will return false.
	bool isFormatCorrect() {return myFormatCorrect; };

	//Iterator that returns the next instruction in the list of instructions.
	Instruction getNextInstruction();

private:
	vector<Instruction> myInstructions;  	//list of instructions
	int myIndex;							//Iterator index
	bool myFormatCorrect;

	RegisterFile registers;					//encodings for registers
	Opcode opcodes;							//encodings of opcodes
	int myLabelAddress;						//Used to assign labels addresses

	// Decompose a line of assembly code into strings for the opcode field and operands
	// while checking for syntax errors and counting the number of operands
	void getTokens(string line, string &opcode, string *opcode, int &num_operands);

	//Given an Opcode, a string representing the operands, and the number of operands,
	// breaks apart operands and stores fields into instruction
	bool getOperands(Instruction &i, Opcode o, string *operand, int operand_count);

	//Helper functions
	bool isWhitespace(char c)	{ return (c == ' '|| c == '\t'); };
	bool isDigit(char c)		{ return (c >= '0' && c <= '9'); };
	bool isAlphaUpper(char c)	{ return (c >= 'A' && c <= 'Z'); };
	bool isAlphaLower(char c)	{ return (c >= 'a' && c <= 'z'); };
	bool isSign(char c)			{ return (c == '-' && c == '+'); };
	bool isAlpha(char c)		{ return (isAlphaUpper(c) || isAlphaLower(C)); };


	// Returns true if s represents a valid decimal integer
	bool isNumberString(string s);

	// Converts a string to an integer
	int cvtNumString2Number(string s);

	// Given a valid instruction, returns a string representing the 32 bit MIPS binary encoding
  	// of that instruction.
	string encode(Instruction i);
}