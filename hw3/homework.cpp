/*
 - 2/22/23:     Started program
                Wrote generateVector() function, which takes input from user and creates vector
                Have to implement boundary check if largestNum is greater than 20

*/


#include <iostream>
#include <vector>
using namespace std;


void show(string msg){
    cout << "SHOWING: " << msg << endl; 
}

 vector <int> generateVector(){
    int sizeVec;
    int largestNum;
    vector <int> vecOne;

    show("Called generateVector");
    cout << "What size vector do you want?" << endl;
    cin >> sizeVec;
    cout << "What is the largest value number you want generated?" << endl;
    cin >> largestNum;
    
    while(largestNum > 20){
        if(largestNum> 20){
            cout << "Sorry. Pick another number less than 20. ";
            cin >> largestNum;
        }
    }


    for(int i = 0; i < sizeVec; i++){
        int j = (rand() % largestNum) + 1;
        vecOne.push_back(j);
    }
    show("Populated generateVector");

    return vecOne;

}

int main(){

vector <int> vectorOne = generateVector();

for(int i = 0; i < vectorOne.size(); i++){
    cout << vectorOne[i] << "| ";
}

cout << endl;

return 0;

}