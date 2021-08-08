// Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it 
// In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5]

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void reverseInGroups(vector<int>& arr, int n, int k){
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
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(vector<int>& arr, int n){
        
        // Your code here
        // logic is to rotate array in grp of 2 elements

        reverseInGroups(arr,n,2);

    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        Solution ob;
        ob.convertToWave(a, n);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}  // } Driver Code Ends

/*Testcases
1
5
1 2 3 4 5
*/