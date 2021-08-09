/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.
*/
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
  
    long long int naiveApproch(long long int x) 
    {
        for(long long int i = 1; i<=x;i++)
        {   
            // T.C : O(x)
            if(i*i == x)
            return i;
            if(i*i > x)
            return i-1;
        }  
    }
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        long long ans = 0;
        ans = naiveApproch(x);
        cout <<"sqaure root by naiveApproch : " <<ans << endl;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends