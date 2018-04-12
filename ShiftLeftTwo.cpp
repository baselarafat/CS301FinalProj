#ifndef __SHIFTLEFTTWO_CPP__
#define __SHIFTLEFTTWO_CPP__

#include "ShiftLeftTwo.h"
#include <bitset>

ShiftLeftTwo::ShiftLeftTwo() {}

ShiftLeftTwo::ShiftLeftTwo(std::bitset offsetfield)
{
	this->offsetfield = offsetfield;
}

// shifts the offset field to the left by two bits, making it a word offset
ShiftLeftTwo::~ShiftLeftTwo(){}

std::string	Shift(std::bitset offsetField)
{
	bitset<16> shiftedOffSet = offsetField << 2;
	return shiftedOffSet;
}

#endif