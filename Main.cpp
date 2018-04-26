//The main class for the stimulation of a non-piplined mips assembly processr. 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
#include "Stimulation.h"


int main(int argc, char *argv[])
{
	Stimulation* stm ;
	
  if(argc < 2){
    cerr << "Need to specify a configuration file to stimulate the processr."<<endl;
    exit(1);
  }
	stm =new Stimulation (argv[1]);
	stm->run();

	delete stm;
};