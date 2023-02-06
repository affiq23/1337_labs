/*
PROGRAM NAME: HW1 - SNAKE GAME EXTENSIONS
NAME: Affiq Mohammed
DATE LAST MODIFIED: 02/5/2023
CLASS SECTION: CS 1337.012
PURPOSE: A simple game that uses WASD keys to control a snake on screen that can eat a piece of fruit to
keep growing; eating more fruit increases score
CHANGELOG:
01/25/23: renamed functions to more accurately describe role in code;
          added brackets to if statements and for loops;
          added first bracket of function to same line declararation to use less lines;
          added uppercase keys to switch statements as well (kept clicking caps lock and game wouldn't
          let me turn snake in time);

02/02/23: added instructions at beginning of program to inform user how to play;
          took functions in main and put them in their own playGame() function to call from main;

02/05/23: implemented functionality so when snake runs into a wall, it quits game;
          added feature where user can quit game by clicking "X";
          added function checkTail() that displays at the end of the game whether or not the user lost due to running
          into their own tail;
          made inputs case insensitive;
          trying to add play again feature, board resets with snake but is frozen;
          added pause functionality

  
*/

#include <iostream>
#include <ncurses.h>
using namespace std;
bool gameOver;
bool ranIntoTail = false;
const int width = 20;
const int height = 20;
int snakeHeadXPos, snakeHeadYPos, fruitXPos, fruitYPos, score;
int tailXPos[100], tailYPos[100];
int tailLength;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void setupGameBoard(){
    gameOver = false;
    dir = STOP;
    snakeHeadXPos = width / 2;
    snakeHeadYPos = height / 2;
    fruitXPos = rand() % width; //sets X coordinate position for fruit
    fruitYPos = rand() % height; //sets Y coordinate position for fruit
    score = 0;
    initscr();
    noecho();
    timeout(100);
}

void drawSnakeOnBoard(){
    //clears board and draws border
    system("clear");
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << "\r" << endl;

    //printing snake items on board
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (j == 0){
                cout << "#";
            }

        if (i == snakeHeadYPos && j == snakeHeadXPos){
                cout << "O"; // print snake head 
        }
        else if (i == fruitYPos && j == fruitXPos){
                cout << "F"; // printing fruit
        } 
         else {
         bool print = false;
         for (int k = 0; k < tailLength; k++){
            if (tailXPos[k] == j && tailYPos[k] == i){
                 cout << "o"; // printing additional bodies to snake if fruit is eaten
                 print = true;
                }
            }
            if (!print){
                cout << " ";
                 }
            }

    //whole segment is just setting up board when user selects "Y"
        if (j == width - 1){
                cout << "#";
            }
        }
        cout << "\r" << endl;
    }
    for (int i = 0; i < width + 2; i++){
        cout << "#";
    }

    //printing further instructions at bottom of game
    cout << "\r" << endl;
    cout << "Score: " << score << "\r" << endl;
    cout << "Press 'X' to quit." << "\r" << endl;
    cout << "Press 'P' to pause." << "\r" << endl;
}

// switch case gets the specific key user inputs to move the snake
void userInput(){
    switch (getch())
    {
    case 'a': // added support for both uppercase and lowercase keyboard input
        dir = LEFT;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 'w':
        dir = UP;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'p': //lets user pause game
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
         break;
    case 'x':
        gameOver = true;
        break;
    case 'A':
        dir = LEFT;
        break;
    case 'D':
        dir = RIGHT;
        break;
    case 'W':
        dir = UP;
        break;
    case 'S':
        dir = DOWN;
        break;
    case 'P': //lets user pause game
        system( "read -n 1 -s -p \"Press any key to continue...\"" );
         break;
    case 'X':
        gameOver = true;
        break;
    }
}

void snakeLogic(){

    int prevX = tailXPos[0];
    int prevY = tailYPos[0];
    int prev2X, prev2Y;
    tailXPos[0] = snakeHeadXPos;
    tailYPos[0] = snakeHeadYPos;

    for (int i = 1; i < tailLength; i++){
        prev2X = tailXPos[i];
        prev2Y = tailYPos[i];
        tailXPos[i] = prevX;
        tailYPos[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    //keyboard input determines which direction to go, which then tells snakeHead positions where to move
    switch (dir){
    case LEFT:
        snakeHeadXPos--;
        break;
    case RIGHT:
        snakeHeadXPos++;
        break;
    case UP:
        snakeHeadYPos--;
        break;
    case DOWN:
        snakeHeadYPos++;
        break;
    default:
        break;
    }

    //this whole segment checks if snake head hits a wall, then the game quits
    if ((snakeHeadXPos > width || snakeHeadXPos < 0) || (snakeHeadYPos > height || snakeHeadYPos < 0)){
        gameOver = true;
    }
    if (snakeHeadXPos >= width){
        snakeHeadXPos = 0;
        gameOver = true;
    } 
    else if (snakeHeadXPos < 0){
        snakeHeadXPos = width - 1;
    }
    if (snakeHeadYPos >= width){
        snakeHeadYPos = 0;
    }
    else if (snakeHeadYPos < 0){
        snakeHeadYPos = width - 1;
    }


    //checks if snake head runs into its own tail
    for (int i = 0; i < tailLength; i++){ 
        if (tailXPos[i] == snakeHeadXPos && tailYPos[i] == snakeHeadYPos){
            gameOver = true;
            ranIntoTail = true;
        }
    }

    //checks if tail hits border of game board
    for (int i = 0; i < tailLength; i++){
        if (tailXPos[i] == width || tailYPos[i] == height){
            gameOver = true;
        }
    }

    //adds to snake tail every time snake head eats a piece of fruit
    if (snakeHeadXPos == fruitXPos && snakeHeadYPos == fruitYPos) {
        score += 10;
        fruitXPos = rand() % width;
        fruitYPos = rand() % height;
        tailLength++;
    }
}

//displays at the beginning of the program when you run for the first time
string instructions()
{
    string answer;
    cout << "Welcome to Snake!\nTry to eat the fruit and avoid running into your tail.\n";
    cout << "Would you like to play? Y or N\n";
    cin >> answer;
    return answer;
}


//check if user lost the game because they ran into their own tail
void checkTail(){

    if (ranIntoTail){ //just returns if you ran into your tail or not
        cout << "You ran into your tail!\n";
    }
    else{
        cout << "You didn't run into your tail!\n";
    }
}

//took the functions in the main function and put them in their own function so they can be called in a more efficient manner
void playGame(){
    setupGameBoard();

    while (!gameOver){
        drawSnakeOnBoard();
        userInput();
        snakeLogic();
    }

    endwin();
    checkTail();
}

int main(){

    string choice;
    //checking if the user wants to play or not
    if (instructions() == "Y"){ 
        playGame();
    
    //restarting if the player wants to play again; the board resets, but unable to interact with the program when it runs again
    if(gameOver == true){ 
        cout << "Do you want to play again? Y or N\n",
        cin >> choice;
        //resets board
        if(choice == "Y"){
            gameOver = false;
            tailLength = 0;
            playGame();
        }
    }
}

    return 0;
}