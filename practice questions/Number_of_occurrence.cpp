/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.

1
7 2
1 1 2 2 2 2 3
*/
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int naiveApproch(int arr[], int n, int x) {
        int c=0;
        // T.C = O(n)
        for(int i=0; i<n; i++)
        {
            if(arr[i] == x)
            c++;
        }
        return c;
    }
    int firstOccurence(int arr[], int low,int high, int x,int n)
    {
        if(high>=low)
        {
            int mid = (low + high)/2;
            cout<<mid<<endl;
            if((mid == 0 || arr[mid]>arr[mid-1]) && arr[mid] == x)
            return mid;
            
            else if(arr[mid]>=x)
            return firstOccurence(arr,low,mid-1,x,n);

            else
            return firstOccurence(arr,mid+1,high,x,n);
            
        }
          return -1;
    }
    int lastOccurence(int arr[], int low,int high, int x,int n)
    {
        if(high>=low)
        {
            int mid = (low + high)/2;
            if((mid == n-1 || arr[mid]<arr[mid+1]) && arr[mid] == x)
            return mid;

            else if(arr[mid]>x)
            return lastOccurence(arr,low,mid-1,x,n);

            else
            return lastOccurence(arr,mid+1,high,x,n);
        }
          return -1;
    }
	int optimizeApproch(int arr[], int n, int x) {
        // first sort the array 
        sort(arr,arr+n); //T.C : O(log(n))
        // now the array is 1 1 2 2 2 2 3 
        // we just want first and last occurence of x which is 2 in this case which also required O(log(n))

        // first occurence
        int first = firstOccurence(arr,0,n-1,x,n);
        int last = lastOccurence(arr,0,n-1,x,n);
        cout<<"firstOccurence"<<first<<" lastOccure"<<last<<"\n";
        int no_of_occurrences = last - first;
        if (first == -1)
        return 0;
        return no_of_occurrences + 1;
    }
	int count(int arr[], int n, int x) {
	    // code here
        int ans ;
        // ans = naiveApproch(arr,n,x);
        ans = optimizeApproch(arr,n,x);
        return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends