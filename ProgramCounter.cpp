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
#include <string>

// This creates the program counter object

    ProgramCounter::ProgramCounter()
    {
        // initializes contents of the PC array
        
        int i = 0;
        addressArray[i] = "0x0"; i++;
        addressArray[i] = "0x1"; i++;
        addressArray[i] = "0x2"; i++;
        addressArray[i] = "0x3"; i++;
        addressArray[i] = "0x4"; i++;
        addressArray[i] = "0x5"; i++;
        addressArray[i] = "0x6"; i++;
        addressArray[i] = "0x7"; i++;
        addressArray[i] = "0x8"; i++;
        addressArray[i] = "0x9"; i++;
        addressArray[i] = "0xa"; i++;
        addressArray[i] = "0xb"; i++;
        addressArray[i] = "0xc"; i++;
        addressArray[i] = "0xd"; i++;
        addressArray[i] = "0xe"; i++;
        addressArray[i] = "0xf"; i++;
        addressArray[i] = "0x10"; i++;
        addressArray[i] = "0x11"; i++;
        addressArray[i] = "0x12"; i++;
        addressArray[i] = "0x13"; i++;
        addressArray[i] = "0x14"; i++;
        addressArray[i] = "0x15"; i++;
        addressArray[i] = "0x16"; i++;
        addressArray[i] = "0x17"; i++;
        addressArray[i] = "0x18"; i++;
        addressArray[i] = "0x19"; i++;
        addressArray[i] = "0x1a"; i++;
        addressArray[i] = "0x1b"; i++;
        addressArray[i] = "0x1c"; i++;
        addressArray[i] = "0x1d"; i++;
        addressArray[i] = "0x1e"; i++;
        addressArray[i] = "0x1f"; i++;
    }


    
        ProgramCounter::~ProgramCounter(){}
    
    
        // getCurrentAddress will return the current address of the program
        // counter as a string
std::string    ProgramCounter::getCurrentAddress()
        {
            return addressArray[this->currentAddress];
        }
    
        // returns the pointer in the array for the current address
int ProgramCounter::getAddressPointer()
        {
            return currentAddress;
        }
    
    
        //moveAddressTo will move the address in the PC to a given point, will
        //will be used for j type and branch instructions
std::string    ProgramCounter::moveAddressTo(std::string newAddress)
    {
            return "";
    }
    
        //Increments the current address by one
std::string ProgramCounter::incrementAddress()
        {
            this->currentAddress++;
            return addressArray[this->currentAddress];
        }
    
        // Note: string is returned for the two methods above for testing purposes


#endif
#include <stdio.h>
