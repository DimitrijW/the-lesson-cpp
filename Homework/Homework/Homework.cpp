// Homework.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;

// #49
void ChangeVal(int* pa, int* pb)
{
    (*pa) = 5;
    (*pb) = 6;
}

int main()
{
    /* homework #49 */
    {
        int a = 6, b = 5;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;

        ChangeVal(&a, &b);
        cout << "function ChangeVal" << endl;

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
    
    
}

