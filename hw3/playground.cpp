#include <iostream>
//#include <math.h>
using namespace std;


int main(){

int nums[10];
for(int i = 0; i < 10; i++){
    nums[i] = (rand() % 100) + 1;
    cout << nums[i] << " ";
}
cout << endl;

    return 0;
}