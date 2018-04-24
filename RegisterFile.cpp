#include "RegisterFile.h"

RegisterFile::RegisterFile(){}
RegisterFile::~RegisterFile(){}
RegisterFile::RegisterFile(string registerFile)
{

  int currentReg = 0;

  //
  ifstream infile3;
  infile3.open(registerFile);
    if (!infile3.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
  
  // Loop should run until eof().
  while(infile3.good())
  {
      //creates string and saves each line to input
      string input;
      infile3 >> input;
      int delimiter =input.find(":");

      string reg1 = input.substr(0,delimiter);
      //puts instruction in
      string reg2 = input.substr(delimiter + 1, input.length()-1);
      myRegister[reg1]=reg2;
      //increments number of instructions
  }

  infile3.close();
}

Register RegisterFile::getNum(string reg)
  // Given a string representing a MIPS register operand, returns the number associated
  // with that register.  If string is not a valid register, returns NumRegisters.
{
  for(int i = 0; i < 2*NumRegisters; i++){
    if(myRegisters[i].name == reg){
      return myRegisters[i].number;
    }

  }
  return NumRegisters;
}

 /*Given a string representing a MIPS register operand, returns the value associated
with said register. If the string is not a valid register, returns the number of registers
*/
std::string RegisterFile::readReg(string reg)
{
  return reg;
    }
/*Given a string representing a MIPS register operand and a specified value, stores the value within
said register.

//This should be modified so that it will not modify the values of the registers,but it needs to copy them 
then the values could be changed 
*/
std::string RegisterFile::writeReg(string reg, string val)
{
  for(int i = 0; i < 2*NumRegisters; i++){
    if(myRegisters[i].name == reg){
      myRegisters[i].value = val;
    return myRegisters[i].value;
    }
  }
  return "";
}
