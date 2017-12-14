/* 
 * File: main.cpp
 * Author: Drake Gerger
 * Purpose: String Slection Sort
 * Created on December 7, 2017, 5:00 PM
 */

//System Libraries
#include <iostream>
#include <string>

using namespace std;
//User Libraries
//Global Constants

//Function Prototypes
void selectionSort(string [], int);
void showArray(string [], int);

//Execution Begins Here!
int main()
{
	const int SIZE = 20;
	
	string name[SIZE] = { "Collins, Bill", "Smith, Bart", "Michalski, Jacob",
                          "Griffin, Jim", "Sanchez, Manny", "Rubin, Sarah",
                          "Taylor, Tyrone", "Johnson, Jill", "Allison, Jeff",
                          "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
                          "Moretti, Bella", "Wu, Hong", "Patel, Renee",
                          "Harrison, Rose", "Smith, Cathy", "Conroy, Patrick",
                          "Kelly, Sean", "Holland, Beth" };

	cout << "   The unsorted string is:"<<endl;
	showArray(name, SIZE);
	selectionSort(name, SIZE);
	cout << "   The sorted string is:"<<endl;
	showArray(name, SIZE);
	
	return 0;
}

void selectionSort(string name[], int elems)
{
	int startScan, minIndex;
	string strName;
	for(startScan = 0; startScan < (elems - 1); startScan++)
	{
		minIndex = startScan;
		strName = name[startScan];
		for(int index = startScan + 1; index < elems; index++)
		{
			if(name[index] < strName)
			{
				strName = name[index];
				minIndex = index;
			}
		}
		name[minIndex] = name[startScan];
		name[startScan] = strName;
	}
}

void showArray(string name[], int elems)
{
	for(int count = 0; count < elems; count++)
		cout << count << ": " << name[count] << endl;
}






