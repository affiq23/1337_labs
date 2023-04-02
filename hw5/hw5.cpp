#include <iostream>
#include <cstdlib>
using namespace std;

struct animalNode {
    string question; // a question to ask the user
    string guess; // the name of the animal to guess
    animalNode* yesAnswer; // null or pointer to the "yes" animalNode
    animalNode* noAnswer; // null or pointer to the "no" animalNode
};

int main(){

}