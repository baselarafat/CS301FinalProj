#ifndef __DATAMEMORY_H__
#define __DATAMEMORY_H__
///Get an address then release out data from memory that corresponds to that instruction

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
 DataMemory(std::string filename);
 ~DataMemory();

std::string getdata(std::string address);
void dmemPrint();
void dmemPrintFinal(string memOutputFile);
std::string writeMem(string address, string val);


};

#endif

