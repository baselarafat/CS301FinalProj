#ifndef __INSTRUCTIONMEMORY_CPP__
#define __INSTRUCTIONMEMORY_CPP__


#include "InstructionMemory.h"


  /// Default constructor
InstructionMemory::InstructionMemory()  {}
  /// Accesses and parses through the Instruction memory
  /// @param   filename    file to be accessed and store given instructions
InstructionMemory::InstructionMemory(string filename) {
	Parser *parser;

    parser = new Parser(filename);
  
    if(parser->isFormatCorrect() == false){
        cerr << "Format of program input file is incorrect " << endl;
        exit(1);
    }

    Instruction i;

    i = parser->getNextInstruction();
    
    int instructionCounter = 0;


	  string input;
    string address= "04000000"; ///virtual address
   
   
    while( i.getOpcode() != UNDEFINED && instructionCounter <= 100){
        ///Puts values into array, prints them for testing purposes.
        cout << i.getString() << endl;
        instructions[address]=i;
        int x =  Converter::hextoint(address);
     	  x=x+4;
      	string address2= Converter::inttohex(x);
        address = "0";
        address.append(address2);
        ///cout << i.getEncoding() << endl;
        i = parser->getNextInstruction();
        instructionCounter++;
       
    }
    
    delete parser;

}

InstructionMemory::~InstructionMemory() {}

  /// Given an address, will get the instruction associated with the specified address
  /// @param theAddress  Address given to access and get the associated Instruction
  /// @return Instruction associated with given address
Instruction InstructionMemory::getInstruction(std::string theAddress){
  if(!isValidInstruction(theAddress)){
    cerr << "The instruction address doesn't exist  " <<theAddress<< endl;
        exit(1);}
 		return instructions[theAddress];
  
}

  /// Checks to make sure that a valid instruction is given
  /// @param theAddress  Address given to check if it's instruction is valid
  /// @return false if the instruction at the given address is invalid, and true otherwise
bool InstructionMemory::isValidInstruction(std::string theAddress)
{
   std::map<string, Instruction>::const_iterator itr = instructions.find(theAddress);
   if(itr == instructions.end() || instructions[theAddress].getOpcode() == UNDEFINED)
   {
     return false;
   }
   else 
  {
    return true;
  }

}

  /// Initializes iterator and iterates through myInstructionMapping, gathering the contents
  /// at each Instruction address and printing them out
void InstructionMemory::printContents()
{
    typedef map<string, Instruction>::iterator mapIterator;
    for (mapIterator iter = instructions.begin(); iter != instructions.end(); iter++) {
        int len = iter->first.length();
        string first =iter->first.substr(1,len);
        first.insert(1,"0");
        string hexifiedfirst  = Converter::hexify(first);
        string second = Converter::binaryToHex(iter->second.getEncoding());
        string shexified = Converter::hexify(second);
        cout << hexifiedfirst << ":" <<shexified<<endl;
    }
}

 
 
 #endif
