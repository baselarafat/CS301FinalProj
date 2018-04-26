#include "Instruction.h"



Instruction::Instruction()
{
  myOpcode = UNDEFINED;
  myRS = myRT = myRD = NumRegisters;
}

/// You can specify all the fields to initialize the Instruction
/// @param  op  current instruction opcode
/// @param  rs  current instruction register source
/// @param  rt  current instruction register source 2
/// @param  rd  current instruction register destination
/// @param  imm   current instruction immediate value
Instruction::Instruction(Opcode op, Register rs, Register rt, Register rd, int imm)

{
  setValues(op, rs, rt, rd, imm);
}

/// Allows you to specify all the fields of the Instruction
/// @param  op  current instruction opcode
/// @param  rs  current instruction register source
/// @param  rt  current instruction register source 2
/// @param  rd  current instruction register destination
/// @param  imm   current instruction immediate value
void Instruction::setValues(Opcode op, Register rs, Register rt, Register rd, int imm)
{

  myOpcode = op;
  if(op < 0 || op >= UNDEFINED)
    myOpcode = UNDEFINED;

  myRS = rs;
  if(rs < 0 || rs >= NumRegisters)
    myRS = NumRegisters;

  myRT = rt;
  if(rt < 0 || rt >= NumRegisters)
    myRT = NumRegisters;

  myRD = rd;
  if(rd < 0 || rd >= NumRegisters)
    myRD = NumRegisters;

  myImmediate = imm;
}

 /// Returns a string which represents all of the fields
 /// @return s.str()   a string representing all of the fields
string Instruction::getString() 
{
  stringstream s ;
  s << "OP: \t" << myOpcode << "\t" << "RD: " << myRD << "\t" << 
    "RS: " << myRS << "\t" << "RT: " << "\t" << myRT << "\t" <<
    "Imm: " << myImmediate;
  
  return s.str();
  
}

