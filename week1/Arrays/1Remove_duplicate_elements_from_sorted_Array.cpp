// Given a sorted array A of size N, delete all the duplicates elements from A.
// Note: Don't use set or HashMap to solve the problem.
// Input:
// N = 5
// Array = {2, 2, 2, 2, 2}
// Output: 2
// Explanation: After removing all the duplicates 
// only one instance of 2 will remain.
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int arr[],int n){
        // code here
        // T.C : O(n)
        if (n==0 || n==1)
        return n;
        
        int j=0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]!=arr[i+1])
            {
                arr[j]=arr[i];
                j++;
            }

        }
        arr[j]=arr[n-1];
        return j+1;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
} 