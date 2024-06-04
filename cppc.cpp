#include <iostream>
#include "lexical analyzer/lex.h"

using namespace std;

bool file_exists (string name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

int main(int argc, char *argv[]){
    //Return in no filename specified. 
    //cppc can only compile a file at a time.
    if(argc != 2){
        printf("Usage: cppc [filename]\n");
        return 1;
    }

    if(file_exists(argv[1]))
        cout << "File Exists" << endl;
    else
        cout << "Error: No such file: " << argv[1];

    // scanToken();
    return 0;
}