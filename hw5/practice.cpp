// adds animals to nodes; bug in question acting as a guess
#include <iostream>
#include <string>
using namespace std;

struct animalNode {
    string question;
    string guess;
    animalNode* yesAnswer;
    animalNode* noAnswer;
};

void playGame(animalNode* currentNode) {
    // If currentNode contains a guess, ask the user if it's correct
    if (currentNode->question == "") {
        cout << "Is it a " << currentNode->guess << "? (yes/no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "yes") {
            cout << "Yay, I got it right!" << endl;
            return;
        }
        else if (answer == "no") {
            cout << "Uh oh, looks like I need to learn something new." << endl;
            animalNode* newAnimal = new animalNode;
            cout << "What animal were you thinking of?" << endl;
            cin >> newAnimal->guess;
            newAnimal->yesAnswer = nullptr;
            newAnimal->noAnswer = nullptr;
            newAnimal->question = "";
            cout << "Please enter a yes/no question that can distinguish a "
                 << currentNode->guess << " from a " << newAnimal->guess << ":" << endl;
            cin.ignore(); // ignore any extra characters in the input buffer
            getline(cin, currentNode->question);
            currentNode->guess = "";
            cout << "If someone answered your question for a " << newAnimal->guess
                 << " would the answer be yes or no?" << endl;
            string newAnswer;
            cin >> newAnswer;
            if (newAnswer == "yes") {
                if (currentNode->yesAnswer != nullptr && currentNode->yesAnswer->question == currentNode->question) {
                    currentNode->yesAnswer->guess = newAnimal->guess;
                    delete newAnimal;
                    newAnimal = currentNode->yesAnswer;
                } else {
                    currentNode->yesAnswer = newAnimal;
                    currentNode->noAnswer = new animalNode;
                    currentNode->noAnswer->guess = currentNode->question;
                    currentNode->noAnswer->yesAnswer = nullptr;
                    currentNode->noAnswer->noAnswer = nullptr;
                    currentNode->noAnswer->question = "";
                }
            }
            else if (newAnswer == "no") {
                if (currentNode->noAnswer != nullptr && currentNode->noAnswer->question == currentNode->question) {
                    currentNode->noAnswer->guess = newAnimal->guess;
                    delete newAnimal;
                    newAnimal = currentNode->noAnswer;
                } else {
                    currentNode->noAnswer = newAnimal;
                    currentNode->yesAnswer = new animalNode;
                    currentNode->yesAnswer->guess = currentNode->question;
                    currentNode->yesAnswer->yesAnswer = nullptr;
                    currentNode->yesAnswer->noAnswer = nullptr;
                    currentNode->yesAnswer->question = "";
                }
            }
            cout << "Thanks for teaching me about " << newAnimal->guess << "!" << endl;
        }
    }
    // If currentNode contains a question, ask it and follow the appropriate path
    else {
        cout << currentNode->question << " (yes/no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "yes") {
            playGame(currentNode->yesAnswer);
        }
        else if (answer == "no") {
            playGame(currentNode->noAnswer);
        }
    }
}

int main() {
    animalNode* rootNode = new animalNode;
    rootNode->question = "";
    rootNode->guess = "lizard";
    rootNode->yesAnswer = nullptr;
    rootNode->noAnswer = nullptr;
    cout << "Think of an animal and press enter when ready." << endl;
    cin.ignore(); // ignore the enter key press
    while (true) {
        playGame(rootNode);
        cout << "Do you want to play again? (yes/no)" << endl;
        string answer;
        cin >> answer;
        if (answer == "no") {
            break;
        }
    }
    return 0;
}
