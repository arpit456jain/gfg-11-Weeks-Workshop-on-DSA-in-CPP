// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int firstIndex(int arr[], int n) 
    {
        // Your code goes here
        int low=0;
        int high = n-1;
        while(high>=low)
        {
            int mid = (low+high)/2;
            if(arr[mid] == 1 && arr[mid-1] == 0)
            return mid;
            
            else if(arr[mid] == 0)
            low = mid + 1;
            
            else
            high = mid-1;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}  // } Driver Code Ends