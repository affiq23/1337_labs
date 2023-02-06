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

  
*/

#include <iostream>
#include <ncurses.h>
using namespace std;
bool gameOver;
bool ranIntoTail = false;
const int width = 20;
const int height = 20;
int x, y, fruitXPos, fruitYPos, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void setupBoard()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitXPos = rand() % width;
    fruitYPos = rand() % height;
    score = 0;
    initscr();
    noecho();
    timeout(100);
}

void drawSnake()
{
    system("clear");
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }

    cout << "\r" << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "#";
            }

            if (i == y && j == x)
            {
                cout << "O"; // print snake head
            }
            else if (i == fruitYPos && j == fruitXPos)
            {
                cout << "F"; // printing fruit
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o"; // printing additional bodies to snake if fruit is eaten
                        print = true;
                    }
                }

                if (!print)
                {
                    cout << " ";
                }
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << "\r" << endl;
    }

    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }

    cout << "\r" << endl;
    cout << "Score: " << score << "\r" << endl;
    cout << "Press 'X' to quit."
         << "\r" << endl;
    cout << "Press 'P' to pause."
         << "\r" << endl;
}

// switch case gets the specific key user inputs to move the snake
void userInput()
{

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
    case 'X':
        gameOver = true;
        break;
    }
}

void snakeLogic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if ((x > width || x < 0) || (y > height || y < 0))
    {
        gameOver = true;
    }
    if (x >= width)
    {
        x = 0;
        gameOver = true;
    }
    else if (x < 0)
    {
        x = width - 1;
    }
    if (y >= width)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = width - 1;
    }



    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
            ranIntoTail = true;
        }
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == width || tailY[i] == height)
        {
            gameOver = true;
        }
    }

    if (x == fruitXPos && y == fruitYPos)
    {
        score += 10;
        fruitXPos = rand() % width;
        fruitYPos = rand() % height;
        nTail++;
    }
}

// displays at the beginning of the program when you run for the first time
string instructions()
{
    string answer;
    cout << "Welcome to Snake Game!\nThe objective is to eat the fruit pieces and avoid running into yourself.\n";
    cout << "Would you like to play? Y or N\n";
    cin >> answer;
    return answer;
}


// check if user lost the game because they ran into their own tail
void checkTail()
{

    if (ranIntoTail){
        cout << "You ran into your tail!\n";
    }
    else{
        cout << "You didn't run into your tail!\n";
    }
}

// took the functions in the main function and put them in their own function so they can be called in a more efficient manner
void playGame()
{

    setupBoard();

    while (!gameOver)
    {
        drawSnake();
        userInput();
        snakeLogic();
    }
    endwin();
}

int main()
{

    string choice;

    if (instructions() == "Y")
    { // checking if the user wants to play or not
        playGame();
        checkTail();
    
    if(gameOver == true){
        cout << "Do you want to play again? Y or N\n",
        cin >> choice;
        if(choice == "Y"){
            gameOver = false;
            nTail = 0;
            playGame();
        }
    }



    }

    return 0;
}