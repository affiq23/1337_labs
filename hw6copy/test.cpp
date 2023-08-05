#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream datafile;
    ofstream report;
    string line;
    string temp;
    string name;
    string atype;
    string age;
    string weight;
    string color;
    string sound;
    string health;
    string breed;

    datafile.open("animals.csv");
    if (!datafile)
    {
        cout << "Error in file reading" << endl;
        return 0;
    }
    getline(datafile, line); // skip header line
    getline(datafile, line); // Get the frist line from the file, if any.
    while (datafile)
    { // Continue if the line was sucessfully read.
        // Process the line.
        atype = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        name = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        age = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        weight = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        breed = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        color = line.substr(0, line.find(','));
        line = line.erase(0, line.find(',') + 1);
        health = line.substr(0, line.find(','));
        sound = line.erase(0, line.find(',') + 1);

         
    }

   

        return 0;
    }
