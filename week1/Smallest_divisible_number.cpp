// Given a number N, find an integer denoting the smallest number evenly divisible by each number from 1 to n.
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution{
public:
    long long LCM_of_first_N_numbers(long long n)
    {
        long long ans = 1;
        for(long long i = 1; i <=n; i++)
        {
            ans = (ans*i)/__gcd(ans,i);
        }
        return ans;
    }
    long long getSmallestDivNum(long long n){
        // code here
        //hint : Ans is LCM of first n mumbers
        long long ans=LCM_of_first_N_numbers(n);
        // cout<<"LCM of first n numbers "<<ans;
        return ans;

    }
};

// { Driver Code Starts.
int main() {
    int t=1;
    // cin>>t;
    cout<<"Enter n";
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<< ob.getSmallestDivNum(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends


/*
test case
Input:
N = 6
Output: 60
Explanation: 60 is the smallest number 
divisible by 1,2,3,4,5,6.
*/