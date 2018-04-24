#ifndef __CONVERTER_H__
#define __CONVERTER_H__

#include <sstream>
#include <string>
#include <iostream>
#include "Parser.h"

using namespace std;
class Converter{
	public: 
	Converter(){
	}
	~Converter(){

	}
	static int hextoint(std::string s ){
  	stringstream ss (s);
  	int x;
   	ss>>hex>>x;
   	return x;
}
static string inttohex(int x){
  stringstream ss ;
  ss<<hex<<x;
  std::string s = ss.str();
  return s;
}
	static string hexToBinary(string hex)
{
    string bin;

    for (int i = 0; i < hex.length(); i++)
    {

        // Get the next char in the hex
        char currChar = hex.at(i);

        // Convert the next char in the hex to the appropriate 4-bit binary representation
        switch (currChar)
        {
        case '0':
            bin.append("0000");
            break;
        case '1':
            bin.append("0001");
            break;
        case '2':
            bin.append("0010");
            break;
        case '3':
            bin.append("0011");
            break;
        case '4':
            bin.append("0100");
            break;
        case '5':
            bin.append("0101");
            break;
        case '6':
            bin.append("0110");
            break;
        case '7':
            bin.append("0111");
            break;
        case '8':
            bin.append("1000");
            break;
        case '9':
            bin.append("1001");
            break;
        case 'A':
            bin.append("1010");
            break;
        case 'a':
            bin.append("1010");
            break;
        case 'B':
            bin.append("1011");
            break;
        case 'b':
            bin.append("1011");
            break;
        case 'C':
            bin.append("1100");
            break;
        case 'c':
            bin.append("1100");
            break;
        case 'D':
            bin.append("1101");
            break;
        case 'd':
            bin.append("1101");
            break;
        case 'E':
            bin.append("1110");
            break;
        case 'e':
            bin.append("1110");
            break;
        case 'F':
            bin.append("1111");
            break;
        case 'f':
            bin.append("1111");
            break;
        }
    }
    return bin;
}
static string binaryToHex(string binary)
{
    string hex;               // string that will hold final hex string to return
    string extender = "0000"; // string to extend input string so length is divisible by 4
    string temp;              // string that will hold 4 bit chunks of input string

    // Extend inputted string to be of a length divisible by 4
    if (binary.length() % 4 != 0) {
        int extenderLength = 4 - binary.length() % 4;
        extender = extender.substr(0, extenderLength);
        binary = extender + binary; // append extender to front of binary string
    }

    // Loop through 4 bit chunks of binary string, appending to hex string
    for (int i = 0; i < binary.length(); i += 4)
    {
        temp = binary.substr(i, 4);
        if (!temp.compare("0000"))
        {
            hex += "0";
        }
        else if (!temp.compare("0001"))
        {
            hex += "1";
        }
        else if (!temp.compare("0010"))
        {
            hex += "2";
        }
        else if (!temp.compare("0011"))
        {
            hex += "3";
        }
        else if (!temp.compare("0100"))
        {
            hex += "4";
        }
        else if (!temp.compare("0101"))
        {
            hex += "5";
        }
        else if (!temp.compare("0110"))
        {
            hex += "6";
        }
        else if (!temp.compare("0111"))
        {
            hex += "7";
        }
        else if (!temp.compare("1000"))
        {
            hex += "8";
        }
        else if (!temp.compare("1001"))
        {
            hex += "9";
        }
        else if (!temp.compare("1010"))
        {
            hex += "a";
        }
        else if (!temp.compare("1011"))
        {
            hex += "b";
        }
        else if (!temp.compare("1100"))
        {
            hex += "c";
        }
        else if (!temp.compare("1101"))
        {
            hex += "d";
        }
        else if (!temp.compare("1110"))
        {
            hex += "e";
        }
        else if (!temp.compare("1111"))
        {
            hex += "f";
        }
    }
    return hex;
}

static std::string hexify(std::string s){
		std::string mystring;
	//Checking if it already has "0x" in the begging of the string 
		if(s.length()<1)
            return s;
        else if((s.at(0)=='0')&& (s.at(1)=='x'))
			return s;
		else {
			mystring="0x";
			mystring.append(s);
		return mystring; 
		}
    }
	static std::string inttobinarry(int a){
		std::string hex =inttohex(a);
		std::string bin = hexToBinary(hex);
		return bin;
 	}
		

};
#endif