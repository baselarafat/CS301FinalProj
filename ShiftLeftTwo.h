///Stimulation Class 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
#ifndef __SHIFTLEFTTWO_H__
#define __SHIFTLEFTTWO_H__

#include <bitset>
#include <string>



///Used to shift the offset field to the left by two, making it a word offset

class ShiftLeftTwo
{
public:
	ShiftLeftTwo(){}
	~ShiftLeftTwo(){}

	/// shifts the offset field to the left by two bits, making it a word offset
	static std::string Shift(std::string offsetField)
	{
		std::bitset<32> shiftedOffSet(offsetField);
		shiftedOffSet  <<= 2;
		std::string s =shiftedOffSet.to_string();
		return s;
	}
};

#endif

