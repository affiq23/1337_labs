/*
    NAME: Affiq Mohammed
    DATE CREATED: 3/9/23
    NAME OF PROGRAM: hw4 (as of now; CHANGE)
    CHANGELOG:

    3/9/23 -    started program
                was able to read in the file and print out sentences, but still need to encapsulate reading in file into its own function

    3/10/23 -   started debugging functions
                made loop to run through every sentence; all string manipulations will just occur in that loop and every sentence will run through the loop
                printed number of characters in sentence
                problem with whitespace when two sentences are on the same line; have to resolve that
                found the number of words in each sentence, but sentences with whitespace are returning one more word; need to fix that


    SPECIAL FEATURES:
        - program asks user for file name to read; though it would add more functionality
        - for debugging statements, each function has a bool value as a parameter; if bool is set to false, all debugging statements in function are turned off

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// debugging statement to check that code is working properly
void debugStatement(string msg)
{
    cout << "SHOWING: " << msg << endl;
}

// reads in text from file and adds each sentence to a "sentence" vector
vector<string> readFileData(string filename, bool debug)
{
    if (debug)
    {
        debugStatement("called readFileData function");
    }

    ifstream inputFile(filename);
    vector<string> sentences;
    string sentence;
    if (inputFile)
    {
        string line;
        string sentence;
        while (getline(inputFile, line))
        {
            for (char c : line)
            {
                sentence += c;
                if (c == '.' || c == '?')
                {
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
        }

        if (debug)
        {
            debugStatement("added all sentences to vector");
        }

        if (!sentence.empty())
        {
            sentences.push_back(sentence);
        }
    }

    else
    {
        cout << "Error: could not open file " << filename << endl; // checking if file exists
    }

    inputFile.close();

    if (debug)
    {
        debugStatement("finished readFileData function");
    }

    return sentences;
}

// counts the number of characters in a sentence
int countNumChars(string sentence, bool debug)
{
    int numChars = sentence.length();
    if (debug)
    {
        debugStatement("counted number of characters in sentence");
    }
    return numChars;
}

// counts the number of words in a sentence
int countNumWords(string sentence, bool debug)
{
    int numWords = 1;
    for (char c : sentence)
    {
        if (c == ' ')
        {
            numWords++;
        }
    }

    if (debug)
    {
        debugStatement("counted number of words in sentence");
    }

    return numWords;
}


int main()
{

    string nameOfFile;
    cout << "Enter name of file you wish to read in: ";
    cin >> nameOfFile;
    cout << endl;

    vector<string> sentences = readFileData(nameOfFile, false); // calling function to read in sentences from file

    // loops through "sentences" vector to use
    for (int i = 0; i < sentences.size(); i++)
    {
        cout << sentences.at(i) << endl;
        cout << "Number of characters in sentence: " << countNumChars(sentences.at(i), false) << endl;
        cout << "Number of words in sentence: " << countNumWords(sentences.at(i), false) << endl;
        cout << endl;
    }
    return 0;
}
