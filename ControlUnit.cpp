#ifndef __ControlUnit_CPP__
#define __ControlUnit_CPP__

#include "ControlUnit.h"

ControlUnit::ControlUnit(){}

ControlUnit::~ControlUnit(){}

void ControlUnit::setValues(std::string opcode)
{	
	//Jump instruction
	if(opcode == "000010")
	{
		this->jump = true;
		break;
	}

	//R-Type
	if(opcode == "000000")
	{
		this->regDest = true;
		this->regWrite = true;
		this->aluOp1 = true;

		break;
	}

	//I-Type
	//Addi
	if(opcode == "001000")
	{
		this->aluSrc = true;
		break;
	}



	//LW
	if(opcode == "100011")
	{
		this->aluSrc = true;
		this->memToReg = true;
		this->regWrite = true;
		this->memRead = true;
		break;
	}

	//SW
	if(opcode == "101011")
	{
		this->aluSrc = true;
		this->memWrite = true;
		break;
	}

	//BEQ
	if(opcode == "000100")
	{
		this->branch = true;
		this->aluOp0 = true;
		break;
	}
}

bool ControlUnit::getRegDest()
{
	return this->regDest;
}

bool ControlUnit::getJump()
{
	return this->jump;
}

bool ControlUnit::getBranch()
{
	return this->branch;
}

bool ControlUnit::getMemRead()
{
	return this->memRead;
}

bool ControlUnit::getMemToReg()
{
	return this->memToReg;
}


bool ControlUnit::getAluOp()
{
	return this->aluOp;
}

bool ControlUnit::getMemWrite()
{
	return this->memWrite;
}

bool ControlUnit::getAluSrc()
{
	return this->aluSrc;
}

bool ControlUnit::getRegWrite()
{
	return this->regWrite;
}

void ControlUnit::setToFalse()
{
	this->regDest = false;
	this->jump = false;
	this->branch = false;
	this->memRead = false;
	this->memToReg = false;
	this->aluOp = false;
	this->aluOp1 = false;
	this->memWrite = false;
	this->aluSrc = false;
	this->regWrite = false;
}

#endif    