// Cats-and-Animals-2 - demonstrate elements of C++ classes
// DeGroot
// April 19, 2021

//  NOTE: THIS CODE IS REAALLY BAD. DO NOT USE IT, JUST LEARN FROM IT.
//
// This program demonstrates both inheritance and polymorphism.
// There are some problems with the code that you can try to solve.
//		1. some inefficient code, some poorly structured code
//		2. some redundant code, some poor class division
//		3. some comments you can try turning off and on to see what happens
//		4. some animal/cat counting errors
//		5. and maybe more
//	Play around with this code to both fix/improve it as well as
//		enhance it.
//
#include <iostream>
#include <string>
#include <cat.h>
#include <animal.h>
using namespace std;

//------------------------------//

//----- init any static class members here
// int Cat::nbrOfCats = 0;
// int Cat::GetNumberOfCats() {
//  return Cat::nbrOfCats;
//};
int Animal::AnimalNumber = 0;

//----- create the class de/constructors here
//
Cat::Cat()
{
  cout << "\nI am creating an unnamed cat." << endl;
  name = "Unnamed";
  age = 0;
  //  nbrOfCats++; //note that this is/isn't a global variable - which?
  //  myCatNbr = nbrOfCats;
  SetCatNumber();
  animalType = "cat";
}

Cat::Cat(string catsName, int catsAge)
{
  cout << "\nI am creating a cat called " << catsName << endl;
  Cat::name = catsName; // notice this; why not the same below
  age = catsAge;
  SetCatNumber();
  animalType = "cat";
}

Cat::~Cat()
{
  cout << "Destructing cat number" << GetCatNbr()
       << ", named " << GetCatsName() << endl;
}

//----- define the class accessors (getters) here

int Cat::GetCatsAge() const { return age; }

string Cat::GetCatsName() const { return name; }

//----- define some class setters (mutators) here
//
void Cat::SetCatName(string catName)
{
  name = catName;
}

void Cat::SetCatNumber()
{
  nbrOfCats++; // note that this is a global variable
  myCatNbr = nbrOfCats;
}

void Cat::Introduction() const
{
  Speak();
  cout << "My name is " << name << endl;
  cout << "I am " << age << " years old." << endl;
  cout << "I am cat number " << myCatNbr << endl;
  cout << "  and I an animal number " << myAnimalNumber << endl;
  cout << "I am a(an) " << animalType << endl;
}

int main()
{
  Animal chipmunk; // just a plain ol' animal, nothing more
  chipmunk.name = "Chippy";
  chipmunk.Speak();
  cout << "I am a(an) " << chipmunk.animalType << endl;

  Cat catA("Frisky", 3);
  cout << "Cat's name: " << catA.GetCatsName() << endl;
  catA.Introduction();

  catA.SetCatName("Boo"); // we're renaming Frisky to Boo; good idea?
  catA.Introduction();

  Cat *catB; // let's create a dynamic cat
  catB = new Cat("Buster", 1);
  catB->Introduction();

  Cat catC; // let's create an "unknown" cat
  catC.Introduction();

  Cat catD("Morris", 9);
  catD.Introduction();

  Animal animalArray[10]; // note: can hold animals and Cats
  animalArray[0] = chipmunk;
  animalArray[1] = catA;
  animalArray[0].Speak(); // this calls on Chippy to speak

  Cat catE("Big Boy", 4);
  catE.Introduction();

  // --- report the number of cats we processed today before quitting.
  //  cout << "\nNumber of cats processed today: " <<
  //    Cat::GetNumberOfCats() << endl << endl;

  delete catB; // where do the others get deleted?

  return 0;
} // main
