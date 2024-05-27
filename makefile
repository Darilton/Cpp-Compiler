cppc: cppc.o
	g++ -o cppc cppc.o

cppc.o: cppc.cpp
	g++ -c cppc.cpp

clean:
	rm *.o cppc