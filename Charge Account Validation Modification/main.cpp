/* 
 * File: main.cpp
 * Author: Drake Gerger
 * Purpose: Charge Account Vaildation Modification
 * Created on December 7, 2017, 2:00 PM
 */

//System Libraries
#include <iostream>

using namespace std;
//User Libraries

//Global Constants
const int NUM_ELEMENTS=18;

//Function Prototypes
void selctSort (int arr[NUM_ELEMENTS]);
bool binSrch (int, int arr[NUM_ELEMENTS]);

//Execution Begins Here!
int main(){
    
    int accAray[]={ 2, 10, 12, 8, 7, 11, 13, 16, 1, 17, 3, 15, 9, 5, 6, 18, 4, 14 };
    int accNum=0;
    bool found=true;
    
    cout<<"Please Enter Your 7-Digit Account Number: "<<endl;
    cin>>accNum;
    
    selctSort(accAray);
    if (found == binSrch(accNum, accAray))
        cout<<"The Account Number "<<accNum<<" is a Valid Account!"<<endl;
    else
        cout<<"The Account Number "<<accNum<<" is NOT a Valid Account!";
        cout<<" Try Again!"<<endl;
    
    return 0;
}

bool binSrch (int giveVal, int arr[NUM_ELEMENTS])
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
