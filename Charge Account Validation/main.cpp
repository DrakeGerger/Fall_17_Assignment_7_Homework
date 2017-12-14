/* 
 * File: main.cpp
 * Author: Drake Gerger
 * Purpose: Charge Account Vaildation
 * Created on December 7, 2017, 1:30 PM
 */

//System Libraries
#include <iostream>

using namespace std;
//User Libraries

//Global Constants
const int NUM_ELEMENTS=18;
bool srchAray(int, int [NUM_ELEMENTS]);

//Function Prototypes

//Execution Begins Here!
int main(){
    
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
    
    return 0;
}

bool srchAray (int giveVal, int findAray [NUM_ELEMENTS])
{
    for (int i=0;i<NUM_ELEMENTS;i++)
    {
        if (giveVal == findAray[i])
        return true;
    }
    
    return false;
}











