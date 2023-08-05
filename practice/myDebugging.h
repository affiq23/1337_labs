// myDebugging.h
// Doug DeGroot
//
// changelog:
//  7/12/21 - commented out the #define SSTR command; around line 19
//      uncommented ckError which was commented for some reason
//  2/27/22 - combined a few other debug.h files into this one

#ifndef MY_DEBUGGING_H
#define MY_DEBUGGING_H

#include <iostream>
#include <string>
#include <sstream>
//#include "myUtils.h"
using namespace std;

// start with all debugging routines turned off
//
bool debugging = false;
bool showflowdebugging = false;
bool showflowControl = false;
bool debugPrinting = false;
int dbgCnt = -1; //debug counter, initialize to 'debug now'

//------- inserted


string myIntToString (int val) {
    //int Number = 123;     // number to be converted to a string
    string result; // string that will contain the result
    ostringstream convert;  // stream used for the conversion
    convert << val; // insert the textual representation of 'val' into the stream
    result = convert.str(); // set 'result' to the contents of the stream
                            // 'result' is now set to "123"
    return result;
} //myIntToString


string createBlurb (string s1, int n) {
    return s1+myIntToString(n);
} //createBlurb

void showflow (string msg) {
    if (showflowdebugging)
        cout << "--- at: " << msg << endl;
} // showflow


void showflow (string msg,char ch) {
    if (showflowdebugging)
		cout << "--- at: " << msg << " " << ch << endl;
} // showflow


void showflow (string msg, int num) {
//    if (showflowControl)
//		cout << "--- at: " << msg << " with " << num << endl;
} // showflow


void showflow (string msg, int num1, int num2) {
    if (showflowControl)
        cout << "--- at: " << msg << " " << num1 << " " << num2 << endl;
} // showflow


void showflow (string msg,string msg2) {
    if (showflowControl)
        cout << "--- at: " << msg << ' ' << msg2 << endl;
} // showflow


// ckError - compare to C++'s assert
// if condition doesn't hold, report the error, pause, and then continue
void ckError(bool condition,string errorString,bool exiting="true") {
   if (condition) {
      cout << errorString << endl;
      system("pause");
      if (exiting)
        exit(EXIT_FAILURE);
   }
} //ckError


//bool ckError(bool condition,string errorString,string location="") {
//   if (condition) {
//	if (location != "")
//	      location = ", at: " + location;
//	cout << errorString << location << endl;
//    system("pause");
//    return true;
//   }
//   return false;
//} //ckError
//

bool warn(bool condition,string errorString) {
   if (condition) {
      cout << "WARNING: " << errorString << endl;
      system("pause");
      return true;
   }
   return false;
} //warn

// ensure - compare to C++'s assert
// if condition doesn't hold, report the error, pause, and then continue
void ensure(bool condition,string errorString="") {
   if (!condition) {
      cout << "ensure failed: " << errorString << endl;
      system("pause");
      exit(EXIT_FAILURE);
   }
} //ensure


void setDbgCnt (int cnt) {
	dbgCnt = cnt;
}

void showDebugHelp() {
    cout << "Add some help here for the debugging system." << endl;
}

//---------- debugging routines ----------//
void ckDbgCnt (string blurb, int num=0) {
    int n;
    if (debugPrinting && (dbgCnt-- <= 1)) {
        cout << blurb << ' ' << num << endl;
        cout << "? "; //type some prompt, ? is probably not good
        cin >> n;
        if (n > 0) dbgCnt = n;
        if (n == -2) {
         debugPrinting = !debugPrinting;
         if (debugPrinting)
            cout << "set debugPrinting to true\n";
         else
            cout << "set debugPrinting to false\n";
        }
    }
} //ckDbgCnt

void dprint(string blurb) {
    ckDbgCnt(blurb);
}

void dprint (string blurb, int val) {
    ckDbgCnt(createBlurb(blurb,val));
} // dprint

void dprint (string blurb, string val) {
    ckDbgCnt(blurb+val);
} // dprint


// -----------------------

void dprint2 (string blurb, int val=0) {
    //cout << "here in dprint" << endl;
    if (val == 0)
        ckDbgCnt(blurb);
    else
        ckDbgCnt(blurb+myIntToString(val));
} // dprint


void dprint (string blurb, int val1, int val2) {
    //cout << "--- at dprint" << endl;
    ckDbgCnt(blurb+' '+myIntToString(val1)+' '+myIntToString(val2));
} // dprint



//---------- OLD STUFF - SAVE FOR REUSE ----------//
/*
#define SSTR(x) static_cast< std::ostringstream & >( \
        (std::ostringstream() << std::dec << x ) ).str()
*/

#endif
