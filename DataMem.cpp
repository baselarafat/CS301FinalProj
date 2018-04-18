#ifndef __DATAMEM_CPP__
#define __SIGNEXTEND_CPP__

#import "DataMem.h"
#import <iostream>

    DataMem::DataMem(){}

    DataMem::DataMem(bitset<>[] dataMemArr)
    {
        dataMemArr.resize(MemSize);
        ifstream memfile;
        string line;
        int i=0;
        memfile.open("mem.txt");
        if (memfile.is_open())
        {
            while (getline(memfile,line))
            {
                dataMemArr[i] = bitset<8>(line);
                i++;
            }
        }

        memfile.close();
    }

    DataMem::~DataMem(){}

    std::string readMem(bitset<32> address)
    {
        unsigned long count = Address.to_ulong();
        int index = (int) count;
            std::string data;
            for (int i = 0; i < 4; i++) {

                data += dataMemArr[index].to_string();
                index++;
            }
            bitset<32> Data(data);
            readdata = Data;
            data = Data.to_string();
            return data;
        }

      writeMem(bitset<32> address, bitset<32> data_to_write) 
      { 
                                                                           
            for(int i= 0;i<32;i=i+8){
                string result = data_to_write.to_string().substr(i,8);
                bitset<8> finalResult(result);
                dataMemArr[index] =  finalResult;
                index++;
            }
        }
        
    
};