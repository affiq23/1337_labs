#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// For searching in all 8 directions
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int row = 0;
int col = 0;

ifstream file;
string fileName;
string line;
vector<string> words;
vector<string> noSpaceWords;
vector<string> wordsNotFound;
vector<string> uppercaseWords;

//function to check the file name and open it if it exists
void checkAndOpenFile(){
    cout << "Enter the file name: ";
    cin >> fileName;
    cout << "\n";
    file.open(fileName.c_str());

    while (file.fail())
    {
        file.clear(); //clearing the original file value
        cout << "Oops, can't open specified input file. No such file or directory." << endl;
        cout << "The file name used was " << fileName << endl;
        cout << "Enter another file name to use (or quit): ";
        cin >> fileName;
        cout << "The new file name is " << fileName << endl;
        cout << "\n";
        file.open(fileName.c_str());
    }

}

// Searches the array and returns true if found
bool search2D(char *grid, int row, int col, string word, int R, int C, int &direction)
{
    // If first character of word doesn't
    // match with given starting point in grid.
    if (*(grid + row * C + col) != word[0])
    {
        // cout << "Nothing at " << row << " " << col << endl;
        return false;
    }
     int length = word.length();
    // cout << "len is " << len << endl;

    // Search word in all 8 directions
    // starting from (row, col)
    for (int dir = 0; dir < 8; dir++)
    {
     
     //initialize starting point
        int checkingLen;
        int rd = row + x[dir];
        int cd = col + y[dir];

     

       //check if remaining characters match
        for (checkingLen = 1; checkingLen < length; checkingLen++)
        {
            // cout << "k: " << k << endl;
            //  If out of bound break
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;

            // If not matched,  break
            if (*(grid + rd * C + cd) != word[checkingLen])
                break;

            // Moving in particular direction
            rd += x[dir];
            cd += y[dir];
            
        }

        // If all character matched, then value of k equals the length of the word
        if (checkingLen == length)
        {
            direction = dir;
            return true;
        }
    }
    return false;
}

// Searches given word in a given
// matrix in all 8 directions
int patternSearch(char *grid, string wordNoSpace, string wordSpace, int R, int C, int &dir)
{
    //  every point start
    // point and search words
    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
        {
            if (search2D(grid, row, col, wordNoSpace, R, C, dir))
            {
                if (dir != 0)
                    cout << wordNoSpace << " found at " << row + 1<< ", " << col + 1<< ": "; //incrementing row and col by one to get rid of zero-based index
            }
        }
    }
    return dir;
}


int main(){

   
    checkAndOpenFile(); //checks and opens file


    // Get rows and columns
    while (!file.eof())
    {
        getline(file, line);
        if (line[0] != '#' && line.length() != 0 && line.length() != 1)
        {

            stringstream s(line);
            s >> row >> col;
            break;
        }
    }
    cout << "Nbr Rows: " << row << ";  Nbr Cols: " << col << endl;

    // Create matrix
    char matrix[row][col];
    while (true)
    {
        getline(file, line);
        if (line[0] != '#' && line.length() != 0 && line.length() != 1)
        {
            for (int i = 0; i < row; i++)
            {
                if (line[0] != '#' && line.length() != 0 && line.length() != 1)
                {
                    for (int j = 0; j < line.length(); j++)
                    {
                        matrix[i][j] = line[j];
                    }
                }
                getline(file, line);
            }
            break;
        }
    }

    // display matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << matrix[i][j];

        cout << endl;
    }

    // get the words
    

    while (!file.eof())
    {
        getline(file, line);
        if (line[0] != '#' && !isspace(line[0]))
        {
            words.push_back(line);
        }
    }

    // get rid of the empty vectors
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].length() == 0)
        {
            words.erase(words.begin() + i);
        }
    }

    // make a copy of words with all capital letters
   

    for (int i = 0; i < words.size(); i++){
        string delimiter = "\n";
        string line1 = words[i];
       for (auto& c : line1) {
        c = toupper(static_cast<unsigned char>(c));
    }

        //removing the \n occurence
        size_t pos = 0;
         while ((pos = line1.find(delimiter)) != std::string::npos) {
        line1.erase(pos, delimiter.length());
    }

        uppercaseWords.push_back(line1);
    }


    // copy words with no spaces
    for (int i = 0; i < words.size(); i++)
    {
       for (const auto& word : words) {
        std::string temp;
        for (char c : word) {
            if (!std::isspace(c)) {
                temp += std::toupper(c);
            }
        }
        noSpaceWords.push_back(temp);
        }
    }

    cout << endl;

    // search and get directions
    for (int i = 0; i < words.size(); i++)
    {
        int direction = 0;
        direction = patternSearch((char *)matrix, noSpaceWords[i], words[i], row, col, direction);
        if (direction == 0)
            wordsNotFound.push_back(words[i]);
        else if (direction == 1)
            cout << "(direction = N)" << endl;
        else if (direction == 2)
            cout << "(direction = NE)" << endl;
        else if (direction == 3)
            cout << "(direction = W)" << endl;
        else if (direction == 4)
            cout << "(direction = E)" << endl;
        else if (direction == 5)
            cout << "(direction = SW)" << endl;
        else if (direction == 6)
            cout << "(direction = S)" << endl;
        else if (direction == 7)
            cout << "(direction = SE)" << endl;
        else if (direction == 8)
            cout << "(direction = NW)" << endl;
        else
            wordsNotFound.push_back(words[i]);
    }

    cout << endl
         << "Couldn't find these movies:" << endl;
    for (int i = 0; i < wordsNotFound.size(); i++)
    {
        cout << wordsNotFound[i] << endl;
    }

    return 0;
}

