/*
Given a number N, calculate the prime numbers up to N using Sieve of Eratosthenes.  

Example 1:

Input:
N = 10

Output:
2 3 5 7

Explanation:
Prime numbers less than equal to N 
are 2 3 5 and 7.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        // Create a boolean array
        // "prime[0..n]" and initialize
        // all entries it as true.
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == true)
            {
                // update to false all multiple of prime[i]
                for (int j = i * 2; j <= n; j = j + i)
                    prime[j] = false;
            }
        }
        vector<int> primes;
        // Print all prime numbers
        for (int p = 2; p <= n; p++)
            if (prime[p])
                primes.push_back(p);

        return primes;
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
        Solution ob;
        vector<int> primes = ob.sieveOfEratosthenes(N);
        for (auto prime : primes)
        {
            cout << prime << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// Time Complexity: O(NloglogN)
// Auxiliary Space: O(N)