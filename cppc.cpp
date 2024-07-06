#include <iostream>
#include <string>
#include "lexical analyzer/lex.h"
#include <list>
#include "file/file.h"
#include "lexical analyzer/token/token.h"

using namespace std;

int main(int argc, char *argv[]){
    //Return if no filename specified. 
    //cppc can only compile a file at a time.
    if(argc != 2){
        printf("Usage: cppc [filename]\n");
        return 1;
    }

    string fileString = readFile(argv[1]);
    
    lex scanner(fileString);
    
    list<token> tokens = scanner.scanTokens();

    for(auto& a: tokens){
        cout << a.toString() << endl;
    }

    if(scanner.errors.size() > 0) cout << "Errors: " << endl;
    for(auto& a: scanner.errors){
        cout << a << endl;
    }
    return 0;
}