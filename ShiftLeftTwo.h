#ifndef __SHIFTLEFTTWO_H__
#define __SHIFTLEFTTWO_H__

#include <bitset>
#include <string>

using namespace std;

//Used to shift the offset field to the left by two, making it a word offset

class ShiftLeftTwo
{
public:
	ShiftLeftTwo();
	ShiftLeftTwo(std::string offset);
	~ShiftLeftTwo();

	// shifts the offset field to the left by two bits, making it a word offset
	Shift(std::string offsetField);
};

#endif