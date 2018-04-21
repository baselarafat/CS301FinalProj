#ifndef __DATAMEMORY_CPP__
#define __DATAMEMORY_CPP__


#include "DataMemory.h"


DataMemory::DataMemory()  {}
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
       
       string s2 = input.substr(delimiter+1,input.length()-1);
       mem[s1]=s2;
      //puts instruction in
     // mem[numOfMemcells][1] = input.substr(delimiter+1,input.length()-1);
      //increments number of instructions
   }

  infile.close();
	
     
  
}

DataMemory::~DataMemory() {}

std::string DataMemory::getdata(std::string   theAddress){
	// std::string Instruction = thearray[10][1];
	// for(int i=0;i<100;i++){
	// 	Instruction = thearray[i][1];
	// 	if(thearray[i][0]==theAddress)
	// 		Instruction = thearray[i][1];
	// }
 		return mem[theAddress];
}
 
 
 #endif
