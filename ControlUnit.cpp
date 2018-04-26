#ifndef __ControlUnit_CPP__
#define __ControlUnit_CPP__

#include "ControlUnit.h"
#include <iostream>
#include <string>

ControlUnit::ControlUnit(){}

ControlUnit::~ControlUnit(){}

void ControlUnit::setValues(std::string opcode)
{	
	///Jump instruction
	if(opcode == "000010")
	{
		this->jump = true;
	}

	///R-Type
	if(opcode == "000000")
	{
		regDest = true;
		regWrite = true;
		//// 10 so true, false
		aluOp0 = false;
		aluOp1 = true;
	}

	///I-Type
	///Addi
	if(opcode == "001000")
	{
		aluSrc = true;
		regWrite = true;
		/// I think? this means add
		aluOp0 = false;
		aluOp1 = false;
	}

	///LW
	if(opcode == "100011")
	{
		aluSrc = true;
		memToReg = true;
		regWrite = true;
		memRead = true;
		aluOp0 = false;
		aluOp1 = false;
	}

	///SW
	if(opcode == "101011")
	{
		aluSrc = true;
		memWrite = true;
		aluOp0 = false;
		aluOp1 = false;
	}

	///BEQ
	if(opcode == "000100")
	{
		branch = true;
		///Represents 01
		aluOp0 = true;
		aluOp1 = false;
	}
	
}

///The following accessors return 1 if the control 
/// is set to true and 0 if false.
int ControlUnit::getRegDest()
{
	if(regDest)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getJump()
{
	if(jump)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getBranch()
{
	if(branch)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getMemRead()
{
	if(memRead)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getmemToReg()
{
	if(memToReg)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}


/// std::string ControlUnit::getAluOp()
/// {

/// 		return aluOp;
/// }

int ControlUnit::getMemWrite()
{
	if(memWrite)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getAluSrc()
{
	if(aluSrc)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getRegWrite()
{
	if(regWrite)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getAluOp0()
{
	if(aluOp0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int ControlUnit::getAluOp1()
{
	if(aluOp1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

///Method that sets all values to 0, must be done prior to 
///each instruction
void ControlUnit::setToZero()
{
	this->regDest = false;
	this->jump = false;
	this->branch = false;
	this->memRead = false;
	this->memToReg = false;
	this->aluOp0 = false;
	this->aluOp1 = false;
	this->memWrite = false;
	this->aluSrc = false;
	this->regWrite = false;
}

///Method that prints out the contents of the Control
void ControlUnit::printControl()
{
	std::cout << "RegDest: "  << getRegDest()  << std::endl;
	std::cout << "Jump: "     << getJump()     << std::endl;
	std::cout << "Branch: "   << getBranch()   << std::endl;
	std::cout << "MemRead: "  << getMemRead()  << std::endl;
	std::cout << "MemToReg: " << getmemToReg() << std::endl;
	std::cout << "MemWrite: " << getMemWrite() << std::endl;
	std::cout << "Alusrc: "   << getAluSrc()   << std::endl;
	std::cout << "RegWrite: " << getRegWrite() << std::endl;
	std::string operation  = std::to_string(getAluOp1());
	std::string operation2 = std::to_string(getAluOp0());
	operation.append(operation2);
	std::cout << "ALUOp: " << operation << std::endl;

}

#endif    