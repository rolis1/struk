#include <iostream>
using namespace std;

const int maks = 3;
int top_A = 0, top_B = 0, top_C = 0;
int place_A[maks], place_B[maks], place_C[maks];

// push function
void pushValue(int place[], int &top, int value)
{
    if (top >= maks)
    {
        cout << "Town is full" << endl;
    }
    else
    {
        place[top] = value;
        top++;
    }
}

// pop function
void popValue(int place[], int &top)
{
    if (top <= 0)
    {
        cout << "Town is empty" << endl;
    }
    else
    {
        top--;
        place[top] = 0;
    }
}

// display function
void displayValues(const string &placeName, const int place[], int top)
{
    cout << "Nilai di " << placeName << ": ";
    if (top == 0)
    {
        cout << "Town is empty" << endl;
    }
    else
    {
        for (int i = 0; i < top; ++i)
        {
            cout << place[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    pushValue(place_A, top_A, 10);
    pushValue(place_A, top_A, 30);
    pushValue(place_A, top_A, 50);

    displayValues("Town A", place_A, top_A);
    displayValues("Town B", place_B, top_B);
    displayValues("Town C", place_C, top_C);

    // A ke B
    if (top_A > 0)
    {
        pushValue(place_B, top_B, place_A[top_A - 1]);
        popValue(place_A, top_A);
    }

    // C ke B
    if (top_C > 0)
    {
        pushValue(place_B, top_B, place_C[top_C - 1]);
        popValue(place_C, top_C);
    }

    // C ke A
    if (top_C > 0)
    {
        pushValue(place_A, top_A, place_C[top_C - 1]);
        popValue(place_C, top_C);
    }

    cout << "\nSetelah pemindahan:" << endl;
    displayValues("Town A", place_A, top_A);
    displayValues("town B", place_B, top_B);
    displayValues("Town C", place_C, top_C);

    cout << "Program berakhir." << endl;
    cout << "Program ini dibuat oleh: Rolis Liu" << endl;
    cout << "NPM: 2310631170117" << endl;
    return 0;
}
