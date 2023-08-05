//
//  main.cpp
//  outputValues
//
//  Created by Affiq Mohammed on 11/3/22.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> myIntVec;
    vector<int> newVec;
    int num;
    int input = 0;
    
    cin >> num;
    
    
    for(int i = 0; i < num + 1; i++){
        cin >> input;
        myIntVec.push_back(input);
    }

    
    for(int i = 0; i < num; i++){
        if(myIntVec.at(i) < myIntVec.back()){
            newVec.push_back(myIntVec.at(i));
        }
    }
    
    
    for(int i = 0; i < newVec.size(); i++){
        cout << newVec.at(i) << ",";
    }
    cout << endl;
    
    return 0;
}
