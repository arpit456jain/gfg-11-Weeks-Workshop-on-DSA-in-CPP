// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int binarysearchByLoop(int arr[], int n, int k)
    {
        // code here
        // int n = arr.size();
        int l = 0;
        int r = n - 1;
        if (n == 1)
        {
            if (arr[0] == k)
                return 0;
            else
                return -1;
        }
        else
        {

            while (l <= r)
            {
                int mid = (l + r) / 2;
                cout << mid << "\n";
                if (arr[mid] == k)
                    return mid;

                else if (k < arr[mid])
                    r = mid - 1;

                else
                    l = mid + 1;
            }
            // return binarySearch(arr,l,r,k);
            return -1;
        }
    }
    int binarysearchByRecursion(int arr[], int n, int k)
    {
        int l = 0;
        int r = n - 1;
        if (n == 1)
        {
            if (arr[0] == k)
                return 0;
            else
                return -1;
        }
        else
        {

            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (arr[mid] == k)
                    return mid;

                else if (k < arr[mid])
                    r = mid - 1;

                else
                    l = mid + 1;
            }
            // return binarySearch(arr,l,r,k);
            return -1;
        }
    }
    int binarysearch(int arr[], int n, int k)
    {
        int ans;
        ans = binarysearchByLoop(arr, n, k);
        cout<<"ans by loop "<<ans;
        ans = binarysearchByRecursion(arr, n, k);
        cout<<"ans by recursion "<<ans;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends