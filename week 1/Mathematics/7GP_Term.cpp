// Given the first 2 terms A and B of a Geometric Series. The task is to find the Nth term of the series.
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        //Complete this function
    double termOfGP(int A,int B,int N)
    {
        //Your code here
        double commonRatio = double(B)/double(A);
        double RToPowern = pow(commonRatio,N-1);
        // cout<<commonRatio<<endl<<RToPowern;
        return A*RToPowern;  
    }
};

// { Driver Code Starts.


int main()
{
    int T; //testcases total
    cin>>T;//input the testcases

    for(int i=0;i<T;i++) //white testcases are not exhausted
    {
        int A,B;
        cin>>A>>B; //input first and second term of gp
        int N;
        cin>>N; //input n
        Solution ob;
        cout<<floor(ob.termOfGP(A,B,N))<<endl;
    }

    return 0;
}

  // } Driver Code Ends