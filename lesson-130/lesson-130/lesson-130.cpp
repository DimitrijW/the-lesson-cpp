// lesson-130.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;

void Foo1(int c)
{
    c++;
}
void Foo2(int *pc)  // die Funktion type void übergiebt keine Parameter in main aber wirch pointer hat man die Möglichkeit.  
{
    //pc++;     verschiebt sich und gibt adress von next Element
    (*pc)++;  //  wird die Variable + 1 -> 1. wird die Zahl bekannt (*pc) und dann 2. + 1 -> ist keine Kopie von c ist Original c
}
void Foo3(int *pd, int *pe, int *pf)
{
    (*pd) = 555;
    (*pe)++;
    (*pf) = -20;

}
void Foo4(int h)
{
    h = 4;
}
void Foo5(int& h)   // die Funktion übernimmt Wert durch Referenc
{                   // arbeitet direct mit Daten
    h = 5;
}
void Foo6(int* h)   // die Funktion übernimmt Wert durch Poiner
{                   //  muss *h
    *h = 6;
}
void Foo7(int& k, int& l, int& m)
{
    k = 10;
    l *= 2;
    m -= 100;
}

int main()
{
    /*lesson #45 statische und dynamische speicher*/
    /*lessen #46 pointer*/
    cout << endl << endl << "lesson #46" << endl;
    {
        int a = 5;
        cout << a << endl;  // 5
        int b = a;  // b = 5 
        int* pa = &a;   // px zeigt auf adress wo liegt a "pointer type int, * variable type pointer, & operator adress"

        //double* px = &a; type pointer muss gleichen type sein auf die Daten er zeigt
        cout << pa << endl; // 00AFF754 16bit adresse wo liegt a. Die Adresse wird immer verschieden sein
        cout << *pa << endl;    // 5 
        int* pa2 = &a;
        cout << *pa2 << endl;   // adressen von liegt a werden gleich sein
        *pa2 = 2;
        cout << a << endl;  // 2
        cout << *pa << endl;    // 2
        // Die Variable a kann über a und durch adresse *pa und *pa2

        /*lesson #47 pointer und array*/
        cout << endl << endl << "lesson #47" << endl;
        const int SIZE = 5;
        int arr[SIZE]{ 4, 55, 79, 1, 4 };   // name array - arr - ist pointer auf erste element
        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << endl;
        }
        cout << "==================================" << endl;
        //int* pArr = arr;
        //cout << "arr\t" << arr << endl;   gleiche ardesse 00AFF86C
        //cout << "pArr\t" << pArr << endl; gleiche adresse 00AFF86C
        cout << "==================================" << endl;
        int* pArr = arr; // ist gleich wie int arr[SIZE]{ 4, 55, 79, 1, 4 };
        for (int i = 0; i < SIZE; i++)
        {
            cout << pArr[i] << endl;
        }

        for (int i = 0; i < SIZE; i++)
        {
            cout << *(pArr + i) << endl;
        }

        cout << *arr << endl;   // 4 erste Element in array wenn wir zum array + int dann verschieben wir in 4 bit in next 
        cout << *(arr + 1) << endl; // 55  wenn wir zum array + int Datentyp(wie type array) dann verschieben wir in 4 bit zum next Element
        cout << *(arr + 2) << endl; // 79 ___ das gleich wie for Schleife line 30

        for (int i = 0; i < SIZE; i++)
        {
            cout << (arr + i) << endl;  // so kriegen wir die Adressen wo die Werte liegen
        }                               // 0019FE28, 0019FE2C, 0019FE30, 0019FE34, 0019FE38 die gehen 4 bit weil unsere array type int = 4 bit

        for (int i = 0; i < SIZE; i++)
        {
            cout << *(arr + i) << endl;  // so kriegen wir die Werte welche in array liegen
        }                                // 4, 55, 79, 1, 4
    }
    /*lesson #48 Übergabe Parameter üner pointer in die Funktion*/
    cout << endl << endl << "lesson #48" << endl;
    {
        int c = 0;

        cout << c << endl;  // 0
        Foo1(c); // c gilt nur in Funktion
        cout << c << endl;  // 0

        cout << c << endl;  // 0
        Foo2(&c);   // &c adresse the variable c
        cout << c << endl;  // 1

        /*lesson #49 Übergabe mehreren Parametern üner pointer in die Funktion*/
        cout << endl << endl << "lesson #48" << endl;

        int d = 0, e = 0, f = 1;
        cout << "d = " << d << endl;    // 0
        cout << "e = " << e << endl;    // 0
        cout << "f = " << f << endl;    // 1

        cout << "function Foo" << endl;
        Foo3(&d, &e, &f);   // the adresses variabes d, e, f

        cout << "d = " << d << endl;
        cout << "e = " << e << endl;
        cout << "f = " << f << endl;
    }
    /*lesson #50 referenc*/
    /*      
    *       *pd<----------------|0x0010c|   *&dRef<----------------|0x0010c|
    *                           | d = 5 |                          | d = 5 |
    *       -> durch Referenc wir arbeitet direct mit den Zahlen
    *       -> Referenc kann keine NULL, 0, nullptr type Daten sein 
     */
    cout << endl << endl << "lesson #50" << endl;
    {
        int d = 5;
        int* pd = &d;   // & -> Adress von Variable
        cout << "pd\t" << pd << endl;  // 012FFBE0 Adress
        cout << "*pd\t" << *pd << endl; // 5 
        int& dRef = d;   // Referenc Adress von variable ->  referenc  muss initilisiert sein
        cout << "&dRef\t" << dRef << endl;  // 5 die Referenc arbeiten gleich mit dem Zahl

        cout << "pd\t" << pd << endl;   // 00AFF964
        pd++;   // pointer type int wird verschoben nach 4 bit 
        cout << "pd\t" << pd << endl;   // 00AFF968
        pd = pd + 2; 
        cout << "pd\t" << pd << endl;   // die Adresse wird weiter nach 8 bit verschoben

        cout << "&dRef\t" << dRef << endl;  // 5
        dRef++;   // zum 5 wird + 1  
        cout << "&dRaf\t" << dRef << endl;  // 6
        dRef = dRef + 2;    // 6 + 2
        cout << "&dRaf\t" << dRef << endl;  // 8

        cout << "d\t" << d << endl; // 5
        cout << "&dRaf\t" << dRef << endl;  // 5
        dRef = 55;
        cout << "d\t" << d << endl;  // 55
        cout << "&dRaf\t" << dRef << endl;  //55

        int* ppd = &dRef; // *ppd zeigt auf Adresse von dRef -> dRef zeigt auf Adresse von d
        cout << "d\t" << d << endl; // 55
        *ppd = 12;
        cout << "d\t" << d << endl; // 12
        // bei Referenc zum Object dann kann sehr CPU von PC sparen weil in Object mehre Variablen und wir übergen nur die Adresse 4 bit
    }
    /*lesson #51 referenc übergabe in die Funktion*/
   /*
   *            |value = 10|                                        |value = 10|-->--                           |value = 10|--<-----|
   *            |  0x0110F |<----                                   |  0x0110F |     |  nur Kopie wird          |  0x0110F |-->|    |  
   *                    ^        |                                                   |  übergeben                              |    |
   *            Foo5(int &h)     ^                                  Foo4(int h)      |                          Foo6(int *h)<--|    |
   *            {                |                                  {                |                          {                   |
   *                h = 5;-->-----   hier Veranderungen                 h = 4;--<-----  wird nur local             *h = 6;-->-------|  
   *            }                    werden value auf 2 enderen     }                   ausgeführt              }                            
    */
    cout << endl << endl << "lesson #51" << endl;
    {
        int value = 10;
        cout << "value\t" << value << endl; // 10

        cout << "Foo4" << endl;
        Foo4(value);
        cout << "value\t" << value << endl; // 10

        cout << "Foo5" << endl;
        Foo5(value);
        cout << "value\t" << value << endl; // 5


        cout << "Foo6" << endl; 
        Foo6(&value);
        cout << "value\t" << value << endl; // 6
    }

    /*lesson #52 referenc übergabe aus Funktion*/
    {
        /*
        *
         */
        cout << endl << endl << "lesson #52" << endl;
        int k = 0, l = 4, m = 34;
        cout << "k = " << k << endl;
        cout << "l = " << l << endl;
        cout << "m = " << m << endl;

        cout << "Foo7" << endl;
        Foo7(k, l, m);

        cout << "k = " << k << endl;
        cout << "l = " << l << endl;
        cout << "m = " << m << endl;
    }



    /*lesson #53 dynamic flash, Operatoren new and delete*/
    /*      ------------
            | software |
            |  flash   |
            |          |       mit new operator wird platz dynamic flash reserviert
            |     -----|----->|10|   mit delete wird den reservirte Speicherplatz gelöscht
            ------------       
     */
    {
        cout << endl << endl << "lesson #53" << endl;

        int* pg = new int;  // wir reserwieren dynamische speicher type int -> operator new markiert dynamische speicher
        cout << pg << endl; // 011D6518 Adresse auser unsere Programm
        cout << *pg << endl;    // -842150451 zufäliche Zahl in Speicher
        *pg = 10;   // auf markirte Speicher wird Zahl 10 geschrieben
        cout << *pg << endl;    // 10

        delete pg;  // löscht den markirten Speicher also muss immer gemacht werden nach dem new, sonst irgent wann gibt keine Speicherplatz mehr
                    // wir habe die Werte gelöscht ober poiner zeigt immer noch auf die Speicher, jetz kann andere Programm in dieses Adresse reinschreiben

    }


    /*lesson #130 pointer*/
    //int* ptr = new int(5);
}

