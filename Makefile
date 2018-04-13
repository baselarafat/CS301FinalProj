CXX:= g++
CXXFLAGS:= -std=c++11 -Wall
INPUT:= *.cpp
OBJECT:= finalproj
make:
	$(CXX) $(CXXFLAGS) $(INPUT) -o $(OBJECT)

clean:
	rm $(OBJECT)
