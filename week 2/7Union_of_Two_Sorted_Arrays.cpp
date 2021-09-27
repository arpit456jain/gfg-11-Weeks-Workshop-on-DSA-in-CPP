/*
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.


Example 1:

Input: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n1, int n2)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> vect;
        int i,j;
        i=0;j=0;
        while(i<n1 && j<n2)
        {
            // to handle duplicates
            while(i<n1-1 && arr1[i] == arr1[i+1])
            i++;
            
            while(j<n2-1 && arr2[j] == arr2[j+1])
            j++;
            
            if(arr1[i]<arr2[j])
            vect.push_back(arr1[i++]);
            
            else if(arr2[j]<arr1[i])
            vect.push_back(arr2[j++]);
            
            else
            {
            vect.push_back(arr1[i]);
            i++;
            j++;
            }
        }
        
        while(i<n1)
        {
            if(i<n1-1 && arr1[i] == arr1[i+1])
            i++;
            
            else
            vect.push_back(arr1[i++]);
        }
        
        while(j<n2)
        {
            if(j<n2-1 && arr2[j] == arr2[j+1])
            j++;
            
            else
            vect.push_back(arr2[j++]);
        }
        return vect;
    }
};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends