//Given an integral number N. The task is to find the count of digits present in this number.

#include <bits/stdc++.h>
using namespace std;
int naiveApproch(int N)
{
    // T.C : O(digitsCount).
    if(N==0) 
    return 0;
    else
    {
        int r=0;
        int c=0;
        
        while(N>0)
        {
            r=N%10;
            N=N/10;
            c++;
        }
        
        return c;
    }
}
int BetterApproch(int N)
{
    // T.c : O(1)
    N = log10(N) + 1;
    return N; 
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
