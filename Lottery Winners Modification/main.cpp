/* 
 * File: main.cpp
 * Author: Drake Gerger
 * Purpose: Lottery Winners Modification
 * Created on December 7, 2017, 3:10 PM
 */

//System Libraries
#include <iostream>

using namespace std;
//User Libraries

//Global Constants
const int NUM_ELEMENTS=10;

//Function Prototypes
bool binSrch (int, int arr[NUM_ELEMENTS]);

//Execution Begins Here!
int main(){
    
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
    
    return 0;
}

bool binSrch (int giveVal, int arr[NUM_ELEMENTS])
{
    int fir=0;
    int mid=0;
    int end=NUM_ELEMENTS;
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
