//
//  ProgramCounter.cpp
//  
//
//  Created by Will Saada on 3/15/18.
//
//
#ifndef __PROGRAM_COUNTER_CPP__
#define __PROGRAM_COUNTER_CPP__

#include "ProgramCounter.h"

// This creates the program counter object

class ProgramCounter
{
    // initializes contents of the PC array
    int i = 0;
    addressArray[i].name = "0x0"; i++;
    addressArray[i].name = "0x1"; i++;
    addressArray[i].name = "0x2"; i++;
    addressArray[i].name = "0x3"; i++;
    addressArray[i].name = "0x4"; i++;
    addressArray[i].name = "0x5"; i++;
    addressArray[i].name = "0x6"; i++;
    addressArray[i].name = "0x7"; i++;
    addressArray[i].name = "0x8"; i++;
    addressArray[i].name = "0x9"; i++;
    addressArray[i].name = "0xa"; i++;
    addressArray[i].name = "0xb"; i++;
    addressArray[i].name = "0xc"; i++;
    addressArray[i].name = "0xd"; i++;
    addressArray[i].name = "0xe"; i++;
    addressArray[i].name = "0xf"; i++;
    addressArray[i].name = "0x10"; i++;
    addressArray[i].name = "0x11"; i++;
    addressArray[i].name = "0x12"; i++;
    addressArray[i].name = "0x13"; i++;
    addressArray[i].name = "0x14"; i++;
    addressArray[i].name = "0x15"; i++;
    addressArray[i].name = "0x16"; i++;
    addressArray[i].name = "0x17"; i++;
    addressArray[i].name = "0x18"; i++;
    addressArray[i].name = "0x19"; i++;
    addressArray[i].name = "0x1a"; i++;
    addressArray[i].name = "0x1b"; i++;
    addressArray[i].name = "0x1c"; i++;
    addressArray[i].name = "0x1d"; i++;
    addressArray[i].name = "0x1e"; i++;
    addressArray[i].name = "0x1f"; i++;
    


    
    
    public:
        ProgramCounter::ProgramCounter()
        {
            currentAddress = 0;
        }
        ~ProgramCounter::ProgramCounter(){}
    
    
        // getCurrentAddress will return the current address of the program
        // counter as a string
        string    getCurrentAddress()
        {
            return addressArray[this.currentAddress];
        }
    
        // returns the pointer in the array for the current address
        int getAddressPointer()
        {
            return currentAddress;
        }
    
    
        //moveAddressTo will move the address in the PC to a given point, will
        //will be used for j type and branch instructions
        string    moveAddressTo(string newAddress);
    
        //Increments the current address by one
        string incrementAddress()
        {
            this.currentAddress++;
            return addressArray[this.currentAddress];
        }
    
        // Note: string is returned for the two methods above for testing purposes
};

#endif
#include <stdio.h>
