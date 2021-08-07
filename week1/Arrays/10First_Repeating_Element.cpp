// Given an array arr[] of size n, find the first repeating element. The element should occurs more than once and the index of its first occurrence should be the smallest.
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int naiveApproch(int arr[],int n)
    {
        // T.C : O(N) but giving TLE
        // logic is i will take a another array and will store position of 1st occurence at that number
        vector<int> arr2(100000000,0);
        int min=-1;
        for(int i = 0; i < n; i++)
        {
            if(arr2[arr[i]]==0)
            arr2[arr[i]] = i+1; // inserting index of 1st occurence of element at that number
            else
            {
            // min = arr2[arr[i]];
                if(min == -1)
                min = arr2[arr[i]];

                else
                {
                    if(arr2[arr[i]]<=min)
                    min = arr2[arr[i]];
                }
            }
            // cout<<min<<"\n";
        } 
        return min;
    }
    //Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        //code here
        int res =  naiveApproch(arr,n);
        return res;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> arr[i] ;
        Solution ob;    
        cout << ob.firstRepeated(arr,n) << "\n";
    }

    return 0;
}
  // } Driver Code Ends