/* 
 * File: main.cpp
 * Author: Drake Gerger
 * Purpose: Rainfall Statistics Modification
 * Created on December 7, 2017, 4:10 PM
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Data
{
    string Name[12];
	double Amt;
};

// Function prototypes
void getData(Data[], int);
void displayReport(Data[], int);
void selectionSort(Data[], int);

int main()
{
	const int mths = 12;
	Data rainfall[mths];

	getData(rainfall, mths);
	selectionSort(rainfall, mths);
	displayReport(rainfall, mths);

	return 0;
}

void getData(Data rainfall[], int mths)
{
	double rain;

	cout<<"Enter the Total Rainfall for ";
	for (int i = 0;i<mths;i++)
	{
		do
		{
			cout<<"Month #"<<(i + 1)<<": ";
			cin >> rain;

			if (rain < 0)
				cout << "Error! Rainfall amounts must be larger than 0!"<<endl;

		} while(rain < 0);
		
		rainfall[i].Amt = rain;
	}	 
}

void selectionSort(Data array[], int size)
{
	Data temp;
	bool swap;

	do
	{	swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count].Amt < array[count + 1].Amt)
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

/*******************************************************************
 *                          displayReport                          *
 * This six parameter function accepts two double, two integer and *
 * a arrays start address and size arguments. Displays a summary   *
 * rainfall report.                                                * 
 *******************************************************************/
void displayReport(Data R[], int S)
{
	cout << "2017 Rain Report from RCC";
	cout << "        sorted in order of rainfall,"
		 << "           from highest to lowest."<<endl;
	cout << "        Month             Rainfall Amounts"<<endl;
	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < S; i++)
	{
		cout << "        " << left << setw(9) << R[i].Name << "              "
			 << R[i].Amt << endl;
	}

}