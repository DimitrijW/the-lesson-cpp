//  lesson von 0 bis 10.    Datum: 24.04.2021


#include <iostream> // Vor der kopieliren
#include <math.h> // Mathe

using namespace std; // wenn zwei Programirer die funktion gleich genat haben konn unterschiden werden

int main()
{
    std::cout << "Привет!\n";
    setlocale(LC_ALL, "Rus");
    std::cout << "Привет!\n";

    /*
        \b
        \n
        \t
        ---------------------------------
        \\
        \"
        \'
     */
    cout << "1. Hallo\n";
    cout << "2. \tHallo\t\t\t\t" << "Abstand" << endl;
    cout << "3. \"Hallo\"\t\\" << endl;

    // mit komma Zahl
    float x1 = 122.56;      // float 4 bit,
    double x2 = 3435.65;    // double 8 bit,

    // ohne komma Zahl
    int x3 = 2147483647;    // int 4 bit, +/- 2147483647
    short x4 = 32767;       // short 2 bit, +/- 32767
    long x5 = 2147483647;   // long 4 bit, +/- 2147483647

    //Simbol
    char x6 = '$';          // char 1 bit, !"§$%&/()=?QWERTqwwrr

    // Logic true || false
    bool x7 = false;             // bool 1 bit, true false 1 0

    cout << "bool false ist = " << x7 << endl;
    x7 = true;
    cout << "bool true ist = " << x7 << endl << endl;

    // Constanten sind festen Werten die nicht uberschreiben werden auch von kompaler
    const int COUNT_DAY_IN_WEEK = 7;       // const werden immer Groß geschrieben
    //COUNT_DAY_IN_WEEK = 5;               // ist fehler Meldung
    const char NEW_LINE = '\n';             
    cout << COUNT_DAY_IN_WEEK << NEW_LINE << "\n";

    // unarnie operatoren nur ein Zeichen z.B -(-5) verandert die +/-
    int a1 = -5;
    cout << a1 << endl;
    a1 = -a1;
    cout << a1 << endl;
    // binar operatoren zwischen 5 + 6
    int a = 5, b = 2, c;
    c = a + b;
    cout << a + b << endl;
    cout << c << endl << endl;
    // trnere operatoren ???

    // inkrement a++ und dekrimenta--
    int q1 = 1, q2 = 1;
    cout << "cout q1   -> " << q1 << endl;      // q1 = 1
    cout << "cout q1++ -> " << q1++ << endl;    // q1 = 1 Prioritet weniger als bei andern
    cout << "cout ++q2 -> " << ++q2 << endl;    // q2 = 2 z.B a = 1 -> b = ++a * a = 4
     //
    /*
    * a = a + 20;   
    * a += 20;          a -= a;, a *= a;, a /= 20; besser so verwenden 
    */

}
