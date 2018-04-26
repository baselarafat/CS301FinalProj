#include "ConfigurationParser.h"
void ConfigurationParser::Parseit() {
	std::ifstream infile1;
  ///opens file then make sure it was successful
  infile1.open(Configurationfile);
    if (!infile1.is_open()) {
        std::cerr << "An error has occured when opening the file";
        exit(1); 
    }
    ///loop to run once for each config
    for(int i = 0; i < 8; i++)
    {
      std::string configInput;
      infile1 >> configInput;

      std::string configResult;
      int pointerToEquals = 0;

      ///loops through string until it finds equals
      ///sets pointer to j
      for(int unsigned(j) = 0; j < configInput.length(); j++)
      {
          if(configInput.at(j) == '=')
          {
              pointerToEquals = j+1;
              break;
          }
      }

      ///gets the part of the input after the equals sign
      configResult = configInput.substr(pointerToEquals);

      ///this block of code adds the values from the config file to 
      ///the appropriate variables.
      switch(i) 
      {
          case 0 :
            programInputFile = configResult;
            break;

          case 1 :
            dataMemoryFile = configResult;
            break;

          case 2 :
            registerFile = configResult;
            break;

          case 3 :
            outputMode = configResult;
            break;

          case 4 :
            if(configResult.at(0) == 'f')
            {
              debugMode = false;
            } 
            else 
            {
              debugMode = true;
            }
            break;

          case 5 :
            if(configResult.at(0) == 'f')
            {
              printMemoryContents = false;
            } 
            else 
            {
              printMemoryContents = true;
            }
            break;
          
          case 6 :
            outputFile = configResult;
            break;

          case 7 :
            if(configResult.at(0) == 'f')
            {
              writeToFile = false;
            } 
            else 
            {
              writeToFile = true;
            }
            break;
      }     
    
    }

    infile1.close();


}