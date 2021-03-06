///Stimulation Class 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
 

#include <iostream>
#include <cstring>
#include <fstream>
#include "InstructionMemory.h"
#include "ProgramCounter.h"
#include <string>
#include <sstream>
#include <map>
#include "DataMemory.h"
#include "ControlUnit.h"
#include "ALU.h"
#include "Multiplexor.h"
#include "Instruction.h"
#include "ShiftLeftTwo.h"
#include "SignExtend.h"
#include "Converter.h"
#include "ConfigurationParser.h"
#include "ALUControl.h"

using namespace std;
class Stimulation{
  public:
   Stimulation(){
  }
  ~Stimulation(){}
  Stimulation(string filename){
  	configFile=filename;
  }
   	void getFiles();
    void run();
private:
  std::string configFile ; ///We could also give this in terminal instead,if needed,but we prefered to set it to default.
  
  std::string programInputFile;
  std::string dataMemoryFile;
  std::string registerFile;
  std::string outputMode;
  std::string outputFile;

  bool debugMode;
  bool printMemoryContents;
  bool writeToFile;

};

