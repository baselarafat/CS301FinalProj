#include <iostream>
#include <cstring>
#include <fstream>
#include "InstructionMemory.h"
#include "ProgramCounter.h"
#include <string>
#include <sstream>
#include <map>
#include "DataMemory.h"
#include "ControlUnit.h"
#include "ALU.h"
#include "Multiplexor.h"
#include "Instruction.h"
#include "ShiftLeftTwo.h"
#include "SignExtend.h"
#include "Converter.h"

using namespace std;
class Tester{
  public:
   Tester(){
  }
};
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

 

  //int used to store # of instructions, must be <= 100
  int numOfMemcells = 0;
  DataMemory* dm = new DataMemory (dataMemoryFile);
  string memdata = dm->getdata("0x10000000");
  // std::cout<<memdata<<std::endl;

  //dm->dmemPrint();
  //map<string,string>::iterator it = dm->mem.begin();
  //it++;
  //while(it != dm->mem.end())
  //{
   // std::cout<< it->first << ":" << it->second <<endl;
    //it++;
  //}
  //dm->dmemPrintFinal("output.mem");

  // RegisterFile registerFile();


  // //For loops runs so the values in arrayOfRegisters get 
  // //stored into the Register file
  // for(int i = 0; i < numOfRegisters; i++)
  // {
  //     registerFile.writeReg(arrayOfRegisters[i][0], arrayOfRegisters[i][1])
  // }

 
 // }
//------------------------------------------------------------------//
//------------------------------------------------------------------//
//------------------------------------------------------------------//
//------------------------------------------------------------------//
//------------------------------------------------------------------//




//This is an example of how to get Instructions from the Instruction from the InstructionMemory 
  //In this example I'm getting the in

    InstructionMemory* im = new InstructionMemory (programInputFile);
    Instruction i = im->getInstruction("0x40000008");
    string s = i.getString();
    cout<<s<<endl;


    std::cout<<std::endl;
 
    //Sets first address at the start and creates Program Counter Object
    
    string firstAddress = "40000000";
    ProgramCounter pc(firstAddress);
    

    //Creates controlunit object.
    ControlUnit* control = new ControlUnit ();
 

    //build 5 Multiplexors
    Multiplexor* mux1 = new Multiplexor ();
    Multiplexor* mux2 = new Multiplexor ();
    Multiplexor* mux3 = new Multiplexor ();
    Multiplexor* mux4 = new Multiplexor ();
    Multiplexor* mux5 = new Multiplexor ();
    

    ALU* ALU1 = new ALU();// only ADD
    ALU* ALU2 = new ALU();// ADD and ALU Result
    ALU* ALU3 = new ALU();// ALU and ALU Result

    //OpcodeTable opt = OpcodeTable();

    RegisterFile* regFile = new RegisterFile(registerFile);

    
  
  // Loop should run until end of program
  while(im->isValidInstruction(pc.getCurrentAddress())) 
  {
  

    //If the user chose to use single step mode, this code asks the user to
    //press y to continue, will continuously run until user enters y
    if(outputMode == "single_step"){
       
       while(true)
       {
          string x;
          cout << "Please enter y to move to the next step in the Program!" << endl;
          cin >> x;
          if(x == "y")
          { 
            break;
          }
      }
    }
    //FETCH 
    //Retrives address from the instruction memory as a string of 1s/0s.
    string addr = pc.getCurrentAddress();
    Instruction inst = im->getInstruction(addr); 
    if(debugMode)
    {
       cout << "The address being run in this iteration: " << addr << endl;
       cout << "The instruction referenced by the above address: " << inst.getString() << endl;
    }

    std::string binaddre = Converter::hexToBinary(addr);
    std::cout<<binaddre<<std::endl;
   
    //Adds 4 to current address and stores the result.
    ALU1->setInput_1(binaddre);
    ALU1->setInput_2("100");
    ALU1->setOperation("add");
    ALU1->performOperation();
    string add4ToAddress = ALU1->getResult(); 
    if(debugMode)
    {
       cout << "Result of adding 4 to the address: " << add4ToAddress << endl;
    }

    //retrives opcode from instruction

    // Opcode op =  opt.getOpcode(inst.getString());
   
    //sets values to false to reset control unit, then calls method
    //to set control values with opcode.
    control->setToZero();
   
    //resets values in control unit
    control->setValues(inst.getEncoding().substr(0,6));

    mux1->setFlow(control->getRegDest());
    mux2->setFlow(control->getAluSrc());
    mux3->setFlow(control->getmemToReg());
    mux4->setFlow(control->getJump());
    // mux 5 is set by a combination of branch and the result of ALU
    
    //always goes to read register1
    string reg1 = inst.getEncoding().substr(6, 5);
    
    //goes to read register 2 and mux1
    string reg2 = inst.getEncoding().substr(11, 5);
    
    //goes to mux1
    string reg3 = inst.getEncoding().substr(16, 5);

    //gets last15 didgets of instruction
    string immediate = inst.getEncoding().substr(17, 15); 

    cout << immediate << endl;


    //get j type address
    string jAddress = inst.getEncoding().substr(6, 25);
    cout << jAddress << " " << jAddress.length();


    //function code 
    string functCode = inst.getEncoding().substr(26, 6);



    
    if(debugMode)
    {
       cout << "Printing: reg1, reg2, reg3, immediate, functCode, jAddress" << endl;
       cout << reg1 << " " << reg2 << " " << reg3 << " " << immediate 
       << " " << functCode << endl << jAddress << endl;

    }


    //Shifts the instruction to the left
    string jInstSl2 = ShiftLeftTwo::Shift(jAddress); 
    
    //test for shift left 
    if(debugMode)
    {
       cout << jInstSl2 << endl;
    }

      mux4->setSecondInput(jInstSl2); // must wait for result of Mux5

       //Sends reg2 and reg3 to mux, based on control 

       mux1->setFirstInput(reg2);
       mux1->setSecondInput(reg3);

       //write register gets value from  mux1
       string writeRegister = mux1->mux();

       bitset<5> reg1bit (reg1);
       bitset<5> reg2bit (reg2);

       int reg1int = reg1bit.to_ulong();
       int reg2int = reg2bit.to_ulong();


       string valAtReg1 = regFile->readReg(to_string(reg1int));
       string valAtReg2 = regFile->readReg(to_string(reg2int));
       
       string valAtReg1Bin = Converter::hexToBinary(valAtReg1);
       string valAtReg2Bin = Converter::hexToBinary(valAtReg2);

     //test for mux1
     if(debugMode)
     {
        cout <<  "Testing values in read registers and the write register after mux" << endl;
        cout <<  "Value in read reg1: " << valAtReg1 << endl;
        cout <<  "Value in read reg2: " << valAtReg2 << endl;
        cout <<  "Value in write register: " << writeRegister << endl;
     }

    
       bitset<16> immbit (immediate);
       string extended = SignExtend::Extend(immbit);
       if(debugMode)
       {
          cout << "Testing sign extend: " << extended << endl;
          cout << extended.length() << endl;
       }

       //second mux decided if imm or register 2 should go to the ALU
       //extended in bin, val at reg2 is in hex rn
       mux2->setFirstInput(valAtReg2Bin);
       mux2->setSecondInput(extended);

       //calls second mux to determine second input for alu
       string aluInput = mux2->mux();

       ALU3->setInput_1(valAtReg1Bin);
       ALU3->setInput_2(valAtReg2Bin);


      if(debugMode)
      {
        cout << "Second input for ALU3: " << aluInput << endl;
      }

    //The following code acts as the ALU control for ALU3
    
    string alu3Result;
    if(control->getAluOp1() == 1 || control->getAluOp0() == 1)
    { 
        if(control->getAluOp1() == 1)
        {
            //SLT, ADD, SUB, SLT
           if(functCode == "100000") 
           {
              //Add
              ALU3->setOperation("add");
              ALU3->performOperation();
              alu3Result = ALU3->getResult();
              
              if(debugMode)
              {
                cout << "Add runs" << endl;
              }
           }
           if(functCode == "100010")
           {
              //Subtract
              ALU3->setOperation("sub");
              ALU3->performOperation();
              alu3Result = ALU3->getResult();
              if(debugMode)
              {
                cout << "subtract runs" << endl;
              }
             
           }
           if(functCode == "101010")
           {
              //SLT instruction, not yet implemented in ALU
              
           }
        }
           //Result gets "equal" or "not equal"
           else if(control->getAluOp0() == 1)
           {
              ALU3->setOperation("compare");
              ALU3->performOperation();
              alu3Result = ALU3->getResult();
          }
           
    
    } else {
        //runs for lw and sw 
        ALU3->setOperation("add");
        ALU3->performOperation();
        alu3Result = ALU3->getResult();
        

    }

    if(debugMode)
    {
      cout << "Result from ALU3: " << alu3Result << endl;
    }

    if(control->getBranch() == 1 && alu3Result == "equal")
    {
      // if this runs it is a branch instruction AND the branch
      // condition passed.  Basically the AND in the data path.
        mux5->setFlow(control->getBranch());

    } else {
      //Not needed but avoids an unused warning for mux5 if no branches
      mux5->setFlow(0);
    }

    //if there is a memory write (sw) it occurs here
     if(control->getMemWrite() == 1)
    {
        
      // valAtReg2 is value to be written
      // address to be written to is alu3 result(needs to be converted to hex)
      dm->writeMem(Converter::binaryToHex(alu3Result), valAtReg2);
      
    }
    //sends result of the alu to the 3rd multiplexor
    mux3->setFirstInput(alu3Result);
    if(control->getMemRead() == 1)
    {
       //runs if op uses a memory read, and sends value to the 3rd multiplexor
       string dataFromMem = dm->getdata(alu3Result);
       mux3->setSecondInput(dataFromMem);
      
      if(debugMode)
      {
          cout << "Value read from memory: " << dataFromMem << endl;
      }

    }


    //checks to see if it is writting to a register from mux3.
    if(control->getRegWrite() == 1)
    {
       string writeData = mux3->mux();
       // remeber string writeRegister holds in the reg
       // code below should write the given value to the register
       if(debugMode)
      {
          cout << "Value being written to reg " << writeData << endl;
      }

      string writeDataHex = Converter::binaryToHex(writeData);
      bitset<5> writebit (writeRegister);
      int writeInt = writebit.to_ulong();
      
      cout << "Reg before register write: " << regFile->readReg(to_string(writeInt)) << endl;
      regFile->writeReg(to_string(writeInt), writeDataHex);

      if(debugMode)
      {
          cout << "Value in reg: " << regFile->readReg(to_string(writeInt)) << endl;
      }

    }



    //Shifts the previously exstended address by 2 bits(needed for b and j)
    string instructionShiftedLeft = ShiftLeftTwo::Shift(extended);
    if(debugMode)
      {
          cout << "Extended immediate value: " << immediate << endl;
          cout << "Value shifted left by two bits: " << instructionShiftedLeft << endl;
      }

      //Add this value to current PC value(This doesnt make sense to me...)
      ALU2->setInput_1(add4ToAddress);
      ALU2->setInput_2(instructionShiftedLeft);
      ALU2->setOperation("add");
      ALU2->performOperation();
      string resultOfAlu2 = ALU2->getResult();

      if(debugMode)
      {
          cout << "Result of ALU2: " << resultOfAlu2 << endl;
      }

      mux5->setFirstInput(add4ToAddress);
      mux5->setSecondInput(resultOfAlu2);

      string resultOfMux5 = mux5->mux();

      if(debugMode)
      {
          cout << "Result of Mux5: " << resultOfMux5 << endl;
      }

    mux4->setFirstInput(resultOfMux5);
    
    string resultOfMux4 = mux4->mux(); //result that is going to program counter

    if(debugMode)
      {
          cout << "Result of mux4: " << resultOfMux4 << endl;
      }

    //
    string hexFinalAddress = Converter::binaryToHex(resultOfMux4);
    if(debugMode)
      {
          cout << "Address being sent to PC: " << hexFinalAddress << endl;
      }


    //Updates program counter with correct address
    pc.moveAddressTo(hexFinalAddress);

    //prints the register memory and the datamemory after each instruction if true.
    if(printMemoryContents)
    {
       cout << "Printing the contents of the registers" << endl;
       regFile->printContents();
       
       cout << "Printing the contents of the data memory" << endl;
       dm->dmemPrint();

    }


  }


  //Testing stuff 

//   stringstream ss (s4);
  
//   for(int i=0;i<10;i++){
//      int x;
//     ss>>hex>>x;
//   ss<<hex<<x;
//   x=x+4;

  
//   string s5 =ss.str();
//   std::cout<<hex<<x<<std::endl;

//   std::cout<<mem.at(s5)<<std::endl;
// }
// string s4 ="4000000";
// Tester t ;
// for(int i=0;i<9;i++){
// int x = t.hextoint(s4);
// x=x+4;
// s4 =t.inttohex(x);
// std::cout<<instructions.at(s4)<<endl;
// }

  return 0;

}
