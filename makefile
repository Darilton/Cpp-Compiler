cppc: cppc.o lex.o token.o
	g++ -o cppc cppc.o lex.o token.o

cppc.o: cppc.cpp
	g++ -c -g cppc.cpp

lex.o: lexical\ analyzer/lex.cpp lexical\ analyzer/lex.h lexical\ analyzer/token/token.h
	g++ -c -g "lexical analyzer/lex.cpp" 

token.o: lexical\ analyzer/token/token.cpp lexical\ analyzer/token/token.h
	g++ -c -g lexical\ analyzer/token/token.cpp

clean:
	rm *.o cppc