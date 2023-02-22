/* CHANGELOG:
    -took Geeks program and tried to implement features
    -added file functionality
    -created matrix from file data
    -can display matrix
    -renamed variables to more relevant names
    -modified patternsearch and search2Darray
    -not able to print out words without spaces
    -still have to implement quit feature for file name properly
    -wrong index appearing

*/

/* SPECIAL INFO:
    written and compiled on VS Code using g++ HW-1337-Affiq-Mohammed.cpp tag in terminal; 
    gives warnings, but thats's because my compiler doesn't have C++ 11 installed for range 
    based for loops 
*/

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

fstream file;
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

    while (file.fail()) {
        file.clear(); //clearing the original file value
        cout << "Oops, can't open specified input file. No such file or directory." << endl;
        cout << "The file name used was " << fileName << endl;
        cout << "Enter another file name to use (or quit): ";
        cin >> fileName;
        cout << "The new file name is " << fileName << endl;
        cout << "\n";

        if(fileName == "quit"){
            break;
        }
        file.open(fileName.c_str());
    }

}

//searches array for word
bool search2D(char *grid, int row, int col, string word, int R, int C, int &direction){
    
    if (*(grid + row * C + col) != word[0]){ //if the first character doesn't match starting point
        return false;
    }

     int length = word.length();

    //search from [row][col]
    for (int dir = 0; dir < 8; dir++) {
     
     //initialize starting point
        int checkingLen;
        int startrow = row + x[dir];
        int startcol = col + y[dir];

       //check if remaining characters match
        for (checkingLen = 1; checkingLen < length; checkingLen++){
            //break if out of bounds
            if (startrow >= R || startrow < 0 || startcol >= C || startcol < 0){
                break;
            }

           //if no match
            if (*(grid + startrow * C + startcol) != word[checkingLen]){
                break;
             }

            startrow += x[dir];
            startcol += y[dir];
            
        }

        //checkingLen should equal length if all characters match
        if (checkingLen == length){
            direction = dir;
            return true;
        }
    }
    return false;
}


//searches for word in all directions
int patternSearch(char *grid, string wordNoSpace, string wordSpace, int R, int C, int &direction){
    //  every point start
    // point and search words
    for (int row = 0; row < R; row++){
        for (int col = 0; col < C; col++){
            if (search2D(grid, row, col, wordNoSpace, R, C, direction)){
                if (direction != 0){
                    cout << wordNoSpace << " found at " << row++ /*+1?*/<< ", " << col++<< ": "; 
                }
            }
        }
    }
    return direction;
}


int main(){

    checkAndOpenFile(); //checks and opens file

    //get rows, cols
    while (!file.eof())
    {
        getline(file, line);
        if (line[0] != '#' && line.length() != 0 && line.length() != 1){

            stringstream s(line); //had to google
            s >> row >> col;
            break;
        }
    }
    cout << "# of Rows: " << row << ";  # of Cols: " << col << endl;

    // create matrix
    char matrix[row][col];
    while (true){
        getline(file, line);
        if ((line[0] != '#' && line.length() != 1 && line.length() != 0)){ //checking if character is not # and exists
            for (int i = 0; i < row; i++) {
                if (line[0] != '#' && line.length() != 1 && line.length() != 0){ 
                    for (int j = 0; j < line.length(); j++){
                        matrix[i][j] = line[j];
                    }
                }
                getline(file, line);
            }
            break;
        }
    }

    // display matrix
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
            cout << matrix[i][j];
        cout << endl;
    }

    // get words from file
    while (!file.eof()){
        getline(file, line);
        if (line[0] != '#' && !isspace(line[0])){
            words.push_back(line);
        }
    }
    
    // make a copy of words with all capital letters
    for (int i = 0; i < words.size(); i++){
        string delimiter = "\n";
        string line1 = words[i];
       for (auto& c : line1) {
        c = toupper(static_cast<unsigned char>(c)); //also had to google
    }
        uppercaseWords.push_back(line1);
    }


    // copy words with no spaces
    for (int i = 0; i < words.size(); i++)
    {
       for (const auto& word : words) {
        string tempString;
        for (char c : word) {
            if (!isspace(c)) { // and this
                tempString += toupper(c);
            }
        }
        noSpaceWords.push_back(tempString);
        }
    }

    cout << endl;

    // search and get directions one by one
    for (int i = 0; i < words.size(); i++){
        int checkDir;
        checkDir = patternSearch((char *)matrix, noSpaceWords[i], words[i], row, col, checkDir);
        if (checkDir == 0){
            wordsNotFound.push_back(words[i]);
        }
        else if (checkDir == 1){
            cout << "(direction = N)" << endl;
        }
        else if (checkDir == 2){
            cout << "(direction = NE)" << endl;
        }
       else  if (checkDir == 3){
            cout << "(direction = W)" << endl;
        }
        else if (checkDir == 4){
            cout << "(direction = E)" << endl;
        }
       else  if (checkDir == 5){
            cout << "(direction = SW)" << endl;
        }
       else if (checkDir == 6){
            cout << "(direction = S)" << endl;
        }
       else  if (checkDir == 7){
            cout << "(direction = SE)" << endl;
        }
        else if (checkDir == 8){
            cout << "(direction = NW)" << endl;
        }
        else{
            wordsNotFound.push_back(words[i]);
        }
    }

    cout << endl << "Couldn't find these movies:" << endl; //returns movies not found
    for (int i = 0; i < wordsNotFound.size(); i++){
        cout << wordsNotFound[i] << endl;
    }

    return 0;
}