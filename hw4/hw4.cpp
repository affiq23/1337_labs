#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string filename = "output.txt";
    ifstream input_file(filename);
    vector<string> sentences;

    if (input_file)
    {
        string line;
        string sentence;
        while (getline(input_file, line))
        {
            for (char &c : line)
            {
                sentence += c;
                if (c == '.')
                {
                    sentences.push_back(sentence);
                    sentence.clear();
                }
            }
        }
        if (!sentence.empty())
        {
            sentences.push_back(sentence);
        }
    }
    else
    {
        cout << "Error: could not open file " << filename << endl;
    }

    input_file.close();

    // use the vector of sentences here
    for (int i = 0; i < sentences.size(); i++)
    {
        cout << sentences.at(i) << endl;
    }

    cout << endl;

    return 0;
}
