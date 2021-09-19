/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int naiveApproch(long long int x)
    {
        for (long long int i = 1; i <= x; i++)
        {
            // T.C : O(sqrt(x))
            if (i * i == x)
                return i;
            if (i * i > x)
                return i - 1;
        }
    }
    long long int floorSqrt(long long int x)
    {
        // Your code goes here
        long long ans = 0;
        ans = naiveApproch(x);
        cout << "sqaure root by naiveApproch : " << ans << endl;
        return ans;
    }
    float SqrtByBinarySearch(long long int n)
    {
        int l = 0;
        int r = n;
        float ans;

        // for integral part only
        while (r >= l)
        {
            int mid = (r + l) / 2;
            if (mid * mid == n)
                return mid;

            else if (mid * mid < n)
            {
                ans = mid;
                l = mid + 1;
            }

            else
                r = mid - 1;
        }
        // For computing the fractional part
        // of square root upto given precision
        float increment = 0.1;
        int precision = 6;
        for (int i = 0; i < precision; i++)
        {
            while (ans * ans <= n)
            {
                ans += increment;
            }

            // loop terminates when ans * ans > number
            ans = ans - increment;
            increment = increment / 10;
        }
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
        long long n;
        cin >> n;
        Solution obj;
        // cout << obj.floorSqrt(n) << endl;
        cout << obj.SqrtByBinarySearch(n) << endl;
    }
    return 0;
}
// } Driver Code Ends