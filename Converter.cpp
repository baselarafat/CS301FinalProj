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
	static std::string cvthex2Bin(std::string s){
  int len = s.length();
  int a = hextoint(s);
  string bin = Parser::cvtInt2Bin(a,len);
  return bin;

}

};