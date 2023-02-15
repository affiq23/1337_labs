#include <iostream>
#include <string>

using namespace std;

// Dimensions of the board
const int ROWS = 18;
const int COLS = 18; 




// Recursive function that performs a depth-first search
bool dfs(char board[][COLS], int i, int j, int k, string word) {
    // If the current index is out of bounds, or the current element is not equal to the current character of the word, return false
    if (i < 0 || i >= ROWS || j < 0 || j >= COLS || board[i][j] != word[k]) {
        return false;
    }
    // If the entire word has been found, return true
    if (k == word.length() - 1) {
        return true;
    }
    // Temporarily mark the current element as visited by assigning it a value of '#'
    char temp = board[i][j];
    board[i][j] = '#';
    // Search the surrounding elements in all four directions
    bool found = dfs(board, i - 1, j, k + 1, word) || 
                 dfs(board, i + 1, j, k + 1, word) || 
                 dfs(board, i, j - 1, k + 1, word) || 
                 dfs(board, i, j + 1, k + 1, word);
    // Restore the original value of the current element
    board[i][j] = temp;
    return found;
}

// Main function that searches the word in the board
bool search(char board[][COLS], string word) {
    // Iterate through all elements of the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Check if the current element is equal to the first character of the word
            if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                cout << "The word " << word << " was found at (" << i << ", " << j << ")" << endl;
                return true;
            }
        }
    }
    // If the word is not found, return false
    return false;
}

int main() {
    // Create a 2D array to represent the board
    char board[ROWS][COLS] = {{'A', 'B', 'C', 'E', 'H', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'Q', 'W', 'E', 'R', 'T'},
                          {'S', 'F', 'C', 'S', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V'},
                          {'A', 'D', 'E', 'E', 'L', 'K', 'J', 'H', 'G', 'F', 'D', 'S', 'A', 'W', 'Q', 'E', 'R'},
                          {'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'},
                          {'C', 'B', 'A', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'},
                          {'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'}};
    // Create a string to represent the word to search for
    string word = "ASA";

    // Print the board
    cout << "The board is:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    // Search for the word in the board
    bool found = search(board, word);
    if (!found) {
        cout << "The word " << word << " was not found in the board." << endl;
    }

    return 0;
}
