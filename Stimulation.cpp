#include"Stimulation.h"

void Stimulation::getFiles(){
  ConfigurationParser* coparser = new ConfigurationParser (configFile);
  coparser->Parseit();
  programInputFile= coparser->getprogramInputFile();
  dataMemoryFile=coparser->getdataMemoryFile();
  registerFile=coparser->getregisterFile();
  outputMode=coparser->getoutputMode();
  outputFile=coparser->getoutputFile();
  debugMode=coparser->getdebugMode();
  printMemoryContents=coparser->getprintMemoryContents();
  writeToFile=coparser->getwriteToFile();
}
void Stimulation::run ()
{
  getFiles();

  ///int used to store # of instructions, must be <= 100
  
  DataMemory* dm = new DataMemory (dataMemoryFile);
  string memdata = dm->getdata("0x10000000");
 
 /// }
///------------------------------------------------------------------///
///------------------------------------------------------------------///
///------------------------------------------------------------------///
///------------------------------------------------------------------///
///------------------------------------------------------------------///
    ///Parser is run through instruction memory to initializes instructions
    /// Initializes the instruction memory with the input file.
    InstructionMemory* im = new InstructionMemory (programInputFile);
    if(debugMode)
    {
      cout << "Testing third instruction slot to make sure instruction memory"
      "was initialized correctly." << endl;
      /// Instruction i = im->getInstruction("0x04000008");
      /// string s = i.getString();
      /// cout<<s<<endl;
    }


    ///Sets first address at the start and creates Program Counter Object
    string firstAddress = "04000000";
    ProgramCounter pc(firstAddress);
    

    ///Creates controlunit object.
    ControlUnit* control = new ControlUnit ();
 

    ///build 5 Multiplexors
    Multiplexor* mux1 = new Multiplexor ();
    Multiplexor* mux2 = new Multiplexor ();
    Multiplexor* mux3 = new Multiplexor ();
    Multiplexor* mux4 = new Multiplexor ();
    Multiplexor* mux5 = new Multiplexor ();
    

    ALU* ALU1 = new ALU();/// only ADD
    ALU* ALU2 = new ALU();/// ADD and ALU Result
    ALU* ALU3 = new ALU();/// ALU and ALU Result


    RegisterFile* regFile = new RegisterFile(registerFile);

    
  /// Loop should run until end of program, ends when the 
  /// instruction memory gets to an invalid program.
  while(im->isValidInstruction(pc.getCurrentAddress())) 
  {
  
    ///If the user chose to use single step mode, this code asks the user to
    ///press y to continue, will continuously run until user enters y
    if(outputMode == "single_step"){
       
       while(true)
       {
          string x;
          cout << "Please enter y to move to the next step in the Program or enter n to exit the Program!" << endl;
          cin >> x;
          if(x == "y")
          { 
            break;
          }
          if(x == "n")
          {
            exit(1);
          }
      }
    }
    ///FETCH 
    ///Retrives address from the instruction memory as a string of 1s/0s.
    string addr = pc.getCurrentAddress();
    Instruction inst = im->getInstruction(addr); 
   
    
       // cout << "The address being run in this iteration: " << addr << endl;
       cout << "The instruction referenced by the above address: " << inst.getString() << endl;
    


    std::string binaddre = Converter::hexToBinary(addr);
    std::cout<<binaddre<<std::endl;
   
    ///Adds 4 to current address and stores the result.
    ALU1->setInput_1(binaddre);
    ALU1->setInput_2("100");
    ALU1->setOperation("add");
    ALU1->performOperation();
    string add4ToAddress = ALU1->getResult(); 
    if(debugMode)
    {
       cout << "Result of adding 4 to the address: " << add4ToAddress << endl;
    }

    ///sets values to false to reset control unit, then calls method
    ///to set control values with opcode.
    control->setToZero();
   
    ///resets values in control unit
    control->setValues(inst.getEncoding().substr(0,6));

    mux1->setFlow(control->getRegDest());
    mux2->setFlow(control->getAluSrc());
    mux3->setFlow(control->getmemToReg());
    mux4->setFlow(control->getJump());
    /// mux 5 is set by a combination of branch and the result of ALU
    
    if(debugMode)
    {
      cout << "Instruction (as string of 32 bits): " << inst.getEncoding() << endl;
    }

    ///always goes to read register1
    string reg1 = inst.getEncoding().substr(6, 5);
    
    ///goes to read register 2 and mux1
    string reg2 = inst.getEncoding().substr(11, 5);
    
    ///goes to mux1
    string reg3 = inst.getEncoding().substr(16, 5);

    ///gets last15 didgets of instruction
    string immediate = inst.getEncoding().substr(17, 15); 

    ///get j type address
    string jAddress = inst.getEncoding().substr(6, 26);
    if(debugMode)
    cout << "Address for Jump: " << jAddress << endl;


    ///function code 
    string functCode = inst.getEncoding().substr(26, 6);

    if(debugMode)
    {
       cout << "Printing: reg1, reg2, reg3, immediate, functCode, jAddress" << endl;
       cout << reg1 << " " << reg2 << " " << reg3 << " " << immediate 
       << " " << functCode << endl <<hex<< jAddress << endl;

    }


    ///Shifts the value to the left (value used for address in jtype)
    string jInstSl2 = ShiftLeftTwo::Shift(jAddress); 
    
    ///test for shift left 
    if(debugMode)
    {
      cout << "Below is the jump instruction shifted left 2" << endl;
      cout << jInstSl2 << endl;
    }

       mux4->setSecondInput(jInstSl2); /// must wait for result of Mux5

       ///Sends reg2 and reg3 to mux1
       mux1->setFirstInput(reg2);
       mux1->setSecondInput(reg3);

       ///write register gets value from mux1
       ///if a writeReg occurs this stores the register to be written to
       string writeRegister = mux1->mux();

       ///Converstion to bitset so a conversion to int can be done
       bitset<5> reg1bit (reg1);
       bitset<5> reg2bit (reg2);

       ///Converts from bitset to integer
       int reg1int = reg1bit.to_ulong();
       int reg2int = reg2bit.to_ulong();

       ///Readreg accepts decimal value as a string, so we use to string
       string valAtReg1 = regFile->readReg(to_string(reg1int));
       string valAtReg2 = regFile->readReg(to_string(reg2int));
       
       ///Converts values from hex (how its stored in register) to binary
       string valAtReg1Bin = Converter::hexToBinary(valAtReg1);
       string valAtReg2Bin = Converter::hexToBinary(valAtReg2);

     ///test for mux1
     if(debugMode)
     {
        cout <<  "Testing values in read registers and the write register after mux" << endl;
        cout <<  "Value in read reg1: " << valAtReg1 << endl;
        cout <<  "Value in read reg2: " << valAtReg2 << endl;
        cout <<  "Value of write register: " << writeRegister << endl;
     }
      
       ///sign extend accepts bitset.
       bitset<16> immbit (immediate);
       string extended = SignExtend::Extend(immbit);
       if(debugMode)
       {
          cout << "Testing sign extend: " << extended << endl;
          cout << extended.length() << endl;
       }

       ///second mux decided if imm or register 2 should go to the ALU
       ///extended in bin, val at reg2 is in hex rn
       mux2->setFirstInput(valAtReg2Bin);
       mux2->setSecondInput(extended);

       ///calls second mux to determine second input for alu
       string aluInput = mux2->mux();

       ALU3->setInput_1(valAtReg1Bin);
       ALU3->setInput_2(aluInput);


      if(debugMode)
      {
        cout << "FirstInput  of ALU3: " << valAtReg1Bin << endl;
        cout << "Secondinput of ALU3: " << aluInput << endl;
      }

    ///The following code acts as the ALU control for ALU3
    
/*    string alu3Result;
    if(control->getAluOp1() == 1 || control->getAluOp0() == 1)
    { 
        if(control->getAluOp1() == 1)
        {
            ///SLT, ADD, SUB, SLT
           if(functCode == "100000") 
           {
              ///Add
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
              ///Subtract
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
              ///SLT instruction, not yet implemented in ALU
              ALU3->setOperation("lessThan");
              ALU3->performOperation();
              alu3Result = ALU3->getResult();
              cout << alu3Result << endl;
              cout << endl;

              
           }
        }
           ///Result gets "equal" or "not equal"
           else if(control->getAluOp0() == 1)
           {
              ALU3->setOperation("compare");
              ALU3->performOperation();
              alu3Result = ALU3->getResult();
          }
           
    } else {
        ///runs for lw and sw 
        ALU3->setOperation("add");
        ALU3->performOperation();
        alu3Result = ALU3->getResult();
        

    }

*/
    string operation = ALUControl::getOperation(control->getAluOp1(), control->getAluOp0(), 
      functCode);
    cout << operation << endl;
    ALU3->setOperation(operation);
    ALU3->performOperation();
    string alu3Result = ALU3->getResult();

    if(debugMode)
    {
      cout << "Result from ALU3: " << alu3Result << endl;
    }

    if(control->getBranch() == 1 && alu3Result == "equal")
    {
      /// if this runs it is a branch instruction AND the branch
      /// condition passed.  Basically the AND in the data path.
        mux5->setFlow(control->getBranch());

    } else {
      ///Not needed but avoids an unused warning for mux5 if no branches
      mux5->setFlow(0);
    }

    ///if there is a memory write (sw) it occurs here
     if(control->getMemWrite() == 1)
    {
      string hexMemWrite = Converter::binaryToHex(alu3Result);
      
      string hexMemWriteFinal = Converter::hexify(hexMemWrite);

      /// valAtReg2 is value to be written
      /// address to be written to is alu3 result(needs to be converted to hex)
      valAtReg2 = Converter::hexify(valAtReg2);
      dm->writeMem(hexMemWriteFinal, valAtReg2);
      
    }
    ///sends result of the alu to the 3rd multiplexor
    string alu3ResultInHex = Converter::binaryToHex(alu3Result);
    mux3->setFirstInput(alu3ResultInHex);
    if(control->getMemRead() == 1)
    {

       //runs if op uses a memory read, and sends value to the 3rd multiplexor
       //aluresult needs to be translated to hex

       ///runs if op uses a memory read, and sends value to the 3rd multiplexor
       ///aluresult needs to be translated to hex
       string alu3ResultHex = Converter::binaryToHex(alu3Result);
       string finalHexMemRead = Converter::hexify(alu3ResultHex);

       string dataFromMem = dm->getdata(finalHexMemRead);
       cout << dataFromMem << endl;
       dataFromMem = dataFromMem.substr(2);

       mux3->setSecondInput(dataFromMem);
      
      if(debugMode)
      {
          cout << "Value read from memory: " << dataFromMem << endl;
      }

    }

    ///checks to see if it is writting to a register from mux3.
    if(control->getRegWrite() == 1)
    {
       string writeData = mux3->mux();
       /// remeber string writeRegister holds in the reg
       /// code below should write the given value to the register
       if(debugMode)
      {
          cout << "Value being written to reg " << writeData << endl;
      }

      ///so binary can be changed to int
      bitset<5> writebit (writeRegister);
      int writeInt = writebit.to_ulong();
      
      cout << "Reg before register write: " << regFile->readReg(to_string(writeInt)) << endl;
    
      regFile->writeReg(to_string(writeInt), writeData);

      if(debugMode)
      {
          cout << "Value in reg: " << regFile->readReg(to_string(writeInt)) << endl;
      }

    }

    ///Shifts the previously exstended address by 2 bits(needed for b and j)
    string instructionShiftedLeft = ShiftLeftTwo::Shift(extended);
    if(debugMode)
      {
          cout << "Extended immediate value: " << immediate << endl;
          cout << "Value shifted left by two bits: " << instructionShiftedLeft << endl;
      }

      ///Add this value to current PC value(This doesnt make sense to me...)
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
    
    string resultOfMux4 = mux4->mux(); ///result that is going to program counter

    if(debugMode)
      {
          cout << "Result of mux4: " << resultOfMux4 << endl;
      }

    ///
    string hexFinalAddress = Converter::binaryToHex(resultOfMux4);
    if(debugMode)
      {
          cout << "Address being sent to PC: " << hexFinalAddress << endl;
      }

    ///Updates program counter with correct address
    pc.moveAddressTo(hexFinalAddress);

    ///prints the control fields, register memory and datamemory 
    ///after each instruction if printMemoryContents is set to true.
    if(printMemoryContents)
    {
       cout << "Printing Control Fields for last instuction" << endl;
       control->printControl();

       cout << "Printing the contents of the registers" << endl;
       regFile->printContents();
       
       cout << "Printing the contents of the data memory" << endl;
       dm->dmemPrint();
    }
      cout << "Printing the contents of the instruction memory"<<endl;
      im->printContents();


  }
  if(writeToFile)
  {
  ofstream out;
  out.open(outputFile);
  out<<"The output has been printed to outdata.memory, outregister.memory, outinstruction.memory"<<endl;
  out.close();
  cout<<"The registermemory has been written to outregister.memory"<<endl;
  regFile->PrintFinal("outregister.memory");
   cout<<"The Instructionmemory has been written to outinstruction.memory"<<endl;
    im->imemPrintFinal("outinstruction.memory");
    cout<<"The Datamemory has been written to outdata.memory"<<endl;
      dm->dmemPrintFinal("outdata.memory");
      
  }
 
}