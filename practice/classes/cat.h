#include <iostream>
#include <string>
#include <animal.h>
using namespace std;
//--- Cat Class ---------------------------//
class Cat : public Animal {
private:
  //static int nbrOfCats; //note that this is a static variable
  int nbrOfCats;
  int myCatNbr;
  int age;
  string name;
  void Speak()const {cout << "\nMeow." << endl;}

public:
  Cat(string name, int age);
  Cat();
  ~Cat();
  int GetCatsAge() const; //notice all the const declarations! WHY?
  string GetCatsName() const;
  int GetCatNbr() {return myCatNbr;}
  void Introduction() const;
  void SetCatAge();
  void SetCatName(string name);
  void SetCatNumber();
  static int GetNumberOfCats();
}; // Cat
