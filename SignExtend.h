#ifndef __SIGNEXTEND_H__
#define __SIGNEXTEND_H__

#include <bitset>

using namespace std;

class SignExtend
{
	public:
		SignExtend();
		SignExtend(std::bitset sign_extend_val);
		~SignExtend();

		std:: string Extend(std::bitset sign_extend_val);
}