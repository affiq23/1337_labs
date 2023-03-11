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

    3/11/23 -   fixed number of words to work for every single line
                implemented foundLongestWord function to find longest word
                implemented function to find number of vowels, consonants, spaces, punctuation, and other characters



    SPECIAL FEATURES:
        - program asks user for file name to read; though it would add more functionality
        - for debugging statements, each function has a bool value as a parameter; if bool is set to false, all debugging statements in function are turned off
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

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
    string line;
    string sentence;
    while (getline(inputFile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            char c = line[i];
            if (c == '.' || c == '?')
            {
                sentence += c;
                sentences.push_back(sentence);
                sentence.clear();
            }
            else
            {
                sentence += c;
            }
        }
    }

    if (!sentence.empty())
    {
        sentences.push_back(sentence);
    }

    if (debug)
    {
        debugStatement("added all sentences to vector");
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
int countWords(string sentence, bool debug)
{
    int wordCount = 0;
    bool inWord = false;

    // iterate over each character in the sentence
    for (int i = 0; i < sentence.length(); i++)
    {
        char c = sentence[i];

        // if the character is not whitespace
        if (!isspace(c))
        {
            if (!inWord)
            {
                inWord = true;
                wordCount++;
            }
        }
        else // if the character is whitespace
        {
            inWord = false; // mark that we're not currently in a word
        }
    }
    if (debug)
    {
        debugStatement("found number of words in a sentence");
    }
    return wordCount;
}

// finds the longest word in a sentence
string findLongestWord(string sentence, bool debug)
{
    string longestWord;
    string word;
    int longestLength = 0;

    for (int i = 0; i < sentence.length(); i++)
    {
        char c = sentence[i];
        if (!isspace(c))
        {
            word += c;
        }
        else
        {
            int length = word.length();
            if (length > longestLength)
            {
                longestLength = length;
                longestWord = word;
            }
            word.clear();
        }
    }
    // check the last word in the sentence
    int length = word.length();
    if (length > longestLength)
    {
        longestLength = length;
        longestWord = word;
    }

    if (debug)
    {
        debugStatement("found longest word in a sentence");
    }
    return longestWord;
}

void countAllCharacters(string sentence, int &numVowels, int &numConsonants, int &numSpaces, int &numPunc, int &numOther)
{
    numVowels = 0;
    numConsonants = 0;
    numSpaces = 0;
    numPunc = 0;
    numOther = 0;

    for (int i = 0; i < sentence.length(); i++)
    {

        char ch = tolower(sentence[i]);
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                numVowels++;
            }

            else
            {
                numConsonants++;
            }
        }
        else if (ch == ' ')
        {
            numSpaces++;
        }
        else if (ispunct(ch))
        {
            numPunc++;
        }
        else
        {
            numOther++;
        }
    }
}


int main()
{
    int numVowels = 0;
    int numConsonants = 0;
    int numSpaces = 0;
    int numPunc = 0;
    int numOther = 0;


    string nameOfFile;
    cout << "Enter name of file you wish to read in: ";
    cin >> nameOfFile;
    cout << endl;

    vector<string> sentences = readFileData(nameOfFile, false); // calling function to read in sentences from file

    // loops through "sentences" vector to use
    for (int i = 0; i < sentences.size(); i++)
    {
        cout << "SENTENCE" << endl;
        cout << sentences.at(i) << endl;
        cout << "Number of characters in sentence: " << countNumChars(sentences.at(i), false) << endl;
        cout << "Number of words in sentence: " << countWords(sentences.at(i), false) << endl;
        cout << "Longest word in the sentence: " << findLongestWord(sentences.at(i), false) << endl;

        cout << "NUMBER OF CHARACTERS" << endl;
        countAllCharacters(sentences.at(i), numVowels, numConsonants, numSpaces, numPunc, numOther);
        cout << "Vowels: " << numVowels << endl;
        cout << "Consonants: " << numConsonants << endl;
        cout << "Spaces: " << numSpaces << endl;
        cout << "Punctuation: " << numPunc << endl;
        cout << "Other: " << numOther << endl;
        cout << endl;

        
    }
    return 0;
}
