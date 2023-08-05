// Books Struct - Testing
// Doug DeGroot
//
// Notes:
//  You should probably play around with this program and
//  see what you can do to it and learn from it.
//
//  The displayBook function is terribly weak. Maybe fix it.
//
#include <iostream>
#include <vector>

using namespace std;

// ----- globals and definitions --------------------------

enum PlaceEnum {LIVINGROOM, BEDROOM, OFFICE, UNKNOWN};

struct bookStruct {
    string title="";
    string author="";
    int isbn=-1;
    int numPages = 0;
    //maybe add condition of book, price, rating, and more
    PlaceEnum location=UNKNOWN;
}; //bookStruct

vector<bookStruct> allMyBooks; //note: a vector of structs

string sayLocation(PlaceEnum location){
    switch (location) {
        case LIVINGROOM:
            return "LivingRoom";
            break;
        case BEDROOM:
            return "BedRoom";
            break;
        case OFFICE:
            return "Office";
            break;
        case UNKNOWN:
            return "WhoKnows?";
            break;
    }
}
// -----------------------------------

bookStruct makeABook(string title, string author,
                     int isbn=-1,PlaceEnum location=UNKNOWN) {
    bookStruct newBook;
    newBook.title = title;
    newBook.author = author;
    newBook.isbn = isbn;
    newBook.location = location;
    return newBook;
} //makeABook


void displayBook(bookStruct theBook) {
    show("\n");
    //show("Inside display book","-------------");
    show("Book Title: ",theBook.title);
    show("Book Author: ",theBook.author);
    show("Book ISBN: ",theBook.isbn);
    show("Book Location: ",sayLocation(theBook.location));
} //displayBook


void displayAllMyBooks() {
   cout << "\n----- All Books -----" << endl;
   for (auto oneBook : allMyBooks)
      displayBook(oneBook);
} // displayAllMyBooks


 int main() {
    bookStruct book1;
    book1.title = "Tom Sawyer";
    book1.author = "Mark Twain";
    book1.location = OFFICE;
    displayBook(book1);
    allMyBooks.push_back(book1); //keep all books in a vector

    displayAllMyBooks();
    system("pause"); //just to see what's going on so far

    bookStruct anotherBook;
    anotherBook = makeABook("Snow Crash","Neal Stephenson",1341827,BEDROOM);
    displayBook(anotherBook);

    allMyBooks.push_back(anotherBook);
    system("pause");

    show("book title = ",allMyBooks[1].title); //which book is this?
    show("book author = ",allMyBooks[1].author);
    system("pause");

    anotherBook = makeABook("William Gibson","Neuromancer",1003401,OFFICE);
    allMyBooks.push_back(anotherBook);

    anotherBook = makeABook("William Gibson","Mona Lisa Overdrive",1003403,OFFICE);
    allMyBooks.push_back(anotherBook);
    displayAllMyBooks();

    // Is the following code legit? and correct?
    bookStruct *bookPtr; //whoa! A pointer to a struct!
    bookPtr = new bookStruct;
    *bookPtr = makeABook("Mickey Mouse","Walt Disney");
    allMyBooks.push_back(*bookPtr);
    displayAllMyBooks();

    // maybe add some books from a file here

    // maybe add some books here from the user's input

    // sort the books by title, or by length, location, etc.

    // show the books sorted by number of same authors

    // maybe show which books are in which locations

    delete bookPtr;
    return 0;
} //main
