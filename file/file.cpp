#include "file.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

bool file_exists (string name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }

    return false;
}

std::list<string> getFileLines (string fileName){
    list<string> fileLines;
    ifstream file(fileName);

    if(file.is_open()){
        string line;
        while(getline(file, line)){
            fileLines.push_back(line);
        }
        file.close();
    }
    return fileLines;
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