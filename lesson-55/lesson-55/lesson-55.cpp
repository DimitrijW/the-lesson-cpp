// lesson-55.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	/* lesson #55 -> dynamic array */
	/*
	*   
	*		  ____________________________________________________________
				
				-----------------			---------------------
				|			x---|--------->	|	|	|	|	|	|
				|				|			|	|	|	|	|	|
				|				|			---------------------
				|				|	int type 4 byte -> 4 byte -> 4 byte -> 4 byte -> 4 byte
				-----------------
	*/
	{
		cout << endl << endl << " lesson #55 " << endl;
		int size = 0;					// bei 5 Bild engepasst
		cout << "enter array size" << endl;
		cin >> size;
		int* arr = new int[size];
										//  Wert	  Adresse
		for (int i = 0; i < size; i++)	// -842150451 00980578
		{								// -842150451 0098057C
			cout << arr[i] << "\t";		// -842150451 00980580
			cout << arr + i << endl;	// -842150451 00980584		arichmetika pointer
		}								// -842150451 00980588

		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;		// funcrion rand() zufelige Werte von 0 bis 10
		}

										//  Wert	  Adresse
		for (int i = 0; i < size; i++)	//	1		 00940578
		{								//	7		 0094057C
			cout << arr[i] << "\t";		//	4		 00940580	oder cout << *(arr + 1) << "\t";
			cout << arr + i << endl;	//	0		 00940584
		}								//	9		 00940588
		delete[] arr;
	}

	/* lesson #56 -> 2D dynamic array */
	/*
	*		____________memory_______________________________
	*			software								cols
	*			---------			----			-----------------    bei delete muss zuerst 
	*			|	   x|--------> |   x|--------->	|	|	|	|	|	die cols lösche dann rows sonst leak memory 
	*			|		|			----			-----------------
	*			|		|	   	r  |   x|--------->	|	|	|	|	|
	*			|		|		o	----			-----------------
	*			---------		w  |   x|--------->	|	|	|	|	|
	*							s	----			-----------------
	*							   |   x|--------->	|	|	|	|	|
	*								----			-----------------
	* 
	
	*/
	{
		cout << endl << endl << " lesson #56 " << endl;
		int rows;
		int cols;

		cout << "enter rows count" << endl;
		cin >> rows;
		cout << "enter columns count" << endl;
		cin >> cols;

		int** arr = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = rand() % 20;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

		for (int i = 0; i < rows; i++)		// so wird Komplett gelöscht bei 2D
		{
			delete[] arr[i];
		}
		delete[] arr;

	}

	/* lesson #57 -> kopie dynamic array*/
	/**/
	{
		cout << endl << endl << " lesson #57 " << endl;
	}
}