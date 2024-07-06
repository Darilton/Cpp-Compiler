cppc: cppc.o lex.o token.o file.o
	g++ -o cppc cppc.o lex.o token.o file.o

cppc.o: cppc.cpp
	g++ -c -g cppc.cpp

lex.o: lexical\ analyzer/lex.cpp lexical\ analyzer/lex.h lexical\ analyzer/token/token.h file/file.h
	g++ -c -g "lexical analyzer/lex.cpp" 

token.o: lexical\ analyzer/token/token.cpp lexical\ analyzer/token/token.h
	g++ -c -g lexical\ analyzer/token/token.cpp

file.o: file/file.cpp file/file.h
	g++ -c -g file/file.cpp

clean:
	rm *.o cppc