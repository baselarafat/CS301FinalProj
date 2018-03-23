#ifndef __PROGRAM_COUNTER_H__
#define __PROGRAM_COUNTER_H__

#include <string>
//This h creates the guidlines for the program counter


// forward declarations needed can go below


class ProgramCounter
{
   private:
      int            currentAddress;
      std::string    addressArray[32];

   public:
      ProgramCounter();
      ~ProgramCounter();

      // getCurrentAddress will return the current address of the program 
      // counter as a string
      std::string    getCurrentAddress();
    
      // returns the pointer in the array for the current address
      int       getAddressPointer();
    
      //moveAddressTo will move the address in the PC to a given point, will
      //will be used for j type and branch instructions
      std::string    moveAddressTo(std::string newAddress);

      //Increments the current address by one
      std::string    incrementAddress();
     
     // Note: string is returned for the two methods above for testing purposes
};

#endif
