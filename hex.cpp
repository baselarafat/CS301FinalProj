 // #include<iostream>

#include "hex.h"
	hex::hex(){}
	hex::hex(std::string s){
		array= new char [10];
	//Checking if it already has "0x" in the begging of the string 
		if((s.at(0)=='0')&& (s.at(1)=='x'))
			for(int i=0;i<s.length();i++)
				array[i]=s.at(i);
		else {
			array[0]='0';
			array[1]='x';
			for(int i=0;i<s.length();i++)
				array[i+2]=s.at(i);
			}
		}
	hex::~hex(){
			delete [] array;
		}
	void hex::print(){
		for(int i=0;i<10;i++){
			std::cout<<this->array[i];
	}
	}
 // For testing puropses only 
// int main (){
// 	std::cout<<"Hi"<<std::endl;
// 	std::string s ("10000030");
// 	std::string str ("0x10000030");
// 	hex a (s);

// 	for(int i=0;i<10;i++){
// 		std::cout<<a.array[i];
// 	}
// 	std::cout<<std::endl;
// 	hex b (str);
// 	for(int i=0;i<10;i++){
// 		std::cout<<b.array[i];
// 	}
// 		std::cout<<std::endl;
// 	return 0;

// }
