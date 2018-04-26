#ifndef __DATAMEMORY_CPP__
#define __DATAMEMORY_CPP__


#include "DataMemory.h"

/// Default constructor
DataMemory::DataMemory()  {}

/// Makes sure the file given is opened correctly and 
/// identifies the delimiter
/// @param filename file that will be checked for syntactic correctness
DataMemory::DataMemory(string filename) {

ifstream infile;
  infile.open(filename);
    if (!infile.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
  // Loop should run until eof().
  while(infile.good())
  {
    
     // mem[numOfMemcells] = vector<string>(2);
      //creates string and saves each line to input
      string input;
      infile >> input;
      int delimiter =input.find(":");
      //puts address in
      // mem[numOfMemcells][0] = input.substr(0,delimiter);
      string s1 =input.substr(0,delimiter);
      string hexs1= Converter::hexify(s1);
       
       string s2 = input.substr(delimiter+1,input.length()-1);
       string hexs2= Converter::hexify(s2);
       mem[hexs1]=hexs2;
      //puts instruction in
     // mem[numOfMemcells][1] = input.substr(delimiter+1,input.length()-1);
      //increments number of instructions
   }

  infile.close();
  
}

DataMemory::~DataMemory() {}

      // Given an Address, returns the data associated with that address
      // @ param  theAddress  specified address to gather data from
      // @ return  mem[theAddress] the data associated with the specified address in the data memory
std::string DataMemory::getdata(std::string   theAddress){
	
 		return mem[theAddress];
}

      // Prints the data memory to console
void DataMemory::dmemPrint()
{

  map<string,string>::iterator it = mem.begin();
  it++;
  while(it != mem.end())
  {
    std::cout<< it->first << ":" << it->second <<endl;
    it++;
  }
}

      // Prints the data memory to the Output file
void DataMemory::dmemPrintFinal(string memOutputFile)
{
  ofstream outputFile;
  outputFile.open(memOutputFile);
  map<string,string>::iterator it = mem.begin();
  it++;
  while(it != mem.end())
  {
    outputFile<< it->first << ":" << it->second <<endl;
    it++;
  }
  outputFile.close();
}
 
      // Given an address and a value, will write the value within the specified data memory address
 std::string DataMemory::writeMem(string address, string val)
{
  string temp = mem[address];
  //mem.insert(std::make_pair(address, val));
  mem[address] = val;
  return temp;


  

}
 #endif
