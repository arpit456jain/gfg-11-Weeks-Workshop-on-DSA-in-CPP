// Given two integers ‘a’ and ‘m’. The task is to find the smallest modular multiplicative inverse of ‘a’ under modulo ‘m’.
// Input:
// a = 3
// m = 11
// Output: 4
// Explanation: Since (4*3) mod 11 = 1, 4 
// is modulo inverse of 3. One might think,
// 15 also as a valid output as "(15*3)
// mod 11"  is also 1, but 15 is not in 
// ring {0, 1, 2, ... 10}, so not valid.
#include<iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Complete this function
    int modInverse(int a, int m)
    {
        //Your code here
        for (int i = 0; i < m; i++)
        {
            if((i*a)%m == 1)
            return i;
        }

        return -1;
        
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	
	//taking testcases
	cin>>T;
	while(T--){
		int a,m;
		
		//taking input a and m
		cin>>a>>m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends