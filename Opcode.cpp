#include "Opcode.h"

OpcodeTable::OpcodeTable()
/// Initializes all the fields for every instruction in Opcode enum
{
  myArray[ADD].name = "add";  myArray[ADD].numOps = 3; myArray[ADD].rdPos = 0; myArray[ADD].rsPos = 1;  myArray[ADD].rtPos = 2;   myArray[ADD].immPos = -1;  myArray[ADD].instType = RTYPE; myArray[ADD].op_field = "000000"; myArray[ADD].funct_field = "100000";
 
 
  
  myArray[ADDI].name = "addi";  myArray[ADDI].numOps = 3; myArray[ADDI].rdPos = -1;  myArray[ADDI].rsPos = 1;  myArray[ADDI].rtPos = 0;   myArray[ADDI].immPos = 2;  myArray[ADDI].instType = ITYPE; myArray[ADDI].op_field = "001000"; myArray[ADDI].funct_field = "";
  
  myArray[SLT].name = "slt";  myArray[SLT].numOps = 3;   myArray[SLT].rdPos = 0; myArray[SLT].rsPos = 1;  myArray[SLT].rtPos = 2;   myArray[SLT].immPos = -1;  myArray[SLT].instType = RTYPE; myArray[SLT].op_field = "000000"; myArray[SLT].funct_field = "101010";
  
  myArray[J].name = "j";  myArray[J].numOps = 1;   myArray[J].rdPos = -1;  myArray[J].rsPos = -1;  myArray[J].rtPos = -1;   myArray[J].immPos = 0;  myArray[J].instType = JTYPE; myArray[J].op_field = "000010"; myArray[J].funct_field = ""; myArray[J].immLabel = true;
  
  myArray[SUB].name = "sub";  myArray[SUB].numOps = 3; myArray[SUB].rdPos = 0;  myArray[SUB].rsPos = 1;  myArray[SUB].rtPos = 2;   myArray[SUB].immPos = -1;  myArray[SUB].instType = RTYPE; myArray[SUB].op_field = "000000"; myArray[SUB].funct_field = "100010";
  
  myArray[LW].name = "lw";  myArray[LW].numOps = 3; myArray[LW].rdPos = -1;  myArray[LW].rsPos = 2;  myArray[LW].rtPos = 0;   myArray[LW].immPos = 1;  myArray[LW].instType = ITYPE; myArray[LW].op_field = "100011";

  myArray[SW].name = "sw";  myArray[SW].numOps = 3; myArray[SW].rdPos = -1; myArray[SW].rsPos = 2;  myArray[SW].rtPos = 0;   myArray[SW].immPos = 1;  myArray[SW].instType = ITYPE; myArray[SW].op_field = "101011"; 

  myArray[BEQ].name = "beq";  myArray[BEQ].numOps = 3;   myArray[BEQ].rdPos = -1;myArray[BEQ].rsPos = 0;  myArray[BEQ].rtPos = 1;   myArray[BEQ].immPos = 2;  myArray[BEQ].instType = ITYPE; myArray[BEQ].op_field = "000100";myArray[BEQ].funct_field = "";myArray[BEQ].immLabel = true;
  
  
  
  /// myArray[UNDEFINED].name = "undefined";  myArray[UNDEFINED].numOps = -1;   myArray[UNDEFINED].rdPos = -1;  myArray[UNDEFINED].rsPos = -1;  myArray[UNDEFINED].rtPos = -1;   myArray[UNDEFINED].immPos = -1; myArray[UNDEFINED].op_field = ""; myArray[UNDEFINED].funct_field = "";

}

/// Given a valid MIPS assembly mnemonic, returns an Opcode which represents a template for that instruction.
/// @param  str MIPS assembly mnemonic
/// @return opcode for the specified mnemonic 
Opcode OpcodeTable::getOpcode(string str)
{
  for(int i = 0; i < (int)UNDEFINED; i++){
    if(myArray[i].name == str){
      return (Opcode)i;
    }
  }
  return UNDEFINED;
}

/// Given an Opcode, returns number of expected operands.
/// @param opcode for current instruction
/// @return number of operands for the specified opcode
int OpcodeTable::numOperands(Opcode o)
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].numOps;
}

/// Given an Opcode, returns the position of RS field.  If field is not appropriate for this Opcode, returns -1.
/// @param opcode of the current instruction
/// @return the position of the RS field 
int OpcodeTable::RSposition(Opcode o)
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].rsPos;
}

/// Given an Opcode, returns the position of RT field.  If field is not appropriate for this Opcode, returns -1.
/// @param opcode of the current instruction
/// @return the position of the RS field 
int OpcodeTable::RTposition(Opcode o)
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].rtPos;
}

/// Given an Opcode, returns the position of RD field.  If field is not appropriate for this Opcode, returns -1.
/// @param opcode of the current instruction
/// @return the position of the RD field 
int OpcodeTable::RDposition(Opcode o)
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].rdPos;
}

/// Given an Opcode, returns the position of IMM field.  If field is not appropriate for this Opcode, returns -1.
/// @param opcode of the current instruction
/// @return the position of the IMM field 
int OpcodeTable::IMMposition(Opcode o)
{
  if(o < 0 || o >= UNDEFINED)
    return -1;

  return myArray[o].immPos;
}

/// Given an Opcode, returns instruction type.
/// @param opcode of the current instruction
/// @return the type of instruction
InstType OpcodeTable::getInstType(Opcode o)
{
  if(o < 0 || o > UNDEFINED)
    return (InstType)-1;
  return myArray[o].instType;
}

/// Given an Opcode, returns a string representing the binary encoding of the opcode field.
/// @param opcode of the current instruction
/// @return string representing the binary encoding of the opcode 
string OpcodeTable::getOpcodeField(Opcode o)
{
  if(o < 0 || o > UNDEFINED)
    return string("");
  return myArray[o].op_field;
}

/// Given an Opcode, returns a string representing the binary encoding of the function field.
/// @param opcode of the current instruction
/// @return string representing the binary encoding of the funct field
string OpcodeTable::getFunctField(Opcode o)
{
  if(o < 0 || o > UNDEFINED)
    return string("");
  return myArray[o].funct_field;
}

/// Given an Opcode, returns true if instruction expects a label in the instruction. See "J".
/// @param opcode of the current instruction
/// @return true/false as to whether the instruction expects label
bool OpcodeTable::isIMMLabel(Opcode o)
{
  if(o < 0 || o > UNDEFINED)
    return false;
  return myArray[o].immLabel;
}

///Given an opcode return the name of the instruction associated with the opcode
/// @param opcode of the current instruction
/// @return name of instruction 
string OpcodeTable::name(Opcode o){
  if(o < 0 || o > UNDEFINED)
    return "";
  return myArray[o].name;
}
