#include <iostream>
#include <vector>
using namespace std;

void getNames(vector<string> &names)
{
    int i = 0;
    bool flag = true;
    string name;
    cout << "Enter names (enter ! to quit): " << endl;

    while (flag)
    {

        cin >> name;

        if (name == "!")
        {
            flag = false;
            break;
        }

        names.push_back(name);
    }
}

void getGrades(vector<double> &grades)
{
    int i = 0;
    bool flag = true;
    double grade;
    cout << "Enter grades (enter 00 to quit): " << endl;

    while (flag)
    {

        cin >> grade;

        if (grade == 00)
        {
            flag = false;
            break;
        }

        grades.push_back(grade);
    }
}

int main()
{

    vector<string> names;
    vector<double> grades;

   // getNames(names);
    getGrades(grades);

    for (int i = 0; i < grades.size(); i++)
    {
        cout << grades.at(i) << " ";
    }
}