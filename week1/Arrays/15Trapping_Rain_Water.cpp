/* Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.
Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10*/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int findLeftMax(int arr[], int n,int i)
    {
        //iterate from i to 0 and find the max height
        // T.C : O(n)
        int maxheight = 0;
        for(int j=i;j>=0;j--)
        {
            maxheight = max(maxheight,arr[j]);
        }
        return maxheight;

    }
    int findRightMax(int arr[], int n,int i)
    {
        // iterate from i to n and find the max height  
        // T.C : O(n)      
        int maxheight = 0;
        for(int j=i;j<n;j++)
        {
            maxheight = max(maxheight,arr[j]);
        }
        return maxheight;
    }
    int naiveApproch(int arr[], int n)
    {
        // logic is to count amount of water store for per index
        // to find water at a postion amount = min(leftmax,rightmax) - valueofthatpos
        int totalwater = 0;
        // ignoring 1st and last position because thoose walls does not store any water
        for(int i = 1; i <n-1;i++) 
        {  
            //  Total T.C : O(n*n)
            int leftmax = findLeftMax(arr,n,i); // T.C : O(n)
            int rightmax = findRightMax(arr,n,i); // T.C : O(n)
            cout <<"left max height"<<leftmax<<endl;
            cout<<"right max height"<<rightmax<<endl;
            totalwater += min(leftmax,rightmax) - arr[i];
        }
        return totalwater;
    }

    int trappingWater(int arr[], int n){
        // Code here
        int ans = naiveApproch(arr,n); // T.C : O(n*n)
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends

/*
testcase
1
4
7 4 0 9
*/