///SignExtend Class 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
#ifndef __ALUCONTROL_H__
#define __ALUCONTROL_H__

#include <string>

class ALUControl
{
	public:
		ALUControl(){}
		~ALUControl(){}

	static std::string getOperation(int aluop1, int aluop0, std::string functCode)
	{
		if(aluop1 == 1 || aluop0 == 1)
        { 
            if(aluop1 == 1)
            {  
                ///SLT, ADD, SUB, SLT
               if(functCode == "100000") 
               {
                    return "add";
             
               }
               if(functCode == "100010")
               {
                    return "sub";
             
               }
               if(functCode == "101010")
               {
               
                    return "lessThan";
              
                }
            }
           ///Result gets "equal" or "not equal"
           else if(aluop0 == 1)
           {
              return "compare";
           }
           
        } else {
            return "add";
        }
        return "";
    }
	
};
#endif