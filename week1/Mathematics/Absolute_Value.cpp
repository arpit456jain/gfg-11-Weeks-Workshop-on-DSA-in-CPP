// You are given an interger I, find the absolute value of the interger I.

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
        int absolute(int I) {
        // Your code goes here
        if(I < 0) return -I;
        else return I;
    }

};

// { Driver Code Starts.

int main() {
    int T;    // number of testcases
    cout<<"Enter T";
    cin >> T; // input number of testcases
    while (T--) {
        int I;
        cin >> I;
        Solution ob;
        cout << ob.absolute(I) << endl; // print the output
    }
    return 0;
}  // } Driver Code Ends

/*
Input:
I = 45
Output: 45
Explanation: 
The absolute value of 45 is 45 itself.
*/