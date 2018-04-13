#ifndef __SHIFTLEFTTWO_CPP__
#define __SHIFTLEFTTWO_CPP__

#include "ShiftLeftTwo.h"
#include <bitset>

ShiftLeftTwo::ShiftLeftTwo() {}

ShiftLeftTwo::ShiftLeftTwo(std::string offset)
{
	std::bitset<32> offsetField(offset);
}

// shifts the offset field to the left by two bits, making it a word offset
ShiftLeftTwo::~ShiftLeftTwo(){}

 Shift(std::string offsetField)
{
	std::bitset<32> shiftedOffSet(offsetField);
	return shiftedOffSet  <<= 2;
};

#endif