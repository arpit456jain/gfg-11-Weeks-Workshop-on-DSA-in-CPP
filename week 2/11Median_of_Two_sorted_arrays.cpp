// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        // code here
        int temp[m+n];
        int i=0;
        int j=0;
        int k=0;
        while(i<n && j<m)
        {
            if(arr[i]<brr[j])
            temp[k++] = arr[i++];
            
            else if(arr[i]>brr[j])
            temp[k++] = brr[j++];
            
            else
            {
            temp[k++] = arr[i++];
            temp[k++] = brr[j++];
            }

        }
        while(i<n)
        temp[k++] = arr[i++];
        
        while(j<m)
        temp[k++] = brr[j++];
        
        
        if((m+n)%2 == 0)
        {
            int median_index1 = (m+n)/2 - 1;
            int median_index2= (m+n)/2;
            return (temp[median_index1] + temp[median_index2])/2;
            
        }
        else
        {
        int median_index = (m+n)/2;    
        return temp[median_index];
        }
        return 9;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}  // } Driver Code Ends