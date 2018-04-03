#ifndef __HEX_H__
#define __HEX_H__

#include<string>
class hex{
 private: char* array;


public: 
hex();
hex(std::string s);
~hex();
void print();



};

#endif