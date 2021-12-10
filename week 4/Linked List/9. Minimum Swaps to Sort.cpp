// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&arr)
	{
	    // Code here
	     // Your code here  
	     int N = arr.size();
        vector<pair<int,int>> v(N);
        for(int i=0;i<N;i++)
        v[i] = {arr[i],i};
        
        sort(v.begin(),v.end());
        
        int c=0;
        for(int i=0;i<N;i++)
        {
            if(v[i].second == i)
            {
            // cout<<i<<v[i].first<<v[i].second<<"\n";
            continue;    
            }
            
            
            else
            {
                // cout<<"dnsakj";
                c++;
                swap(v[i],v[v[i].second]);
                i--;
            }
        }
        // cout<<c;
        return c;
        
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends