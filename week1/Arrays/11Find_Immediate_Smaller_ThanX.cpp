// Given an array arr[] of size N containing positive integers and an integer X, find the element in the array which is smaller than X and closest to it.
// Input:
// N = 5
// arr[] = {4 67 13 12 15}
// X = 16
// Output: 15
// Explanation: For a given value 16, there
// are four values which are smaller than
// it. But 15 is the number which is smaller
// and closest to it with minimum difference
// of 1.
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // User function to complete
    // arr[]: input array
    // n: size of array
    // k: find element smaller and closest to it. 
    int immediateSmaller(int arr[], int n, int x)
    {
        // your code here
        // logic is i will store 1st element in min variable then i will check every element if its smaller than x then i will check it with min 

        int min = -1;
        for (int i = 0; i < n;i++)
        {
            if(arr[i] < x and arr[i]>min)
            min = arr[i];
        }
        
        return min;
    }   
};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    
            int n;
        	cin >> n;
        	
        	int arr[n];
        	
        	for(int i = 0;i<n;i++){
        	    cin >> arr[i];
        	}
        	
        	int x;
        	cin >> x;
        	Solution ob;
        	cout << ob.immediateSmaller(arr, n, x) << endl;
	}
	
	
	return 0;
}
  // } Driver Code Ends

  /*Testcases
  5
4 67 13 12 15
16
*/
