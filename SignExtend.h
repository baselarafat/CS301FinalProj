#ifndef __SIGNEXTEND_H__
#define __SIGNEXTEND_H__

#include <bitset>
#include <string>
#include <iostream>


class SignExtend
{
	public:
		SignExtend(){}
		~SignExtend(){}

	static std::string Extend(std::bitset<16> sign_extend_val)
	{
		std::string s;

		if(sign_extend_val[15]==0){
			std::bitset<16> extended ;
			s=extended.to_string();
			s+=sign_extend_val.to_string();
		}
		else 
		{
			std::bitset<16> extended2 ;
			extended2.set();
			s=extended2.to_string();
			s+=sign_extend_val.to_string();
		}
		
		return s;
	}
	
	
};
#endif