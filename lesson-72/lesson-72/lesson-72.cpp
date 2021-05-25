// lesson-72.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
using namespace std;

class Human // ist Schablone welche beschreibt Variable z.B int a -> int class mit Ganzenzahlen
{
public:

    int age;
    int weight;
    string name;

    void Print()
    {
        cout << "Name " << name << "\tGewicht " << weight << "\tAlter " << age << endl;
    }


};

class Point
{
public:
    int x;
    int y;
    int z;
};
class Point75
{
public:
    int x;
    void Print()    // Methode Print() ist in public daher hat man Zugrief uberal und die Methode hat zugrief auf private  
    {
        cout << "y = " << y << "\nx = " << x << "\n" << "z = " << z << endl;
        PrintY();   // so kann Methode PrintY() aus privat in main() ausgeben durch pablic
    }
private:            // wenn die Methode Print() wird in private die hat Zugrief auf alle Felder und Metoden dieses classe
    int y;          // aber in main() hat kein Zugriff auf Print()
    int z;

    void PrintY()
    {
        cout << y << endl;
        cout << "PrintY() aus privat" << endl;
    }
};
class Point76
{
private:
    int x;
    int y;

public:
    int GetX()
    {
        return x;
    }
    void SetX(int valueX)
    {
        x = valueX;
    }

    int GetY()
    {
        return y;
    }
    void SetY(int valueY)
    {
        y = valueY * 2;
    }

    void Print()
    {
        cout << "x =  " << x << "\ty = " << y << endl << endl;
    }

};
class CoffeeGrinder
{
private:
    bool CheckVoltage()
    {
        return false;
    }

public:
    void Start()
    {
        bool voltageIsNormal = CheckVoltage();

        if (voltageIsNormal)
        {
            cout << "Coffee wird gemaehlt." << endl;
        }
        else
        {
            cout << "false Voltage" << endl;
        }
        
    }

};

int main()
{
    /* lesson #72 */
    /**/ 
    {

    }

    /* lesson #73 */
    /*
    *            y ^     
    *              |    / z
                   |   /     .Point
                   |  /  
                   | /
                   +-------------->
                                    x
    
    */
    {
        cout << endl << endl << " lesson #73 " << endl;

        //int a;              // 
        Human firstHuman;   // Human ist class -> firstHuman ist object 
        firstHuman.age = 30;
        firstHuman.name = "Issus";
        firstHuman.weight = 100;
        cout << firstHuman.age << endl;
        cout << firstHuman.name << endl;
        cout << firstHuman.weight << endl;

        Human secondHuman;  // neu objekt
        secondHuman.age = 19;
        secondHuman.name = "NOname";
        secondHuman.weight = 60;
        cout << "'''''''''''''''''''''''''" << endl;
        cout << secondHuman.age << endl;
        cout << secondHuman.name << endl;
        cout << secondHuman.weight << endl;

        Point a;
        a.x = 1;
        a.y = 3;
        a.z = 5;
    }

    /* lesson #74 */
    /**/
    {
        cout << endl << endl << " lesson #74 " << endl;

        Human firstHuman;   // Human (Typdaten) ist class -> firstHuman ist object 
        firstHuman.age = 30;
        firstHuman.name = "Issus";
        firstHuman.weight = 100;
        firstHuman.Print(); // Methode ist gleich Funktion in Klass

        Human secondHuman;
        secondHuman.Print();    // kommt irget was muss zuerst die Werte inizilisiren
    }

    /* lesson #75 -> public private protected*/
    /* 
    *           classe Point75          classe Point75          classe Point75  ->  keine Zugrief durch a. 
    *           {                       {                       {                   aber bei Vererbung hat Zugrief
    *               int x;              privat:                 protected:
    *               int y;       ->         int x;                  int x;
    *           };                          int y;                  int y;
    *                                   };                      };
    *          wie private hat kein Zugrief durch a. -> Zugrief kann nur classe oder frend classe und function
    */
    {
        cout << endl << endl << " lesson #75 " << endl;
        Point75 a;
        a.Print();
    }

    /* lesson 76 get and set */
    /**/
    {
        cout << endl << endl << " lesson #75 " << endl;
        Point76 a;
        a.Print();
        cout << "nacht a.SetX(5)" << endl;
        a.SetX(5);
        a.Print();

        int result = a.GetX();
        cout << "a.GetX " << result << endl;

        a.SetY(11);
        cout << "nach a.SetY(11)" << endl;
        a.Print();
    }

    /* lesson 77 get and set */
    /**/
    {
        cout << endl << endl << " lesson #77 " << endl;
        CoffeeGrinder a;
        a.Start();
    }

    return 0;
}
