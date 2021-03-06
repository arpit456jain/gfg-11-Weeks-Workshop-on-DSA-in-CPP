// Given a positive integer value N. The task is to find how many numbers less than or equal to N have numbers of divisors exactly equal to 3.
// Input:
// N = 6
// Output: 1
// Explanation: The only number less than 6 with 
// 3 divisors is 4.
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool checkDivisors(int N)
    {
        int c=0;
        for(int i=1; i<=N; i++)
        {
            if(N%i==0)
            c++;
            if (c>3)
            return false;
        }
        if(c==3)
        return true;
        else return false;
    }
    bool isPrime(int N)
    {
        for(int i = 2; i <= int(sqrt(N)); i++)
        {
            if(N%i == 0)
            return false;
        }
        return true;
    }
    int exactly3Divisors(int N)
    {
        //Your code here
        int count =0 ;
        for(int i=2; i<N; i++)
        {
            if(isPrime(i))
            {
                if(i*i<=N)
                {
                    count++;
                }
                else
                return count;
            }
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends