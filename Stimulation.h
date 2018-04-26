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

using namespace std;
class Stimulation{
  public:
   Stimulation(){
  }
    void run();
};

