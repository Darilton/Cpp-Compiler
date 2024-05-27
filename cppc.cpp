#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    //Return in no filename specified. 
    //cppc can only compile a file at a time.
    if(argc != 2){
        printf("Usage: cppc [filename]\n");
        return 1;
    }

    cout << "File: " << argv[1] <<endl;
    return 0;
}