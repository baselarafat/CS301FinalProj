#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

int main ()
{
  
  //writting code to read the configuration file
  //will read contents of the file and save information set up
  //to be used by the program.

  //This should be changed to take command line argument (I think?)
  string configFile = "input.config";
  
  string programInputFile;
  string dataMemoryFile;
  string registerFile;
  string outputMode;
  string outputFile;

  bool debugMode;
  bool printMemoryContents;
  bool writeToFile;



  ifstream infile;
  
  //opens file then make sure it was successful
  infile.open(configFile);
    if (!infile.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }

    //loop to run once for each config
    for(int i = 0; i < 8; i++)
    {
      string configInput;
      infile >> configInput;

      string configResult;
      int pointerToEquals = 0;

      //loops through string until it finds equals
      //sets pointer to j
      for(int j = 0; j < configInput.length(); j++)
      {
          if(configInput.at(j) == '=')
          {
              pointerToEquals = j+1;
              break;
          }
      }

      //gets the part of the input after the equals sign
      configResult = configInput.substr(pointerToEquals);


      //this block of code adds the values from the config file to 
      //the appropriate variable.
      switch(i) 
      {
          case: 0 :
            programInputFile = configResult;
            break;

          case: 1 :
            dataMemoryFile = configResult;
            break;

          case: 2 :
            registerFile = configResult;
            break;

          case: 3 :
            outputMode = configResult;
            break;

          case: 4 :
            if(configResult.at(0) == 'f')
            {
              debugMode = false;
            } 
            else 
            {
              debugMode = true;
            }
            break;

          case: 5 :
            if(configResult.at(0) == 'f')
            {
              printMemoryContents = false;
            } 
            else 
            {
              printMemoryContents = true;
            }
            break;
          
          case: 6 :
            outputFile = configResult;
            break;

          case: 7 :
            if(configResult.at(0) == 'f')
            {
              writeToFile = false;
            } 
            else 
            {
              writeToFile = true;
            }
            break;
      }     

    
    }

    infile.close();

  // writting code to read the data memory file.
  // will read data and build a 2d array that can be used
  // to construct the instruction memory.

  //int used to store # of instructions, must be <= 100
  int numOfInstructions = 0;

  //builds array to store instructions
  string arrayOfInstructions[100][2];

  //
  ifstream infile;
  infile.open(dataMemoryFile);
  	if (!infile.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
  
  // Loop should run until eof().
  while(infile.good())
  {
      //creates string and saves each line to input
      string input;
      infile >> input;
      
      //puts address in
      arrayOfInstructions[numOfInstructions][0] = input.substr(0,8);
      //puts instruction in
      arrayOfInstructions[numOfInstructions][1] = input.substr(9,8);
      //increments number of instructions
      numOfInstructions++;

  }

  infile.close();

  //Loop to test file reading from above.  No problems as of current implementation.
  for(int i = 0; i < numOfInstructions; i++)
  {

    cout << arrayOfInstructions[i][0] << endl;
    cout << arrayOfInstructions[i][1] << endl;

  }

  return 0;
}