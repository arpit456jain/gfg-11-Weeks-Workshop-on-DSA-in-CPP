/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
 

Example 1:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
*/
// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        void naiveApproch(long long arr1[], long long arr2[], int n, int m) 
        {
            int temp[m+n];
            int i=0;
            int j=0;
            int k=0;
            while(i<n && j>m)
            {
                if(arr1[i]<arr2[j])
                {
                temp[k++] = arr1[i++];
                }
                if(arr1[i]>arr2[j])
                {
                    temp[k++] = arr2[j++];
                }
                if(arr1[i]==arr2[j])
                {
                    temp[k++] = arr1[i++];
                    temp[k++] = arr2[j++];
                    
                }
                
            }


            //copy array from temp to original ones
            for(int i=0; i<n; i++)
            {
                arr1[i]=temp[i];
            }
            for(int i=n; i<m; i++)
            {
                arr2[i]=temp[i];
            }
        }
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            naiveApproch(arr1, arr2, n, m);
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends