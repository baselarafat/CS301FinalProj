///ConfigurationFile Parsr Class 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
class ConfigurationParser
{
public:
	ConfigurationParser();
	ConfigurationParser(std::string s){
		Configurationfile=s;
	}
	~ConfigurationParser(){}
	void Parseit ();

	//Getters
	inline std::string getConfigurationfile(){return Configurationfile;}
	inline std::string getprogramInputFile(){return programInputFile;}
	inline std::string getdataMemoryFile(){return dataMemoryFile;}
	inline std::string getregisterFile(){return registerFile;}
	inline std::string getoutputMode(){return outputMode;}
	inline std::string getoutputFile(){return outputFile;}
	inline bool getdebugMode(){return debugMode;}
	inline bool getprintMemoryContents(){return printMemoryContents;}
	inline bool getwriteToFile(){return writeToFile;}


private:
	std::string Configurationfile;
	std::string programInputFile;
  	std::string dataMemoryFile;
  	std::string registerFile;
  	std::string outputMode;
  	std::string outputFile;

  	bool debugMode;
  	bool printMemoryContents;
  	bool writeToFile;

	
};
