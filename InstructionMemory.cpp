#ifndef __INSTRUCTIONMEMORY_CPP__
#define __INSTRUCTIONMEMORY_CPP__


#include "InstructionMemory.h"



InstructionMemory::InstructionMemory()  {}
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
    string address= "04000000"; //virtual address
   
   
    while( i.getOpcode() != UNDEFINED && instructionCounter <= 100){
        //Puts values into array, prints them for testing purposes.
        cout << i.getString() << endl;
        instructions[address]=i;
        int x =  Converter::hextoint(address);
     	  x=x+4;
      	string address2= Converter::inttohex(x);
        address = "0";
        address.append(address2);
        //cout << i.getEncoding() << endl;
        i = parser->getNextInstruction();
        instructionCounter++;
       
    }
    
    delete parser;


     
  
      // std::cout<<address<<std::endl;
      // infile2 >> input;
    
     // std::cout<<input<<std::endl;
      //puts address in
      // instructions[numOfInstrucs][0] = address;
     
      //puts instruction in
     // instructions[numOfInstrucs][1] = input;
      //increments number of instructions
      // numOfInstrucs++;
     

}

InstructionMemory::~InstructionMemory() {}

  // Given an address, will get the instruction associated with the specified address
Instruction InstructionMemory::getInstruction(std::string theAddress){
	// std::string Instruction = thearray[10][1];
	// for(int i=0;i<100;i++){
	// 	Instruction = thearray[i][1];
	// 	if(thearray[i][0]==theAddress)
	// 		Instruction = thearray[i][1];
	// }
  if(!isValidInstruction(theAddress)){
    cerr << "The instruction address doesn't exist  " <<theAddress<< endl;
        exit(1);}
 		return instructions[theAddress];
  
}

  // Checks to make sure that a valid instruction is given
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
void InstructionMemory::printContents()
{
  // Initializes iterator and iterates through myInstructionMapping, printing contents
    typedef map<string, Instruction>::iterator mapIterator;
    for (mapIterator iter = instructions.begin(); iter != instructions.end(); iter++) {
       
        string hexifiedfirst  = Converter::hexify(iter->first);

        string s = Converter::binaryToHex(iter->second.getEncoding());
        string shexified = Converter::hexify(s);
        cout << hexifiedfirst << ":" <<shexified<<endl;
    }
}
//  int InstructionMemory::hextoint(std::string s ){
//   stringstream ss (s);
//   int x;
//    ss>>hex>>x;
//    return x;
// }
// string InstructionMemory::inttohex(int x){
//   stringstream ss ;
//   ss<<hex<<x;
//   std::string s = ss.str();
//   return s;
// }
// std::string cvthex2Bin(std::string s){
//   int len = s.length();
//   int a = InstructionMemory::hextoint(s);
//   string bin = Parser::cvtInt2Bin(a,len);
//   return bin;

// }

 
 
 #endif
