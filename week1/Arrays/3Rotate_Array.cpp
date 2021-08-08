// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here

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