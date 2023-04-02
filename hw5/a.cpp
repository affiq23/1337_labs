#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

    //animal mode and string questions
struct animalNode
    {
    string question;
    string guests;
    aninalMode* yesAnswer;
    animalMode* noAnswer;
};

    animalNode* node = new animalNode;
    newNode->question = "Does it have four legs?";
    newNode->guess = "dog";
    newNode->yesAnswer = nullptr;
    newNode->noAnswer = nullptr;

    delete newNode;

    animalNode* node = new animalNode;
    node->question = "Does it have wings?";
    node->guess = "";
    node->yesAnswer = new animalNode;  // child node for "yes" answer
    node->noAnswer = new animalNode;   // child node for "no" answer

    animalNode* node = new animalNode;
    node->question = "";
    node->guess = "elephant";
    node->yesAnswer = nullptr;
    node->noAnswer = nullptr;

    animalNode* rootNode = new animalNode;
    rootNode->question = "";
    rootNode->guess = "lizard";
    rootNode->yesAnswer = nullptr;
    rootNode->noAnswer = nullptr;

    //ask the user to be able to find and think of an animal
    cout << "think of animal and press Enter to continue..." << endl;
    cin.ignore(); //ignore previous input from the user

    //Start the game with root node
    animalNode* currentNode = rootNode;


while(secretnum != guess){

    animalMode StartingPoint;
    StartingPoint.question = "Does it fly? ";
    animalMode NumFlying;
    animalMode Flying;
    StartingPoint.yesAnswer
    string text;
    TreeNode yes_ans,no_ans;
};
typedef TreeNode* TreeNodePtr;