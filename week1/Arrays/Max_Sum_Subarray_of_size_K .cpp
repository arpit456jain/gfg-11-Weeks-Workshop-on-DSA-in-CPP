// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        // logic is to make a window of size n and slide it over the array
        int curr_sum = 0;
        // first find sum of first element
        for(int i = 0; i <K; i++)
        curr_sum += Arr[i];

        int max_sum = curr_sum;
        // now move the window over the array
        for(int i = K; i <N; i++)
        {
            curr_sum += Arr[i];
            curr_sum -= Arr[i-K];

            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;

    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends