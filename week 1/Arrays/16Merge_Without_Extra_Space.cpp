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
            // int i=0;
            int j=0;
            int flag=0;
            while(j<m)
            {
            
                for(int i=0; i<n; i++)
                {
                    if(arr2[j]<arr1[i])
                    {
                        //swap both of them
                        long long int tmp = arr2[j];
                        arr2[j] = arr1[i];
                        arr1[i] = tmp;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if(flag == 0)
                {
                    // it means that no swapping occurs so just increase the j pointer
                    j++;
                }
            }
            // now first array is sortred so just sort the 2nd array
            sort(arr2,arr2+m);
        }
        void optimizeApproch(long long arr1[], long long arr2[], int n, int m) 
        {
            // 1) Initialize i,j,k as 0,0,n-1 where n is size of arr1 
            // 2) Iterate through every element of arr1 and arr2 using two pointers i and j respectively
            //     if arr1[i] is less than arr2[j]
            //         increment i
            //     else
            //         swap the arr2[j] and arr1[k]
            //         increment j and decrement k

            // 3) Sort both arr1 and arr2 
            int i=0, j=0;
            int k=n-1;
            while (j<m && i<=k)
            {
                if(arr1[i]<arr2[j])
                i++;
                else
                {
                    // swap last element of arr1 and current element of arr2
                    long long int temp = arr1[k];
                    arr1[k] = arr2[j];
                    arr2[j] = temp;
                    j++;
                    k--;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
            // The time complexity while traversing the arrays in while loop is O(n+m) in worst case and sorting is O(nlog(n) + mlog(m)). So overall time complexity of the code becomes O((n+m)log(n+m)).
        }
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            // naiveApproch(arr1, arr2, n, m); // giving TLE
            optimizeApproch(arr1, arr2, n, m);
            
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