/*
Given an array arr[] of size N, find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing
number is 6.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    int naiveApproch(int arr[], int n) { 
        // logic is i will run 2 loops and check every number whether its in array or not
        // T.C : O(n*n) giving TLE
        for (int i = 1; i < 1000; i++)
        {   
            bool flag = false;
            for (int j = 0; j < n;j++)
            {
                    if(arr[j]==i)
                    {
                    flag = true; // that means i is present in array
                    break;
                    }
            }
            if (flag == false)
            return i;
        }
    }
    int findMissingByUsingSort(int arr[], int n) { 
        // T.C : O(n) but still TLE
        // i will index referncing 
        int temp[n];
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>=0)
            temp[arr[i]] = 1;
        }
        // check the temp array where its 0 
        for (int i = 0; i < n; i++)
        {
            if(arr[i]==0)
            return i;
        }
        return n+1;
    }
    // Function to find missing integer in array
    // arr: input array
    // n: size of array
    int findMissing(int arr[], int n) { 
        
        // Your code here
        int res = 0;
        //T.c : O(n*n) giving TLE
        // res = naiveApproch(arr,n); 
        res = findMissingByUsingSort(arr,n); // T.C : O(n) but still TLE
        return res;
    }
};

// { Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        cout<<ob.findMissing(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends

// testcases
// 1
// 5
// 1 2 3 4 5