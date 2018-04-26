///Control Unit Class 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
/// The Control Unit class stores a variables for each of the 
/// control fields in out simple mips processor.  The set values function 
/// is called given an opcode to initialize the values for each new 
/// instruction.  After each instruction the set to zero method resets the control 
/// object such that all fiels are false.
///
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
		bool aluOp0;
        bool aluOp1;
		bool memWrite;
		bool aluSrc;
		bool regWrite;

    

    public:
        ControlUnit();

        ~ControlUnit();

        void setValues(std::string opcode);

        void setToZero();

        int getRegDest();

        int getJump();

        int getBranch();

        int getMemRead();

        int getmemToReg();

        int getMemWrite();

        int getAluSrc();

        int getRegWrite();

        int getAluOp0();

        int getAluOp1();

        void printControl();

        
};
#endif
