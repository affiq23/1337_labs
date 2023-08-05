#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ofstream newFile;
    newFile.open("filePractice.txt");

    if(newFile.is_open()){
        newFile << "this is a new file" << endl;
        newFile.close();
    }
    return 0;


}