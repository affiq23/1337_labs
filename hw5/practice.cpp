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
        
    4/1/23 - 
              



*/
#include <iostream>
#include <string>
using namespace std;

void debug(string msg, bool val)
{
    if (val)
    {
        cout << endl;
        cout << "SHOWING: " << msg;
        cout << endl;
    }
}

struct animalNode
{
    string question;
    string guess;
    animalNode *yesAnswer;
    animalNode *noAnswer;
};

void playGame(animalNode *currentNode)
{
    bool check = true;
    debug("called playGame", check);
    // If currentNode contains a guess, ask the user if it's correct
    if (currentNode->question == "")
    {
        debug("question is empty", check);

        cout << "Is it a " << currentNode->guess << "? (yes/no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "yes")
        {
            cout << "Yay, I got it right!" << endl;
            return;
        }
        else if (answer == "no")
        {
            debug("answer was no", check);
            cout << "Uh oh, looks like I need to learn something new." << endl;
            animalNode *newAnimal = new animalNode; // creates new animalNode
            debug("new node created", check);
            cout << "What animal were you thinking of?" << endl;

            cin >> newAnimal->guess; // takes in new animal
            debug("newAnimal node pointing to new guess", check);
            newAnimal->yesAnswer = nullptr;
            newAnimal->noAnswer = nullptr;
            newAnimal->question = "";
            debug("yes/noAnswers set to null, question is empty", check);

            cout << "Please enter a yes/no question that can distinguish a " << currentNode->guess << " from a " << newAnimal->guess << ":" << endl;
            cin.ignore(); // ignore any extra characters in the input buffer
            getline(cin, currentNode->question);
            currentNode->guess = "";
            debug("currentNode pointing to new guess", check);
            cout << "If someone answered your question for a " << newAnimal->guess << " would the answer be yes or no?" << endl;
            string newAnswer;
            cin >> newAnswer;
            if (newAnswer == "yes")
            {
                debug("newAnswer was yes", check);
                if (currentNode->yesAnswer != nullptr && currentNode->yesAnswer->question == currentNode->question)
                {
                    debug("currentNode is not pointing to null, and currentNode's yesAnswer is pointing to question, which is the same as currentNode question", check);
                    currentNode->yesAnswer->guess = newAnimal->guess;
                    debug("currentNode's yesAnswer is pointing to guess, which is same as newAnimal's guess", true);
                    delete newAnimal;
                    debug("newAnimal is deleted", check);
                    newAnimal = currentNode->yesAnswer;
                    debug("newAnimal is set to currentNode pointing to yesAnswer", check);
                }
                else
                {
                    currentNode->yesAnswer = newAnimal;
                    currentNode->noAnswer = new animalNode;
                    currentNode->noAnswer->guess = currentNode->question;
                    currentNode->noAnswer->yesAnswer = nullptr;
                    currentNode->noAnswer->noAnswer = nullptr;
                    currentNode->noAnswer->question = "";
                }
            }
            else if (newAnswer == "no")
            {
                debug("newAnswer was no", check);
                if (currentNode->noAnswer != nullptr && currentNode->noAnswer->question == currentNode->question)
                {
                    debug("currentNode is not pointing to null, and currentNode's noAnswer is pointing to question, which is the same as currentNode question", check);
                    currentNode->noAnswer->guess = newAnimal->guess;
                    debug("currentNode's noAnswer is pointing to guess, which is same as newAnimal's guess", check);
                    delete newAnimal;
                    debug("newAnimal is deleted", check);
                    newAnimal = currentNode->noAnswer;
                    debug("newAnimal is set to currentNode pointing to noAnswer", check);
                }
                else
                {
                    currentNode->noAnswer = newAnimal;
                    currentNode->yesAnswer = new animalNode;
                    currentNode->yesAnswer->guess = currentNode->question;
                    currentNode->yesAnswer->yesAnswer = nullptr;
                    currentNode->yesAnswer->noAnswer = nullptr;
                    currentNode->yesAnswer->question = "";
                }
            }
            cout << "Thanks for teaching me about a " << newAnimal->guess << "!" << endl;
        }
    }
    // If currentNode contains a question, ask it and follow the appropriate path
    else
    {
        debug("else statement called, currentNode has a question", check);

        cout << currentNode->question << " (yes/no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "yes")
        {
            debug("answer was yes, currentNode pointing to yes", check);
            playGame(currentNode->yesAnswer);
        }
        else if (answer == "no")
        {
            debug("answer was no, currentNode pointing to no", check);
            playGame(currentNode->noAnswer);
        }
    }
}

int main()
{
    animalNode *rootNode = new animalNode;
    rootNode->question = "";
    rootNode->guess = "lizard";
    rootNode->yesAnswer = nullptr;
    rootNode->noAnswer = nullptr;
    cout << "Think of an animal." << endl;

    while (true)
    {
        playGame(rootNode);
        cout << "Do you want to play again? (yes/no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "no")
        {
            break;
        }
    }
    return 0;
}