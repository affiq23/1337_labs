#include <iostream>
#include <string>
using namespace std;

//--- Animal Class ---------------------------//
class Animal {
private:
  static int AnimalNumber;
public:
  string name;
  void Speak() { //default speak function, so no specific sound
    cout << name << " says: (slight breathing sound)" << endl;
  }
  Animal();
//  ~Animal() {cout << "One less animal: " << name << endl;}
  string animalType = "animal";
  int myAnimalNumber;
};

Animal::Animal() {
  cout << "\nCreating a new animal." << endl;
  AnimalNumber++;
  myAnimalNumber = AnimalNumber;
}