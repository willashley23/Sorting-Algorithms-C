lab06: Test.o main.o
	g++ -g -Wall -std=c++11 main.o Test.o -o lab06
Test.o: Test.h Test.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 -c Test.cpp
main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 -c main.cpp
Sorts.o:
	g++ -g -Wall -std=c++11 -c Sorts.hpp
	
clean:
	rm *.o lab06
