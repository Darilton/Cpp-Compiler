#include <iostream>
#include <string>
#include <fstream>
#include "lexical analyzer/lex.h"
#include <list>
#include "lexical analyzer/token/token.h"

using namespace std;

bool file_exists (string name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }

    return false;
}

string readFile(string fileName){
    string content;
    ifstream file(fileName);
    
    if (file.is_open()) {
        char ch;
        while (file.get(ch)) {
            content += ch;
        }
        file.close();
        return content;
    }
    return "";
}

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

    cout << "Errors: " << endl;
    for(auto& a: scanner.errors){
        cout << a << endl;
    }
    return 0;
}