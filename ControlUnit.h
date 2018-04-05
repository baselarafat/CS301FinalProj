
#ifndef __ControlUnit_H__
#define __ControlUnit_H__

#include <string> 

class ControlUnit
{
	protected:
		bool regDest;
		bool jump;
		bool branch;
		bool memRead;
		bool memToReg;
		bool aluOp;
		bool memWrite;
		bool aluSrc;
		bool regWrite;

    

    public:
        ControlUnit();

        ~ControlUnit();

        void setValues(std::string opcode, std::string func);

        void sendSignals();
        
};
