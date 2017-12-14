/* 
 * File:   main.cpp
 * Author: Drake Gerger
 * Created on December 7th, 2017, 8:00 PM
 * Purpose:  Menu with functions
 */

//System Libraries
#include <iostream> //Input/Output Stream Library
#include <string> //Memory Thread
#include <iomanip>

using namespace std;    //Standard Name-space under which System Libraries reside

//User Libraries
struct Data
{
    string Name[12];
	float Amt;
};

//Global Constants - Not variables only Math/Science/Conversion constants
const int NUM_ELEMENTS=18;
bool srchAray(int, int [NUM_ELEMENTS]);
const int NUM_ELEMENT=10;
bool srchArray(int, int [NUM_ELEMENT]);

//Function Prototypes
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void menu();
void selectSort (int arr[NUM_ELEMENTS]);
bool binarySrch (int, int arr[NUM_ELEMENTS]);
void selctSort (int arr[NUM_ELEMENT]);
bool binSrch (int, int arr[NUM_ELEMENT]);
void getData(Data[], int);
void displayReport(Data[], int);
void selectionSort(Data[], int);
void selectionSort(string [], int);
void showArray(string [], int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int choice;
    //Loop the Menu and Problems
    do{
        //Input Data/Variables
        menu();
        cin>>choice;
        //Process or map the inputs to the outputs
        switch(choice){
            case 1:prob1();break;
            case 2:prob2();break;
            case 3:prob3();break;
            case 4:prob4();break;
            case 5:prob5();break;
            case 6:prob6();break;
            default:{
                cout<<"Exiting, have a great day!"<<endl;
            }
        }
    }while(choice>0&&choice<6);
    //Exit the program
    return 0;
}

void prob1(){
//Declare Variables
    
    int account[]={ 5658845, 4520125, 7895122, 8777541, 1302850,
                    8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                    1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };
                    
    int accNum=0;
    bool found=true;
    
    cout<<"Enter your 7 Digit Account Number: ";
    cin>>accNum;
    
    if (found == srchAray(accNum, account))
        cout<<"The Number "<<accNum<<" is a Vaild Account"<<endl;
    else
        cout<<"The Number "<<accNum<<" is NOT a Vaild Account. Sorry, Please Re-Enter!"<<endl;
    
}

void prob2(){
//Declare Variables
   
    int accAray[]={ 2, 10, 12, 8, 7, 11, 13, 16, 1, 17, 3, 15, 9, 5, 6, 18, 4, 14 };
    int accNum=0;
    bool found=true;
    
    cout<<"Please Enter Your 7-Digit Account Number: "<<endl;
    cin>>accNum;
    
    selctSort(accAray);
    if (found == binarySrch(accNum, accAray))
        cout<<"The Account Number "<<accNum<<" is a Valid Account!"<<endl;
    else
        cout<<"The Account Number "<<accNum<<" is NOT a Valid Account!";
        cout<<" Try Again!"<<endl;
    
}

void prob3(){
//Declare Variables
    
    int winNum[]={ 13579, 26791, 26792, 33445, 55555,
                   62483, 77777, 79422, 85647, 93121};
                   
    int guess=0;
    bool found=true;
    
    cout<<"Enter your 5-Digit Lucky Number: ";
    cin>>guess;
    
    if (found == srchArray(guess, winNum))
        cout<<"Your Lottery Ticket Number "<<guess<<" is a Winner this Week!"<<endl;
    else
        cout<<"Your Lottery Ticket Number "<<guess<<" is NOT a Winner! Try Again Next Week!"<<endl;
    
}

void prob4(){
//Declare Variables
    
    int accAray[]={ 13579, 26791, 26792, 33445, 55555,
                   62483, 77777, 79422, 85647, 93121 };
    int accNum=0;
    bool found=true;
    
    cout<<"Please Enter Your 5-Digit Account Number: "<<endl;
    cin>>accNum;
    
    if (found == binSrch(accNum, accAray))
        cout<<"The Account Number "<<accNum<<" is a Valid Account!"<<endl;
    else
        cout<<"The Account Number "<<accNum<<" is NOT a Valid Account! Try Again!"<<endl;
}

void prob5(){
//Declare Variables
    
    const int mths = 12;
	Data rainfall[mths];

	getData(rainfall, mths);
	selectionSort(rainfall, mths);
	displayReport(rainfall, mths);
}

void prob6(){
//Declare Variables
    
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
}

//------------------------------------------------------------------------------
//Function Calling
void menu(){
    //Input Data/Variables
    cout<<"Choose from the Menu"<<endl;
    cout<<"1. Problem 1: Charge Account Validation"<<endl;
    cout<<"2. Problem 2: Charge Account Validation Modification"<<endl;
    cout<<"3. Problem 3: Lottery Winners"<<endl;
    cout<<"4. Problem 4: Lottery Winners Modification"<<endl;
    cout<<"5. Problem 5: Rainfall Statistics Modification"<<endl;
    cout<<"6. Problem 6: String Selection Sort"<<endl;
    cout<<"Enter the Problem Number: ";
    
}

bool srchArray (int giveVal, int findAray [NUM_ELEMENTS])
{
    for (int i=0;i<NUM_ELEMENTS;i++)
    {
        if (giveVal == findAray[i])
        return true;
    }
    return false;
}

bool binarySrch (int giveVal, int arr[NUM_ELEMENTS])
{
    int fir=0;
    int mid=0;
    int end=NUM_ELEMENTS - 1;
    int pos=0;
    
    while (fir <= end)
    {
        mid=(fir + end / 2); //finds mid
        
        if (arr[mid] == giveVal)
            return true;
        else if (arr[mid] > giveVal)
            end = mid - 1;
        else
            fir = mid + 1;
    }
    
    return false;
}

void selctSort (int arr[NUM_ELEMENTS])
{
    int minIndex = 0;
    
    for (int i=0;i<NUM_ELEMENTS - 1;i++)
    {
        int minIndex = i;
        int minVal = arr[i];
        for (int c=i + 1; c<NUM_ELEMENTS;c++)
        {
            if (arr[c] < minVal)
            {
                minVal=arr[c];
                minIndex=c;
            }
        }
        
        //Swaping Vals
        int temp = arr[i];
        arr[i] = minVal;
        arr[minIndex] = temp;
    }
}

bool srchAray (int giveVal, int findAray [NUM_ELEMENT])
{
    for (int i=0;i<NUM_ELEMENT;i++)
    {
        if (giveVal == findAray[i])
        return true;
    }
    return false;
}

bool binSrch (int giveVal, int arr[NUM_ELEMENT])
{
    int fir=0;
    int mid=0;
    int end=NUM_ELEMENT;
    int pos=0;
    
    while (fir <= end)
    {
        mid=(fir + end); //finds mid
        
        if (arr[mid] == giveVal)
            return true;
        else if (arr[mid] > giveVal)
            end = mid;
        else
            fir = mid;
        return true;
    }
    return false;
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



