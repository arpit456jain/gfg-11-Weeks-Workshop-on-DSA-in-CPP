/*
A peak element in an array is the one that is not smaller than its neighbours.
Given an array arr[] of size N, find the index of any one of its peak elements.
Note: The generated output will always be 1 if the index that you return is correct. Otherwise output will be 0. 


Example 1:

Input:
N = 3
arr[] = {1,2,3}
Output: 1
Explanation: index 2 is 3.
It is the peak element as it is 
greater than its neighbour 2.
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
class Solution
{
    public:
	int naiveApproch(int arr[], int n)
	{
		int pos=0;
      int maxele = arr[0];
      for(int i=1;i<n;i++)
      {
          if(arr[i]>maxele)
          {
              maxele = arr[i];
              pos = i;
          }
      }
	  return pos;
	}
	int optimizeApproch(int arr[],int low,int high, int n)
	{
		int mid = low + (high - low)/2 ;
	    if ((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;
  
    // If middle element is not peak and its left neighbour is greater  
    // than it, then left half must have a peak element 
    else if (mid > 0 && arr[mid-1] > arr[mid])
        return optimizeApproch(arr, low, (mid -1), n);
  
    // If middle element is not peak and its right neighbour is greater 
    // than it, then right half must have a peak element 
    else 
        return optimizeApproch(arr, (mid + 1), high, n);

	return -1;
	}
    int peakElement(int arr[], int n)
    {
      int ans;
	    if(n<=1)
            return 0;
	  ans = naiveApproch(arr,n);
	  ans = optimizeApproch(arr,0,n-1,n);
      return ans;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;
		
		int A = ob. peakElement(tmp,n);
		
		if(A<0 and A>=n)
		    cout<<0<<endl;
		else
		{
		if(n==1 and A==0)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A]>=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		cout<<f<<endl;
		}
		
	}

	return 0;
}  // } Driver Code Ends