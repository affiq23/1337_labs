#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include "Animal.cpp"
#include "Dog.cpp"
#include "Cat.cpp"


using namespace std;

int Dog::NoOfDogCounts = 0;
int Cat::NoOfCatCounts = 0;
int main()
{
   ifstream datafile;
   ofstream report;
   string line;
   string temp;
   string name;
   string atype;
   string age;
   string weight;
   string color;
   string sound;
   string health;
   string breed;

   vector<Animal *> animals;
   vector<Dog *> dogs;
   vector<Cat *> cats;

   datafile.open("animalFile.csv");
   if (!datafile)
   {
       cout << "Error in file readig" << endl;
       return 0;
   }
   getline(datafile, line); // skip header line
   getline(datafile, line); // Get the frist line from the file, if any.
   while (datafile) { // Continue if the line was sucessfully read.
       // Process the line.
       atype = line.substr(0, line.find(','));
       line = line.erase(0, line.find(',') + 1);
       name = line.substr(0, line.find(','));
       line = line.erase(0, line.find(',') + 1);
       age = line.substr(0, line.find(','));
       line = line.erase(0, line.find(',') + 1);
       weight = line.substr(0, line.find(','));
       line = line.erase(0, line.find(',') + 1);
       breed = line.substr(0, line.find(','));
       line = line.erase(0, line.find(',') + 1);
       color = line.substr(0, line.find(','));
       line = line.erase(0, line.find(',') + 1);
       health = line.substr(0, line.find(','));
       sound = line.erase(0, line.find(',') + 1);
       Animal * obj;
       if (atype == "cat")
       {
           obj = new Cat();
       }
       else if (atype == "dog")
       {
           obj = new Dog();
       }
       else
       {
           obj = new Animal();
       }
       obj->Age = age;
       obj->Breed = breed;
       obj->Color = color;
       obj->Health = health;
       obj->Name = name;
       obj->Sound = sound;
       obj->Type = atype;
       obj->Weight = weight;

       animals.push_back(obj);
       if (atype == "cat")
       {
           cats.push_back((Cat *)obj);
       }
       else if (atype == "dog")
       {
           dogs.push_back((Dog *)obj);
       }
       getline(datafile, line);
   }
   // print report
   report.open("report.txt");
   if (report)
   {
       cout << "Total Animals created:" << animals.size() << ", Total cats created:" << cats.size() << ",Total dogs created:" << dogs.size() << endl;
       report << "Total Animals created:" << animals.size() << ",Total cats created:" << cats.size() << ",Total dogs created:" << dogs.size() << endl;
       cout << "Animals" << endl;
       for (int i = 0; i < animals.size();i++)
       {
           cout << animals[i]->speak() << endl;
           report << animals[i]->speak() << endl;
       }
       cout << "Cats" << endl;
       for (int i = 0; i < cats.size();i++)
       {
           cout << "Name:" + cats[i]->Name + ",Age:" + cats[i]->Age + ",Weight:" + cats[i]->Weight + ",Breed:" +
               cats[i]->Breed + ",Color:" + cats[i]->Color + ",Health:" + cats[i]->Health + ",Sound:" + cats[i]->Sound << endl;
           report << "Name:" + cats[i]->Name + ",Age:" + cats[i]->Age + ",Weight:" + cats[i]->Weight + ",Breed:" + cats[i]->Breed
               + ",Color:" + cats[i]->Color + ",Health:" + cats[i]->Health + ",Sound:" + cats[i]->Sound << endl;
          
       }
       cout << "Dogs" << endl;
       for (int i = 0; i < dogs.size();i++)
       {
           cout << "Name:" + dogs[i]->Name + ",Age:" + dogs[i]->Age + ",Weight:" + dogs[i]->Weight + ",Breed:" +
               dogs[i]->Breed + ",Color:" + dogs[i]->Color + ",Health:" + dogs[i]->Health + ",Sound:" + dogs[i]->Sound << endl;
           report << "Name:" + dogs[i]->Name + ",Age:" + dogs[i]->Age + ",Weight:" + dogs[i]->Weight + ",Breed:" + dogs[i]->Breed
               + ",Color:" + dogs[i]->Color + ",Health:" + dogs[i]->Health + ",Sound:" + dogs[i]->Sound << endl;
       }
       report.close();
   }

   datafile.close();
   return 0;
}

    