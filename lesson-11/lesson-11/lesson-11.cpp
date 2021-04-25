/*
* lesson von 11 bis 20
* Datum 25.04.2021
*/

#include <iostream>
using namespace std;

/*
*   1. Operatoren vergleichen                       Operatoren geben zurück nur bool true oder false
*   < - weniger
*   > - größer
*   <= - weniger oder gleich
*   >= ´- größer oder gleich
* 
*   2. Operatoren gelich
*   == - ist gleich              -> = gehört
*   != - ungleich
* 
*   3. logic operatoren und negative inversia
*   && - und
*   || - oder
*   != - nein
*
*/

int main()
{
    cout << (4 > 5) << endl;                // false -> 0
    cout << (4 < 5) << endl;                // true -> 1
    cout << (5 <= 5) << endl;               // true -> 1
    cout << (5 < 5) << endl;                // false -> 0
    cout << (4 >= 5) << endl;               // false -> 0

    cout << (4 == 5) << endl;               // false -> 0
    cout << (5 == 5) << endl;               // true -> 1
    cout << (5 != 5) << endl;               // false -> 0
    cout << (4 != 5) << endl;               // true -> 1

    cout << !(5 == 5) << endl;              // false -> 0
    cout << ((5 == 5) && (5 > 4)) << endl;  // true -> 1
    cout << ((5 == 5) && (5 < 4)) << endl;  // false -> 0
    cout << ((5 == 5) || (1 > 0)) << endl;  // true -> 1
    cout << ((5 == 4) && (5 > 4)) << endl;  // false -> 0

    /*
    * if - else if
    */
    bool isRain = false;
    if (isRain)
    {
        cout << "es regnet wir brauchen Regenschierm" << endl;
    }
    else
    {
        cout << "es gibt kein Regen braucht man kein Regenschierm" << endl;
    }

    int a;
    cout << "Gebensie die Wert" << endl;
    cin >> a;
    if (a > 5)
    {
        cout << a << " > 5" << endl;
    }
    else if (a == 5)
    {
        cout << a << " = 5" << endl;
    }
    else
    {
        cout << a << " < 5" << endl;
    }

    /*
    * switch()          wenn viele dann switch bei weniger if else
    */
    switch (a)
    {
    case 1:
        cout << "Sie haben 1 eingegeben" << endl;
        break;  // ohne break wird Programm nicht angeahatlen und geht in die case 2
    case 2:
        cout << "Sie haben 2 eingegeben" << endl;
        break;
    default:                // defaut ist nicht Pflicht aber macht was nicht in case ist. Ohne wird Programm nicht ausgefurt wenn es in case nicht findet
        cout << "Sie haben sonstige Zahl eingegeben" << endl;
        break;
    }

    /*
    *               while
    */
    int n = 0;
    while (n < 10)    // wird wiederchol bis es false wird dan bricht ab also geht in die schleife wenn true
    {
        cout << "Nummer ist = " << n << endl;
        n++;
    }
    cout << "Text auf dem Display" << endl;

    int m = 18;
    do
    {
        cout << " Nummer ist = " << m << endl;
        m++;
    } while (m < 20);   // wird ausgefurt wenn true

    /*
    *               for
    */
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        cout << "for Schleife 1 Zahl ist = " << i << endl;
    }

    for (; i < 20; i++) // hier ist schon i = 10
    {
        cout << "for Schleife 2 Zahl ist = " << i << endl;
    }

    for (i = 0; i < 10; )
    {
        cout << "Zahl ist = " << i << endl;
        i++;            // kann z.B weiter verwenden in if else 
    }

    for (int k = 0, l = 10; k < 10 && l != 5; k++, l--)
    {
        cout << "Zahl k ist = " << k << endl;
        cout << "Zahl l ist = " << l << endl;
    }

    /*
    for (; ; )
    {
        cout << "unendliche Schleife " << endl;
    }
    */

    /*
    *               break
    */
    for (i = 0; ; i++)      // ist immer true wird immer durchgefuhrt
    {
        cout << "Variable i ist = " << i << endl;
        if (i == 5)
        {
            break;      // ende
        }
    }
    cout << "ende" << endl;

    int r = 0;
    while (true)
    {
        cout << "Varialbe r = " << r << endl;
        r++;
        if (r == 6)
        {
            break;
        }
    }

    /*
    *       continue
    */
    cout << endl << "tutorium continue" << endl << endl;
    for (i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            continue;   // wird bei i = 5 nicht ausgefuhrt also wird nicht ausgefürt was danach kommt in Schleife
        }
        cout << "variabl i = " << i << endl;
    }
}
