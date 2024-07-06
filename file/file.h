#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

bool file_exists (string name);
string readFile(string fileName);
list<string> getFileLines (string fileName);
#endif