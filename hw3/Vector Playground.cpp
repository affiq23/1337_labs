// VectorPlayground
// Doug DeGroot
// 1-25-19
//
// This example code has been written for you to play around with vectors.
// Below are the various methods you can use with vectors.
// You might want to play around with them and watch what happens to the vector.
// In particular, watch what happens with the vector's capacity as
// you add elements to and delete elements from the vector.
//
// See http://www.cplusplus.com/reference/vector/vector/ for details on the vector container.
// You need to read the Pearson lecture notes for Chapter 7, Vectors.
// You should also read Chapter 17 on the STL (Standard Template Library).
//
// The Vector Container Declaration Format - vector<dataType> nameOfVector
//
// myVector.at(index) -  return the element at the specified index number
// myVector.back() - access the last element
// myVector.begin() - ITERATOR or reads vector from the first element (index 0)
// myVector.clear()
// myVector.data()
// myVector.empty() - tests the vector to see if it is empty or not
// myVector.emplace(element,position) - insert specified element at specified position
// myVector.erase()
// myVector.front() - access the first element
// myVector.insert()
// myVector.insert(my.Vector.begin() + integer, new value) - adds element BEFORE specified index number
// myVector.pop_back() - deletes the last element in the vector
// myVector.pushback(value) - adds an element to the END of the vector (and may resize it)
// myVector.reserve() - request a change in capacity
// myVector.resize()
// myVector.shrink_to_fit() - shrink to fit the current size
// myVector.size() - returns an *unsigned int* equl to the number of elements
// myVector.swap() - swap the values in one vector with those in another vector of the same size
// and more -- See Chapters 7 and 17
//
// changelog:
// 6/18/20 - added a few more comments; improved the formatting a bit
//
// Suggestions:
//    blah blah blah
//


#include <iostream>
#include <vector>

using namespace std;


// ----- Globals -----
vector <int> v;

// ----- Debugging and Output Stuff -----

void show(string msg, int num) {
   cout << msg << " " << num << endl;
} //show


void showVector(string msg="") {
    //show the vector contents and some of its properties
   if (msg != "") cout << msg << endl;

   cout << "Vector contents are: ";
   for (auto val : v)
      cout << val << " ";
   cout << endl;

   show("vector size = ",v.size());
   show("vectorCapacity = ",v.capacity());
   cout << endl;
} //showVector


int main() {

   showVector("--- at the very beginning:");

   v.push_back(1);
   showVector("after adding 1 number");

   v.push_back(2);
   showVector("after adding a second number");

   v.push_back(3);
   showVector("after adding a third number");

   v.push_back(4);
   showVector("4 elements");

   cout << "testing next line" << endl;
   cout << v[3] << endl;

   v.push_back(81);
   showVector("There should be 5 elements in the vector at this point.");

   cout << "testing next line" << endl;
   cout << v[4];
   v.push_back(82);
   showVector("There should be 6 elements in the vector at this point.");

   v.push_back(83);
   v.push_back(84);
   v.push_back(85);
   v.push_back(86);
   showVector("There should be 10 elements in the vector at this point.");

   //v.emplace(v.begin()+2,4); //see Chapter 17 for a discussion of emplace
   //v.emplace(v.begin(),44);
  // showVector("4 and 44 should be near the first two items now.");


   v.insert(v.begin()+1,999); showVector("999 should now be second item in the vector.");
   v.insert(v.end()-4,1); showVector("1 should now be the fourth to last in the vector.");
   v.resize(32,-2); showVector("What is the capacity now? Did anything else change?");
   v.push_back(18); showVector("What about now?");
   v.resize(10); showVector("Resized the vector to 10. What happened to the extra items?");
   v.shrink_to_fit(); showVector("We just called 'shrink_to_fit'. What changed?");

   // Let's delete the last two vector elements.
   v.pop_back();
   v.pop_back();
   showVector("We just deleted the last two items.");

   //Let's erase the first element.
   v.erase(v.begin());
   showVector("The first item should now be gone. Is it?");

   // Let's erase all but the last two items.
   v.erase(v.begin(),v.end()-2);
   showVector("There should be only 2 items in the vector now.");

   //Now let's clear the entire vector.
   v.clear();
   showVector("Is the vector now totally cleared?");

	// Let's add some more values to the vector.
		// <-- do that here

   // And now, play around with some of the other methods.

   return 0;
} //main
