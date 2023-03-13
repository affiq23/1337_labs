/*
    NAME: Affiq Mohammed
    DATE CREATED: 3/9/23
    NAME OF PROGRAM: HW4-CS1337-Affiq-Mohammed
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

    3/12/23 -   implemented title case function, sentence case function, toggle case function
                created ofstream to print results to file



    SPECIAL FEATURES:
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
    string sentence;
    while (getline(inputFile, sentence, '\n'))
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
    bool word = false;

    // loops over each character in the sentence
    for (int i = 0; i < sentence.length(); i++)
    {
        char c = sentence[i];

        // if not whitespace
        if (!isspace(c))
        {
            if (!word)
            {
                word = true;
                wordCount++;
            }
        }
        else // if the character is whitespace
        {
            word = false; // mark that we're not currently in a word
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
            // updates length for each word
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

void countAllCharacters(string sentence, int &numVowels, int &numConsonants, int &numSpaces, int &numPunc, int &numOther, bool debug)
{
    numVowels = 0;
    numConsonants = 0;
    numSpaces = 0;
    numPunc = 0;
    numOther = 0;

    string vowels = "AIEOUaeiou";
    string punctuation = ".,;?!";

    for (int i = 0; i < sentence.length(); i++) // checking each character in string to see which type it is
    {
        // counts number of vowels
        if (vowels.find(sentence.at(i)) != string::npos)
        {
            if (debug)
            {
                debugStatement("found vowels and counting");
            }
            numVowels++;
        }
        // counts number of consonants
        else if (isalpha(sentence.at(i)))
        {
            if (debug)
            {
                debugStatement("found consonants and counting");
            }
            numConsonants++;
        }
        // counts number of spaces
        else if (isspace(sentence.at(i)))
        {
            if (debug)
            {
                debugStatement("found spaces and counting");
            }
            numSpaces++;
        }
        // counts number of punctuation marks
        else if (punctuation.find(sentence.at(i)) != string::npos)
        {
            if (debug)
            {
                debugStatement("found punctuation marks and counting");
            }
            numPunc++;
        }
        else
        {
            if (debug)
            {
                debugStatement("found other characters and counting");
            }
            // counts other characters
            numOther++;
        }
    }
}

// function that capitalizes the first letter of every word
string titleCase(string sentence, bool debug)
{

    for (int i = 0; i < sentence.length(); i++)
    {
        sentence.at(i) = tolower(sentence.at(i)); // makes every character lowercase
    }
    if (debug)
    {
        debugStatement("converted all characters to lowercase");
    }

    sentence.at(0) = toupper(sentence.at(0)); // capitalizes the first letter of the first word in the sentence
    if (debug)
    {
        debugStatement("capitalized first letter of the sentence");
    }

    for (int i = 1; i < sentence.length(); i++)
    { // if the previous character is a space, capitalize the next character
        if (isspace(sentence.at(i - 1)) || i == 0)
        {
            sentence.at(i) = toupper(sentence.at(i));
        }
    }
    if (debug)
    {
        debugStatement("capitalized all first letters of each word");
    }

    return sentence;
}

// capitalizes the first letter of the first word of the sentence
string sentenceCase(string sentence, bool debug)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        sentence.at(i) = tolower(sentence.at(i)); // makes every character lowercase
    }
    if (debug)
    {
        debugStatement("converted all characters to lowercase");
    }

    sentence.at(0) = toupper(sentence.at(0)); // capitalizes the first letter of the first word in the sentence

    if (debug)
    {
        debugStatement("capitalized first letter of the sentence");
    }
    return sentence;
}

string toggleCase(string sentence, bool debug)
{

    // uppercases all characters
    for (int i = 0; i < sentence.length(); i++)
    {
        sentence.at(i) = toupper(sentence.at(i));
    }

    sentence.at(0) = tolower(sentence.at(0)); // lowercases the first letter of the first word of the sentence

    for (int i = 1; i < sentence.length(); i++)
    { // if the previous character is a space, lowercase the next character
        if (isspace(sentence.at(i - 1)) || i == 0)
        {
            sentence.at(i) = tolower(sentence.at(i));
        }
    }
    return sentence;
}

int main()
{
    int numVowels = 0;
    int numConsonants = 0;
    int numSpaces = 0;
    int numPunc = 0;
    int numOther = 0;

    ofstream outfile;
    outfile.open("output.txt");
    string nameOfFile = "input.txt";

    vector<string> sentences = readFileData(nameOfFile, false); // calling function to read in sentences from file

    // loops through "sentences" vector to use
    for (int i = 0; i < sentences.size(); i++)
    {
        // printing to console
        cout << "ORIGINAL SENTENCE: " << sentences.at(i) << endl;
        cout << "NUMBER OF CHARACTERS IN SENTENCE: " << countNumChars(sentences.at(i), false) << endl;
        cout << "NUMBER OF WORDS IN SENTENCE: " << countWords(sentences.at(i), false) << endl;
        cout << "LONGEST WORD IN SENTENCE: " << findLongestWord(sentences.at(i), false) << endl;

        cout << "NUMBER OF CHARACTERS" << endl;
        countAllCharacters(sentences.at(i), numVowels, numConsonants, numSpaces, numPunc, numOther, false);
        cout << "Vowels: " << numVowels << endl;
        cout << "Consonants: " << numConsonants << endl;
        cout << "Spaces: " << numSpaces << endl;
        cout << "Punctuation: " << numPunc << endl;
        cout << "Other: " << numOther << endl;
        cout << "TITLE CASE: " << titleCase(sentences.at(i), false) << endl;
        cout << "SENTENCE CASE: " << sentenceCase(sentences.at(i), false) << endl;
        cout << "TOGGLE CASE: " << toggleCase(sentences.at(i), false) << endl;
        cout << endl;

        // printing to file
        if (outfile.is_open())
        {
            outfile << "ORIGINAL SENTENCE: " << sentences.at(i) << endl;
            outfile << "NUMBER OF CHARACTERS IN SENTENCE: " << countNumChars(sentences.at(i), false) << endl;
            outfile << "NUMBER OF WORDS IN SENTENCE: " << countWords(sentences.at(i), false) << endl;
            outfile << "LONGEST WORD IN SENTENCE: " << findLongestWord(sentences.at(i), false) << endl;

            outfile << "NUMBER OF CHARACTERS" << endl;
            outfile << "Vowels: " << numVowels << endl;
            outfile << "Consonants: " << numConsonants << endl;
            outfile << "Spaces: " << numSpaces << endl;
            outfile << "Punctuation: " << numPunc << endl;
            outfile << "Other: " << numOther << endl;
            outfile << "TITLE CASE: " << titleCase(sentences.at(i), false) << endl;
            outfile << "SENTENCE CASE: " << sentenceCase(sentences.at(i), false) << endl;
            outfile << "TOGGLE CASE: " << toggleCase(sentences.at(i), false) << endl;
            outfile << endl;
        }
    }
    return 0;
}
