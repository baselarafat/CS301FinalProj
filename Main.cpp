//The main class for the stimulation of a non-piplined mips assembly processr. 
///Basel Arafat, Nicholas Biffis,Vincent Camp & Will Saada
///Computer Orginization CS 301 Spring 2018
#include "Stimulation.h"

int main (){
	Stimulation* stm = new Stimulation ("input.config");
	stm->run();
};