#include "RegisterFile.h"

RegisterFile::RegisterFile()
{
  int i = 0;

  /// Register Table for access
  myRegisters[i].name = "$0";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$1";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$2";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$3";  myRegisters[i].number = i; i++;

  myRegisters[i].name = "$4";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$5";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$6";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$7";  myRegisters[i].number = i; i++;

  myRegisters[i].name = "$8";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$9";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$10";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$11";  myRegisters[i].number = i; i++;

  myRegisters[i].name = "$12";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$13";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$14";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$15";  myRegisters[i].number = i; i++;

  myRegisters[i].name = "$16";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$17";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$18";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$19";  myRegisters[i].number = i; i++;

  myRegisters[i].name = "$20";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$21";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$22";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$23";  myRegisters[i].number = i; i++;

  myRegisters[i].name = "$24";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$25";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$26";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$27";  myRegisters[i].number = i; i++;

  myRegisters[i].name = "$28";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$29";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$30";  myRegisters[i].number = i; i++;
  myRegisters[i].name = "$31";  myRegisters[i].number = i; i++;

  myRegisters[i].name = "$zero";  myRegisters[i].number = 0; i++;
  myRegisters[i].name = "$v0";  myRegisters[i].number = 2; i++;
  myRegisters[i].name = "$v1";  myRegisters[i].number = 3; i++;
  myRegisters[i].name = "$a0";  myRegisters[i].number = 4; i++;

  myRegisters[i].name = "$a1";  myRegisters[i].number = 5; i++;
  myRegisters[i].name = "$a2";  myRegisters[i].number = 6; i++;
  myRegisters[i].name = "$a3";  myRegisters[i].number = 7; i++;
  myRegisters[i].name = "$t0";  myRegisters[i].number = 8; i++;

  myRegisters[i].name = "$t1";  myRegisters[i].number = 9; i++;
  myRegisters[i].name = "$t2";  myRegisters[i].number = 10; i++;
  myRegisters[i].name = "$t3";  myRegisters[i].number = 11; i++;
  myRegisters[i].name = "$t4";  myRegisters[i].number = 12; i++;

  myRegisters[i].name = "$t5";  myRegisters[i].number = 13; i++;
  myRegisters[i].name = "$t6";  myRegisters[i].number = 14; i++;
  myRegisters[i].name = "$t7";  myRegisters[i].number = 15; i++;
  myRegisters[i].name = "$s0";  myRegisters[i].number = 16; i++;

  myRegisters[i].name = "$s1";  myRegisters[i].number = 17; i++;
  myRegisters[i].name = "$s2";  myRegisters[i].number = 18; i++;
  myRegisters[i].name = "$s3";  myRegisters[i].number = 19; i++;
  myRegisters[i].name = "$s4";  myRegisters[i].number = 20; i++;

  myRegisters[i].name = "$s5";  myRegisters[i].number = 21; i++;
  myRegisters[i].name = "$s6";  myRegisters[i].number = 22; i++;
  myRegisters[i].name = "$s7";  myRegisters[i].number = 23; i++;
  myRegisters[i].name = "$t8";  myRegisters[i].number = 24; i++;

  myRegisters[i].name = "$t9";  myRegisters[i].number = 25; i++;
  myRegisters[i].name = "$gp";  myRegisters[i].number = 28; i++;
  myRegisters[i].name = "$sp";  myRegisters[i].number = 29; i++;
  myRegisters[i].name = "$fp";  myRegisters[i].number = 30; i++;

  myRegisters[i].name = "$ra";  myRegisters[i].number = 31; i++;
}
RegisterFile::~RegisterFile(){}

/// Checks to make sure file is opened correctly, and establishes the delimiter
/// @param  registerFile  file given to be evaluated for syntacitc correctness
RegisterFile::RegisterFile(string registerFile)
{
  /// Makes sure the file is opened correctly
  ifstream infile3;
  infile3.open(registerFile);
    if (!infile3.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
  
  /// Loop should run until eof().
  while(infile3.good())
  {
      ///creates string and saves each line to input
      string input;
      infile3 >> input;
      int delimiter =input.find(":");

      string reg1 = input.substr(0,delimiter);
      ///puts instruction in
      string reg2 = input.substr(delimiter + 1, input.length()-1);
      myRegister[reg1]=reg2;
      ///increments number of instructions
  }

  infile3.close();
}

/// Given a string representing a MIPS register operand, returns the number associated
/// with that register.  If string is not a valid register, returns NumRegisters.
/// @param  reg   register to get set number equivalent of
/// @return NumRegisters[i].number if the register corresponded with a number and 32 otherwise
Register RegisterFile::getNum(string reg)
{
  for(int i = 0; i < 2*NumRegisters; i++){
    if(myRegisters[i].name == reg){
      return myRegisters[i].number;
    }

  }
  return NumRegisters;
}

///Given a string representing a MIPS register operand, returns the value associated
///with said register. If the string is not a valid register, returns the number of registers
/// @param reg  register to be read from
/// @return myRegister[reg] the value stored at the given register
std::string RegisterFile::readReg(string reg)
{
  return myRegister[reg];
    }

///Given a string representing a MIPS register operand and a specified value, stores the value within
///said register.
/// @param reg  register to be written to
/// @param value  value to be stored within the specified address
/// @return temp[reg] the value originally stored in the specified address
std::string RegisterFile::writeReg(string reg, string val)
{

  temp[reg] = myRegister[reg];
  myRegister[reg] = val;
  return temp[reg];


}

///Prints contents of register file
void     RegisterFile::printContents()
{
    for(int i = 0; i <= 31; i++)
    {
        string temp = to_string(i);
        
        std::cout << i << ":" << myRegister[temp] << endl;
    }
  }
    void     RegisterFile::PrintFinal(std::string regOutputFile)
{
  ofstream outputFile;
  outputFile.open(regOutputFile);
    for(int i = 0; i <= 31; i++)
    {
        string temp = to_string(i);
        
        outputFile << i << ":" << myRegister[temp] << endl;
    }
    outputFile.close();
      
}




