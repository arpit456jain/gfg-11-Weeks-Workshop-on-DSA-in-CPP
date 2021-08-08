// Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
// Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
#include <iostream>
#include <numeric>     
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int naiveApproch(long long a[], int n)
    {
        // T.c : O(n)
        long long sum1 = 0;
        for (int i = 0; i < n; i++)
        sum1 += a[i];
        cout <<"sum is"<<sum1<<endl;

        //now logic is to iterate over array and substract point and add it to left 
        long long left = 0;
        long long current = 0;
        long long right = sum1;

        for(long long i = 0; i < n;i++)
        {
            left += current;
            current = a[i];
            right = right - a[i];
            if(left == right)
            return i+1;
        }

        return -1;

    }
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int res = naiveApproch(a,n);
        return res;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends