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

int ControlUnit::getMemToReg()
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


int ControlUnit::getAluOp()
{
	if(aluOp)
	{
		return 1;
	}
	else 
	{
		return 0;
	};
}

int ControlUnit::getMemWrite()
{
	if(memWrite)
	{
		return 1;
	}
	else 
	{
		return 0;
	};
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