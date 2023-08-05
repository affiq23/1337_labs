// AddressStructs
// DeGroot
// 1july20
// Notes:
//	This program is only a demo program to show how structs
// 	can be used and embedded within other structs. You
//	might want to improve this program to gain practice
//	with using structs.
//	There could easily be bugs in this program.
//
#include <iostream>
#include <string>
using namespace std;


//----- houseType -----//
struct houseType {
	int bedrooms;
	int baths;
	bool garage;
};

//----- Address -----//
struct Address {
	int houseNumber = 0;
	string streetName="unknown street";
	string city="?", state="?";
	int zip=-1;
	houseType htype;
	void setAddress(int ahouseNumber, string astreetName, string acity) {
		houseNumber = ahouseNumber;
		streetName = astreetName;
		city = acity;
	}
	void printMe() {
		cout << houseNumber << streetName << endl;
		cout << city << ' ' << state << ' ' << zip << endl;
	}
};

//----- Person -----//
struct Person {
	string title;
	string firstName;
	string lastName;
	string mods;
	Address address;

	void setName(string atitle,string afirstName,string alastName,string amods="") {
		title=atitle;
		firstName=afirstName;
		lastName=alastName;
		mods=amods;
	}
	void setAddress(int houseNumber, string streetName, string city) {
		address.setAddress(houseNumber,streetName,city);
	}
	void printMe() {
		cout << endl << title << firstName << lastName << mods << endl;
		address.printMe();
	}
};

//-----main-----//
int main() {
	Person jack;
	jack.title = "Mr.";
	jack.firstName = "Jackson";
	jack.lastName = "Brown";

	jack.address.houseNumber = 123;
	jack.address.streetName = "Main";
	jack.printMe();

	Person jill;
	jill.setName("Ms.","Jill","White");
	jill.setAddress(456,"Elm St.","Dallas");
	jill.printMe();

	Person* mary = new Person;
//	*(mary.title) - "Prof."; //what's wrong here??
	(*mary).title = "Mr.";
	mary->title = "Dr."; //note the -> operator; compare to above
	mary->firstName = "Mary";
	mary->lastName = "Smith";
	mary->printMe();

}//main

