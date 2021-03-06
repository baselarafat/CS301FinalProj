/*
This class has three important variables, flow, input 1 and input 2.  
The flow is set by the control unit and the inputs are sent to each 
multiplexor in the datapath.  Based on the flow given by the control 
the multiplexor sends that value to continue in the datapath.
*/
#ifndef __MULTIPLEXOR_CPP__
#define __MULTIPLEXOR_CPP__

#include <iostream>
#include "Multiplexor.h"

Multiplexor::Multiplexor(){}

Multiplexor::~Multiplexor(){}

///will be used by the Control Unit, which sends true or false based 
///on whether or not the mux is needed.
//@param int Sets the flow for the mux
void Multiplexor::setFlow(int flow)
{
    this->flow = flow;
    
}
///Returns signal for testing 
//@return int Returns the flow value 
int Multiplexor::getFlow()
{
    return flow;
}

///Set's input at point that coincides with 0 on the picture
//@param string The first input to the mux (coincides with the 0 in the processor)
//@return string Returns value input for testing
std::string Multiplexor::setFirstInput(std::string firstInput)
{
	this->firstInput = firstInput;
	return this->firstInput;
}

///Sets input at 1 that coincides with 1 on the picture
//@param string The second input to the mux (coincides with the 1 in the processor)
//@return string Returns value input for testing
std::string Multiplexor::setSecondInput(std::string secondInput)
{
	this->secondInput = secondInput;
	return this->secondInput;
}


///calls mux and returns the result chosen
//@return string Result chosen by multiplexor
std::string Multiplexor::mux()
{
	if(this->flow == 0)
	{
		return this->firstInput;
	}
	else
	{
		return this->secondInput;
	}

}


#endif /// MULTIPLEXOR_CPP_
