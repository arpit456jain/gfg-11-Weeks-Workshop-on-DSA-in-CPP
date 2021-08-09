/*
Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 

 

Example 1:

Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    void printArray(int arr[],int n) 
    {
        for(int i = 0; i < n; i++)
        cout<<arr[i];

        cout<<endl;
    }
    void reverseArray(int arr[],int first,int last,int n)
    {
        // T.C : O(n)
        int left = first;
        int right = last;
        // reverseArray(arr,left,right);    
        while(left<right)
            {
                    swap(arr[left],arr[right]);
                    left++;
                    right--;
            }
    }
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // total T.C : O(n)
        // code here
        // logic is 
        // 1. reverse first d elements
        // 2. reverse last n-d elements
        // 3. reverse whole array
        printArray(arr,n);
        reverseArray(arr,0,d-1,n);  // O(n)
        printArray(arr,n);
        reverseArray(arr,d,n-1,n);  // O(n)
        printArray(arr,n);
        reverseArray(arr,0,n-1,n);  // O(n)
        printArray(arr,n);
    }
};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends