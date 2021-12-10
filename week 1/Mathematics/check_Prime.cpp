//Given an integral number N. The task is to find the count of digits present in this number.

//to Check if a number is Prime
#include <bits/stdc++.h>
using namespace std;
bool naiveApproch(int N)
{
    // T.C : O(N)
    if(N<2)
    return false;
    else
    {
        for(int i=2;i<N;i++)
        {
            if(N%i==0)
            return false;
        }
        return true;
    }
}
bool BetterApproch(int N)
{
    if(N<2)
    return false;
    else
    {
        for(int i=2;i<N/2;i++)
        {
            if(N%i==0)
            return false;
        }
        return true;
    }
}
int main() {
    int N;
    // N=10;
    cout<<"Enter N\n";
    cin>>N;
    cout<<"By naive approach "<<naiveApproch(N)<<endl;
    cout<<"Better approach "<<BetterApproch(N);
    return 0;
}  // } Driver Code Ends
