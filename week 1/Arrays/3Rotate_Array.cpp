/*
Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 
Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void rotateArrUsingExtraSpace(int arr[], int d, int n){
        // logic is i will copy first d elements into another array and then i will shift elements by  d postions and then i will insert those elements in reverse order
        int temp[d];
        // copy the first d elements into the second array and then reverse it
        for(int i=0; i<d; i++)
        {
            temp[i] = arr[i];
        }
        
        // shifting array by d postiion
        for(int i=0; i<n-d; i++)
        {
            arr[i] = arr[i+d];
        }
        
        int j=0;
        // copy temp array in reverse order to original array
        for(int i=n-d; i<n; i++)
        {
            arr[i] = temp[j];
            j++;
        }
    }
    void rotateArrWithOutUsingExtraSpace(int arr[], int d, int n){
        // logic is to rotate array by one  postion d times
        for(int i=0; i<d; i++)
        {
            // rotate array by one postion 
            int temp = arr[0];
            for(int j=1; j<n; j++)
            {
                arr[j-1] = arr[j];
            }
            arr[n-1] = temp;
        }
    }
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        // rotateArrUsingExtraSpace(arr,d,n); // T.C : O(n) 
        rotateArrWithOutUsingExtraSpace(arr,d,n);
        
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

/*
Testcase
1
5 2
1 2 3 4 5 

Output : 3 4 5 1 2 
*/