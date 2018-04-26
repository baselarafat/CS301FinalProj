#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__
//Get an address then release out data from memory that corresponds to that instruction

#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include "Converter.h"

using namespace std;
class DataMemory{

private :
 std::map<string,string> mem;

public : 

/// Default constructor
 DataMemory();
/// Makes sure the file given is opened correctly and 
/// identifies the delimiter
/// @param filename	file that will be checked for syntactic correctness
 DataMemory(std::string filename);
 ~DataMemory();

/// Given an Address, returns the data associated with that address
/// @ param  theAddress  specified address to gather data from
/// @ return  mem[theAddress] the data associated with the specified address in the data memory
std::string getdata(std::string address);

/// Prints the data memory to console
void dmemPrint();

/// Prints the data memory to the Output file
///  @ param   memOutputFile   file that data memory will be written to
void dmemPrintFinal(string memOutputFile);

/// Given an address and a value, will write the value within the specified data memory address
///  @param  address   address to be written to
///  @param  val       value to be stored into the specified address
///  @return temp      the value originally stored within the specified address
std::string writeMem(string address, string val);


};

#endif

