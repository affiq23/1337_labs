/*
    NAME: Affiq Mohammed
    DATE CREATED: 3/30/23
    NAME OF PROGRAM: HW5-CS1337-Affiq-Mohammed
    CHANGELOG:

    3/30/23 - started program
              wrote struct and added lizard as first animal guess

    3/31/23 - started playGame function
              was able to implement new node creation when user thinks of new animal that program does not recognize
              added yes/no question for program to ask user to guess new animal
              started playGame function
        
    4/1/23 - implemented yesAnswer and noAnswer cases
             added debugging function to print out every operation as it happens
             created logic for program to point towards new question and guess using curNode
             wrote else statement when question is not empty
             bug in code where it asks question instead of guess once it gets down to last node; need to fix

    4/2/23 - fixed bug where it was calling question: curNode was pointing to guess and setting it equal to question

    SPECIAL FEATURES: set bool check to true if you want to turn on debugging statements
*/

#include <iostream>
#include <string>
using namespace std;

bool check = false; 

// debug statement to fix my bugs
void debug(string msg, bool check)
{
    if (check)
    {
        cout << endl;
        cout << "SHOWING: " << msg;
        cout << endl;
    }
}

// original struct for node
struct animalNode
{
    string question;
    string guess;
    animalNode *yesAnswer;
    animalNode *noAnswer;
};

void playGame(animalNode *curNode) // passes in root node as current node first time playing
{

    debug("called playGame", check);
    // if curNode contains a guess, ask the user if it's correct
    if (curNode->question == "")
    {
        debug("question is empty", check);
        cout << "Is it a(n) " << curNode->guess << "? (yes/no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "yes") // program guesses correctly and game is over
        {
            cout << "I win!" << endl;
            return;
        }
        else if (answer == "no")
        {
            debug("answer was no", check);
            cout << "Bummer!" << endl;
            animalNode *newAnimal = new animalNode; // creates new animalNode
            debug("new node created", check);
            cout << "What animal were you thinking of?" << endl;

            cin >> newAnimal->guess; // takes in new animal
            debug("newAnimal node pointing to new guess", check);
            newAnimal->yesAnswer = nullptr; // sets new animal node's yesAnswer and noAnswer to null
            newAnimal->noAnswer = nullptr;
            newAnimal->question = "";
            debug("yes/noAnswers set to null, question is empty", check);

            cout << "What's a yes/no question to identify a(n) " << curNode->guess << " from a(n) " << newAnimal->guess << ":" << endl;
            cin.ignore(); // ignore whitespace/extra characters
            getline(cin, curNode->question);
            debug("curNode pointing to new guess", check);
            cout << "For a(n) " << newAnimal->guess << ", would the answer be yes or no?" << endl;
            string newAnswer;
            cin >> newAnswer;

            if (newAnswer == "yes") // if answer is yes
            {
                debug("newAnswer was yes", check);
                if (curNode->yesAnswer != nullptr && curNode->yesAnswer->question == curNode->question) 
                // if user's answer is not null and the question yesAnswer points to is equal to question pointed to by current node; yesAnswer already exists
                {
                    debug("curNode is not pointing to null, and curNode's yesAnswer is pointing to question, which is the same as curNode question", check);
                    curNode->yesAnswer->guess = newAnimal->guess; // updates yesAnswer guess to be newAnimal guess
                    debug("curNode's yesAnswer is pointing to guess, which is same as newAnimal's guess", true);
                    delete newAnimal; 
                    debug("newAnimal is deleted", check);
                    newAnimal = curNode->yesAnswer;
                    debug("newAnimal is set to curNode pointing to yesAnswer", check);
                }
                else // yesAnswer does not exist
                {
                    curNode->yesAnswer = newAnimal;
                    curNode->noAnswer = new animalNode; // creates new node for noAnswer
                    curNode->noAnswer->guess = curNode->guess; //sets noAnswer guess equal to current guess
                    curNode->noAnswer->yesAnswer = nullptr;
                    curNode->noAnswer->noAnswer = nullptr;
                    curNode->noAnswer->question = "";
                }
            }
            else if (newAnswer == "no")
            {
                debug("newAnswer was no", check);
                if (curNode->noAnswer != nullptr && curNode->noAnswer->question == curNode->question)
                // if current node's noAnswer is not null and noAnswer's question is equal to the question pointed to by current node
                {
                    debug("curNode is not pointing to null, and curNode's noAnswer is pointing to question, which is the same as curNode question", check);
                    curNode->noAnswer->guess = newAnimal->guess; // updates noAnswer guess to be newAnimal guess
                    debug("curNode's noAnswer is pointing to guess, which is same as newAnimal's guess", check);
                    delete newAnimal;
                    debug("newAnimal is deleted", check);
                    newAnimal = curNode->noAnswer;
                    debug("newAnimal is set to curNode pointing to noAnswer", check);
                }
                else
                {
                    curNode->noAnswer = newAnimal;
                    curNode->yesAnswer = new animalNode; // creates new node for yesAnswer
                    curNode->yesAnswer->guess = curNode->guess; //sets yesAnswer guess equal to current guess
                    curNode->yesAnswer->yesAnswer = nullptr;
                    curNode->yesAnswer->noAnswer = nullptr;
                    curNode->yesAnswer->question = "";
                }
            }
            cout << "Thanks for teaching me about a(n) " << newAnimal->guess << "!" << endl;
        }
    }
    // if curNode has a question, check answer to question
    else
    {
        debug("else statement called, curNode has a question", check);

        cout << curNode->question << " (yes/no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "yes")
        {
            debug("answer was yes, curNode pointing to yes", check);
            playGame(curNode->yesAnswer);
        }
        else if (answer == "no") // new comment
        {
            debug("answer was no, curNode pointing to no", check);
            playGame(curNode->noAnswer);
        }
    }
}

int main()
{
    string answer; // to indicate whether user wants to keep playing

    // creates root node to start binary tree
    animalNode *rootNode = new animalNode;
    rootNode->question = "";
    rootNode->guess = "lizard";
    rootNode->yesAnswer = nullptr;
    rootNode->noAnswer = nullptr;
    cout << "Let's play an Animal Guessing Game!" << endl;
    cout << "Think of an animal and click return when ready." << endl;
    cin.ignore(); // ignores key click

    // while loop to keep playing game
    while (true)
    {
        playGame(rootNode);
        cout << "Do you want to play again? (yes/no)" << endl;
        cin >> answer;
        if (answer == "no")
        {
            break;
        }
    }
    return 0;
}