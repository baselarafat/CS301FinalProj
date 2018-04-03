
#ifndef __MULTIPLEXOR_H__
#define __MULTIPLEXOR_H__

#include <string> 

class Multiplexor
{
	protected:
    int numMux;
    bool sig;
    std::string firstInput;
    std::string secondInput;
    //0 or 1, based on value in the picture of the processor.
    int flow;

    public:
        Multiplexor(int num);

        ~Multiplexor();

        std::string mux(std::string address);

        std::string setFirstInput(std::string firstInput);

        std::string setSecondInput(std::string secondInput);

        void setSignal(bool signal);

        bool getSignal();

        std::string mux();

        void setFlow(int flow);

        //For testing only
        int getFlow();
        
};

#endif
