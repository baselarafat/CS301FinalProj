#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

int main ()
{
  
  // writting code to read the data memory file.
  // will read data and build a 2d array that can be used
  // to construct the instruction memory.
  
  string instructionFile = "data1.memory";

  //int used to store # of instructions, must be <= 100
  int numOfInstructions = 0;

  //
  string arrayOfInstructions[100][2];

  //
  ifstream infile;
  infile.open(instructionFile);
  	if (!infile.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
  
  // Loop should run until eof().
  while(infile.good())
  {
      string input;
      infile >> input;
      
      arrayOfInstructions[numOfInstructions][0] = input.substr(0,8);
      arrayOfInstructions[numOfInstructions][1] = input.substr(9,8);
      
      numOfInstructions++;

  }

  infile.close();

  for(int i = 0; i < numOfInstructions; i++)
  {

    cout << arrayOfInstructions[i][0] << endl;
    cout << arrayOfInstructions[i][1] << endl;

  }

  return 0;
}