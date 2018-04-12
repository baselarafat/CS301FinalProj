#include <iostream>
#include <cstring>
#include <fstream>
#include "InstructionMemory.h"
#include <string>
#include <vector>





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



  ifstream infile1;
  
  //opens file then make sure it was successful
  infile1.open(configFile);
    if (!infile1.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
    //loop to run once for each config
    for(int i = 0; i < 8; i++)
    {
      string configInput;
      infile1 >> configInput;

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
          case 0 :
            programInputFile = configResult;
            break;

          case 1 :
            dataMemoryFile = configResult;
            break;

          case 2 :
            registerFile = configResult;
            break;

          case 3 :
            outputMode = configResult;
            break;

          case 4 :
            if(configResult.at(0) == 'f')
            {
              debugMode = false;
            } 
            else 
            {
              debugMode = true;
            }
            break;

          case 5 :
            if(configResult.at(0) == 'f')
            {
              printMemoryContents = false;
            } 
            else 
            {
              printMemoryContents = true;
            }
            break;
          
          case 6 :
            outputFile = configResult;
            break;

          case 7 :
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

    infile1.close();

  // writting code to read the data memory file.
  // will read data and build a 2d array that can be used
  // to construct the instruction memory.

  //int used to store # of instructions, must be <= 100
  int numOfInstructions = 0;

  //builds array to store instructions
  vector<vector<string> > vec(100); 


  //
  ifstream infile2;
  infile2.open(dataMemoryFile);
  	if (!infile2.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
  // Loop should run until eof().
  while(infile2.good())
  {
    
     vec[numOfInstructions] = vector<string>(2);
      //creates string and saves each line to input
     string input;
      infile2 >> input;
      int delimiter =input.find(":");
      //puts address in
      vec[numOfInstructions][0] = input.substr(0,delimiter);
      //puts instruction in
     vec[numOfInstructions][1] = input.substr(delimiter+1,input.length()-1);
      //increments number of instructions
      numOfInstructions++;
   }

  infile2.close();

   //builds array to store registers
  string arrayOfRegisters[32][2];

  int numOfRegisters = 0;

  //
  ifstream infile3;
  infile3.open(registerFile);
    if (!infile3.is_open()) {
        cerr << "An error has occured when opening the file";
        exit(1); 
    }
  
  // Loop should run until eof().
  while(infile3.good())
  {
      //creates string and saves each line to input
      string input;
      infile3 >> input;
      
      int equalsPtr = 0;
      
      //gets location of the =
      for(int k = 0; k < input.length(); k++)
        {
            if(input.at(k) == '=')
            {
              equalsPtr = k;
              break;
            }
        }
      arrayOfRegisters[numOfRegisters][0] = input.substr(0,equalsPtr);
      //puts instruction in
      arrayOfRegisters[numOfRegisters][1] = input.substr(equalsPtr + 1,8);
      //increments number of instructions
      numOfRegisters++;

  }

  infile3.close();

 // Loop to test file reading from above. 
 //  for(int i=0;i<100;i++){
 //   std::cout<<vec[i][0];
 //   std::cout<<"---";
 //   std::cout<<vec[i][1];
 //   std::cout<<std::endl;
 // }

   InstructionMemory* Inst = new InstructionMemory (vec);
    string s = Inst->getInstruction("1000006c");
    cout <<"-------"<<s<<endl;
    cout<<s<<endl;

  std::cout<<std::endl;


    /*
    Iterates through instructions, and sends them to the Instruction memory.
    The below code is from the lab4 parser class, and will find the encodings 
    for a given programInputFile found above.  Once the other files are added to the 
    folder it should run and collect instructions in binary to be used in the program.

    ASMParser *parser;

    parser = new ASMParser(programInputFile);

    if(parser->isFormatCorrect() == false){
        cerr << "Format of program input file is incorrect " << endl;
        exit(1);
    }

    Instruction i;

    i = parser->getNextInstruction();

    while( i.getOpcode() != UNDEFINED){
        // cout << i.getString() << endl;
        cout << i.getEncoding() << endl;
        i = parser->getNextInstruction();
    }
    
    delete parser;
    */

    //Code below will begin utilizizing the given input to run the processor based on
    //the given input.  (A new class could be created such that once this runs, it sends 
    //the info to that class needed to run the processor).

    //FETCH

    
}
  
  return 0;
}
