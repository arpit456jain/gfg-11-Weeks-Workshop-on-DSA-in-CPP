// Given a temperature in celsius C. You need to convert the given temperature to Fahrenheit.
// (0°C × 9/5) + 32 = 32°F
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    //You need to complete this function
    double cToF(int C)
    {
        //Your code here
        return (C*9)/5 + 32;
    }
};

// { Driver Code Starts.

int main()
{
    int T;//number of testcases
    int C,F;
    cin >> T; //input number of testcases
    while(T--){
        cin >> C;//input temperature in celscius
        Solution ob;
        cout << floor(ob.cToF(C)) << endl; //print the output
    }
    return 0;
}  // } Driver Code Ends

/*
Input:
C = 32
Output: 89
Explanation: Using the conversion 
formula of celsius to farhenheit , it
can be calculated that, for 32 degree
C, the temperature in Fahrenheit = 89.
 */