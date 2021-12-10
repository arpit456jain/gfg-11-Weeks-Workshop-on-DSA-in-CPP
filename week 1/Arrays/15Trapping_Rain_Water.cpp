/* Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.
Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int findLeftMax(int arr[], int n, int i)
    {
        //iterate from i to 0 and find the max height
        // T.C : O(n)
        int maxheight = 0;
        for (int j = i; j >= 0; j--)
        {
            maxheight = max(maxheight, arr[j]);
        }
        return maxheight;
    }
    int findRightMax(int arr[], int n, int i)
    {
        // iterate from i to n and find the max height
        // T.C : O(n)
        int maxheight = 0;
        for (int j = i; j < n; j++)
        {
            maxheight = max(maxheight, arr[j]);
        }
        return maxheight;
    }
    int naiveApproch(int arr[], int n)
    {
        // logic is to count amount of water store for per index
        // to find water at a postion amount = min(leftmax,rightmax) - valueofthatpos
        int totalwater = 0;
        // ignoring 1st and last position because thoose walls does not store any water
        for (int i = 1; i < n - 1; i++)
        {
            //  Total T.C : O(n*n)
            int leftmax = findLeftMax(arr, n, i);   // T.C : O(n)
            int rightmax = findRightMax(arr, n, i); // T.C : O(n)
            cout << "left max height" << leftmax << endl;
            cout << "right max height" << rightmax << endl;
            totalwater += min(leftmax, rightmax) - arr[i];
        }
        return totalwater;
    }
    void printArray(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << "\n";
    }

    int optimizeApproch(int arr[], int n)
    {
        // Create two arrays left and right of size n. create a variable max_ = INT_MIN.
        int max1 = arr[0];
        int prefixMax[n];
        int prefixMin[n];
        // Run one loop from start to end. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign left[i] = max_
        for (int i = 0; i < n; i++)
        {
            // O(n)
            max1 = max(max1, arr[i]);
            prefixMax[i] = max1;
        }
        cout << "left max array \n";
        printArray(prefixMax, n);
        // Update max_ = INT_MIN.
        max1 = arr[n - 1];
        // Run another loop from end to start. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign right[i] = max_
        for (int i = n - 1; i >= 0; i--)
        {
            // O(n)
            max1 = max(max1, arr[i]);
            prefixMin[i] = max1;
        }
        cout << "right max array \n";
        printArray(prefixMin, n);
        // Traverse the array from start to end.
        int total_water = 0;
        // The amount of water that will be stored in this column is min(a,b) – array[i],(where a = left[i] and b = right[i]) add this value to total amount of water stored
        for (int i = 0; i < n; i++)
        {
            total_water += min(prefixMax[i],prefixMin[i]) - arr[i];
        }
        // return the total amount of water stored.
        return total_water;
    }
    int trappingWater(int arr[], int n)
    {
        // Code here
        // int ans = naiveApproch(arr,n); // T.C : O(n*n) gives TLE
        int ans = optimizeApproch(arr, n); // T.C : O(n)
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends

/*
testcase
1
4
7 4 0 9
*/