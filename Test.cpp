#include <iostream>
#include <cstring>
#include <fstream>
#include "InstructionMemory.h"
#include "ProgramCounter.h"
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

  RegisterFile registerFile();

  //For loops runs so the values in arrayOfRegisters get 
  //stored into the Register file
  for(int i = 0; i < numOfRegisters; i++)
  {
      registerFile.writeReg(arrayOfRegisters[i][0], arrayOfRegisters[i][1])
  }

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
    */
   // string instructionArray[100][2];
    
    /*
    if(parser->isFormatCorrect() == false){
        cerr << "Format of program input file is incorrect " << endl;
        exit(1);
    }

    Instruction i;

    i = parser->getNextInstruction();
    
    int instructionCounter = 0;
    while( i.getOpcode() != UNDEFINED || instructionCounter <= 100){
        //Puts values into array, prints them for testing purposes.
        cout << i.getString() << endl;
        instructionArray[instructionCounter][1];
        
        //cout << i.getEncoding() << endl;
        i = parser->getNextInstruction();
    }
    
    delete parser;
    */
    
    
    //Sets null value into instructionArray.
  


    //Code below will begin using imput to simulate a processor.  First all objects needed 
    // for the execution will be created.
    
    //Sets first address at the start and creates Program Counter Object
    /*
    string firstAddress = "1000000";
    ProgramCounter pc(firstAddress);
    
    //Creates IM using the array built above.
    InstructionMemory im(instructionArray);
    
    //Creates controlunit object.
    ControlUnit control();

    //build 5 Multiplexors
    Multiplexor mux1();
    Multiplexor mux2();
    Multiplexor mux3();
    Multiplexor mux4();
    Multiplexor mux5();
    
    RegisterFile registerFile();
    //while() // Loop to run until all instructions are executed.
    //Code that asked user to enter y after each instruction is executed.
    if(outputMode = "single_step")
       
       while(true)
       {
          string x;
          cout << "Please enter y to continue execution!" << endl;
          cin >> x;
          if(x == "y")
          { 
            break;
          }
      }

    //FETCH 
    //Retrives address from the instruction memory as a string of ints.
    string addr = pc.getCurrentAddress();
    string instruction = im.(addr); 
    
    //Sends address to ALU next?

    string opcode = instruction.substr(0, 6);

    //sets values to false to reset control unit, then calls method
    //to set control values with opcode.
    control.setToFalse();
    control.setValues(opcode);

    mux1.setFlow(control.getRegDest());
    mux2.setFlow(control.getAluSrc());
    mux3.setFlow(control.getMemToReg());
    mux4.setFlow(control.getJump());
    // mux 5 is set by a combination of branch and the result of ALU
    
    //always goes to read regester1
    string reg1 = instruction.substr(6,5);
    
    //goes to read register 2 and mux1
    string reg2 = instruction.substr(11, 5);
    
    //goes to mux1
    string reg3 = instruction.substr(16, 5);

    //gets last15 didgets of instruction
    string last15Digits = instruction.substr(16, 16); 

    // string extended15 = SIGN EXTEND 15 once Sign Extend is added

    string functCode = instruction.substr(27, 5);

    // SEND FUNCTCODE to the ALU CONTROL!

    //gets values from reg1 and reg 2
    string valAtReg1 = readReg(reg1);
    string valAtReg2 = readReg(reg2);

    //Sends reg2 and reg3 to mux, based on control 
    mux1.setFirstInput(reg2);
    mux1.setSecondInput(reg3);

    string writeRegister = mux1.mux();
  
  */




  
  return 0;
}
