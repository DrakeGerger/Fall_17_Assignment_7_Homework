/* 
 * File: main.cpp
 * Author: Drake Gerger
 * Purpose: Lottery Winners
 * Created on December 7, 2017, 2:10 PM
 */

//System Libraries
#include <iostream>

using namespace std;
//User Libraries

//Global Constants
const int NUM_ELEMENTS=10;
bool srchAray(int, int [NUM_ELEMENTS]);

//Function Prototypes

//Execution Begins Here!
int main(){
    
    int winNum[]={ 13579, 26791, 26792, 33445, 55555,
                   62483, 77777, 79422, 85647, 93121};
                   
    int guess=0;
    bool found=true;
    
    cout<<"Enter your 5-Digit Lucky Number: ";
    cin>>guess;
    
    if (found == srchAray(guess, winNum))
        cout<<"Your Lottery Ticket Number "<<guess<<" is a Winner this Week!"<<endl;
    else
        cout<<"Your Lottery Ticket Number "<<guess<<" is NOT a Winner! Try Again Next Week!"<<endl;
    
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











