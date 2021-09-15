/*
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.


Example 1:

Input:
N = 5
arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n)
    {

        // Your code here
        /* by kadane's algo 
        Initialize:
        max_so_far = INT_MIN
        max_ending_here = 0

        Loop for each element of the array
        (a) max_ending_here = max_ending_here + a[i]
        (b) if(max_so_far < max_ending_here)
                    max_so_far = max_ending_here
        (c) if(max_ending_here < 0)
                    max_ending_here = 0
        return max_so_far
        */
     long long int max_so_far = arr[0];
     long long  int max_ending_here = 0;
       for(int i = 0; i < n; i++)
       {
           max_ending_here = max_ending_here + arr[i];
           if(max_so_far<max_ending_here)
           max_so_far = max_ending_here;

           if(max_ending_here<0)
           max_ending_here=0;
           
       }
           return max_so_far;
        
    }
            
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends