// myUtils.h
// Doug DeGroot
// main version - 3/13/19
//
// changelog:
//	3/13/19 - added fontsize
//	3/15/19 - added the definition for pause()
//	4/6/19 - add fontsize, but sometimes it doesn't work; why?
//	6/18/20 - fixed sp2 and sp3; changed from '  ' to "  ", etc.
//


#include <iostream>
#include <string>
#include <fstream>
//#include <Windows.h> // for fontsize
#include <cctype>
#include <cstdlib> //for exit
#include <cassert> //for assert
#include <vector>
#include <time.h> //rand srand, et al


using namespace std;

// declare some useful constants
#define sp  ' '
#define sp2 "  "
#define sp3 "   "
#define sp4 "    "
#define sp5 = "     "
#define sp10 = "          "

#define sep ", "

// ===== show and other output routines ===== //

bool showing = true;

void show(string msg) {
	if (showing)
		cout << msg << endl;
} //show

void show(string msg1, string msg2) {
	if (showing)
		cout << msg1 << ": " << msg2 << endl;
} //show

void show(string msg, int num) {
	if (showing)
		cout << msg << ": " << num << endl;
} //show

void show(string msg, int num1,int num2) {
	if (showing)
		cout << msg << ": " << num1 << sp << num2 << endl;
} //show

void show(string msg, unsigned int num) {
	if (showing)
		cout << msg << " " << num << endl;
} //show

void show(string msg, char ch) {
	if (showing)
		cout << msg << " " << ch << endl;
} //show

void show(string msg, bool val) {
	if (showing)
		cout << msg << " " << val << endl;
} //show

void display(string msg) { //for basic display purposes, not for debugging
    cout << msg << endl;
} //display

void showVector(string msg, vector<string> &v) {
	cout << msg << endl;
	for (auto val : v)
		cout << val << " ";
	cout << endl;
} //showVector

void line() {
   cout << "---------------------------------------" << endl;
} //line

void thickLine() {
   cout << "=======================================" << endl;
} //line

//============================================//

// ===== misc system routines ========================-- //

void pause() {
    system("pause");
} //pause


void greenScreen() { //set the font color to green
	system("color A"); //A=green, B=light blue, C=red
} //greenScreen

void blueScreen() { //set the font color to green
	system("color B"); //A=green, B=light blue, C=red
} //blueScreen

void redScreen() { //set the font color to green
	system("color C"); //A=green, B=light blue, C=red
} //blueScreen

void setRandomScreenColor() {
    srand(time(0));
    int foo = rand() % 3;
    switch (foo) {
    case 0:
        greenScreen();
        break;
    case 1:
        redScreen();
        break;
    case 2:
        blueScreen();
        break;
    }
    return;
} //setRandomScreenColor


bool askYN(string question="") {
  if (question != "")
	  cout << question << ": ";
  string foo;
  cin >> foo;
  cin.ignore();
  cout << "input = " << foo << endl;
  cout << "askYN = " << toupper(foo[0]) << endl;
  return (toupper(foo[0]) == 'Y');
} //askYN


// ===== IO and File Routines ============================= //


bool openForReading(ifstream &infile,string fileName) {
	infile.open(fileName);
	if (infile.good()) //then the file opened just fine
		return true;
	else {
		perror("Can't open specified file:");
		cout << "The file name used was: " << fileName << endl;
		cout << "Enter another file name to use (or quit): ";
		getline(cin,fileName);
		cout << "--- the new file name is: " << fileName << endl;
		if (fileName != "quit") // maybe check for QUIT, too
			return openForReading(infile,fileName); //note the use of recursion here
		else return false;
	}
} //openFor Reading


bool openForWriting(ofstream &outfile,string fileName) {
	outfile.open(fileName);
	if (outfile.good()) //then the file opened just fine
		return true;
	else {
		perror("Can't open the specified output file");
		cout << "The file name used was: " << fileName << endl;
		cout << "Enter another file name to use (or quit): ";
		getline(cin,fileName);
		cout << "--- The new file name is: " << fileName << endl;
		if (fileName != "quit") {
			openForWriting(outfile,fileName); //note the use of recursion here
			return true;
		}
		else return false; //or should I actually EXIT here?
	}
} //openForWriting


// showFileStatus
void showFileStatus(ifstream &theStream) {
    show("File Status:");
    cout << "EOF bit:" << theStream.eof() << endl;
    cout << "FAIL bit:" << theStream.fail() << endl;
    cout << "BAD bit:" << theStream.bad() << endl;
    cout << "GOOD bit:" << theStream.good() << endl;
    theStream.clear();
} //showFileStatus



// ===== Console Utilities ============================= //


// fontsize - requires <Windows.h>
// The following are symmetric font sizes.
// 4:6, 6:8. 8:8, 16:8, 5:12, 7:12, 16:12, 12:16, 10:18
// example call:
// int main(){
//   fontsize(8,24);
//   cout << "This is a symmetrical font" << endl;
//   system("pause");
// }
//// prototype: void fontsize(int,int);
//
//#include "windows.h"
//#define fontSize fontsize
//void fontsize(int a, int b){
//	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
//	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
//	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
//	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
//	lpConsoleCurrentFontEx->dwFontSize.X = a;
//	lpConsoleCurrentFontEx->dwFontSize.Y = b;
//	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
//} //fontsize


// ===== END =========================================== //





