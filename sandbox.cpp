/*
    Where I test new concepts or do some extra practice
*/

#include <iostream>
using namespace std;

void messingWith2DArray(bool ifTrue)
{
    if (ifTrue)
    {
        const int ROWS = 2;
        const int COLS = 3;
        int total = 0;
        int arr[ROWS][COLS] = {{2, 3, 4}, {6, 7, 8}};

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                total += arr[i][j];
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        cout << "Total: " << total << ".\n";
    }
}

void summingRows(bool ifTrue)
{
    if (ifTrue)
    {
        const int NUM_STUDENTS = 3;
        const int NUM_SCORES = 5;
        double total;
        double average;
        int counter = 1;

        double scores[NUM_STUDENTS][NUM_SCORES] = {{88, 97, 79, 86, 94},
                                                   {86, 91, 78, 79, 84},
                                                   {82, 73, 77, 82, 89}};

        for (int i = 0; i < NUM_STUDENTS; i++)
        {
            total = 0;
            average = 0;
            for (int j = 0; j < NUM_SCORES; j++)
            {
                total += scores[i][j];
            }
            average = total / NUM_SCORES;
            cout << "Student " << counter << " average score: " << average << endl;
            counter++;
        }
    }
}

int main()
{

    messingWith2DArray(false);
    summingRows(true);

    return 0;
}