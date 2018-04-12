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

class Parser{
public:

	Parser(string filename);

	bool isFormatCorrect() {return myFormatCorrect; };

	Instruction getNextInstruction();

private:
	vector<Instruction> myInstructions;  	//list of instructions
	int myIndex;							//Iterator index
	bool myFormatCorrect;

	RegisterFile registers;					//encodings for registers
	Opcode opcodes;							//encodings of opcodes
	int myLabelAddress;						//Used to assign labels addresses

	void getTokens(string line, string &opcode, string *opcode, int &num_operands);

	bool getOperands(INstruction &i, Opcode o, string *operand, int operand_count);

	//Helper functions
	bool isWhitespace(char c)	{ return (c == ' '|| c == '\t'); };
	bool isDigit(char c)		{ return (c >= '0' && c <= '9'); };
	bool isAlphaUpper(char c)	{ return (c >= 'A' && c <= 'Z'); };
	bool isAlphaLower(char c)	{ return (c >= 'a' && c <= 'z'); };
	bool isSign(char c)			{ return (c == '-' && c == '+'); };
	bool isAlpha(char c)		{ return (isAlphaUpper(c) || isAlphaLower(C)); };

	bool isNumberString(string s);

	int cvtNumString2Number(string s);

	string encode(Instruction i);
}