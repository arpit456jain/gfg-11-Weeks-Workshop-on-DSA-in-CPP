// Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.
// Input:
// N = 5, K = 3
// arr[] = {1,2,3,4,5}
// Output: 3 2 1 5 4
// Explanation: First group consists of elements
// 1, 2, 3. Second group consists of 4,5.
#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

 // } Driver Code Ends
//User function template for C++

class Solution{
public:

    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        if(k>=n)
        {
            int left = 0;
            // to handle case when k is not multiple of n
            int right = n-1;

            // reverseArray(arr,left,right);
            while(left<right)
            {
                    swap(arr[left],arr[right]);
                    left++;
                    right--;
            }
        }
        else
        {
            
            for(int i=0; i <n;i=i+k)
            {
                int left = i;
                // to handle case when k is not multiple of n
                int right = min(i + k - 1, n - 1);

                // reverseArray(arr,left,right);
                while(left<right)
                {
                        swap(arr[left++],arr[right--]);
                        
                }
            }
 
        }       
    }
};

// { Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

  // } Driver Code Ends
  
//   Testcases
// 1
// 5 3
// 1 2 3 4 5
// 3 2 1 5 4 