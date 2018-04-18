#ifndef __SIGNEXTEND_CPP__
#define __SIGNEXTEND_CPP__

#include "SignExtend.h"
#include <bitset>

SignExtend::SignExtend() {}

SignExtend::SignExtend(std::bitset sign_extend_val)
{
	this-> sign_extend_val = sign_extend_val;
}

SignExtend::~SignExtend(){}

std::string Extend(std::bitset sign_extend_val)
{
	return "";
}