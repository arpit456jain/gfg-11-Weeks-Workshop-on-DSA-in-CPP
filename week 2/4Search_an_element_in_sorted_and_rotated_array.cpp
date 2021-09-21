/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.

Example 1:

Input:
N = 9
A[] = {5 6,7,8,9,10,1,2,3}
K = 10
Output: 5
Explanation: 10 is found at index 5.
*/

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int optimizeApproch(vector<int> vec, int K)
{
        // if only one element
        if(vec.size() ==1 )
        {
            if(vec[0] == K)
                return 0;
            else
                return -1;
        }
    // logic is find piviot elements than divide tha array in  parts then applly binary search
    int pivot ;
    for(int i = 0; i < vec.size()-1;i++)
    {
        if(vec[i]>vec[i+1])
        {
            pivot = i;
            break;
        }

    }
    // now break the array 
    /*
     2) Now call binary search for one of the two sub-arrays.
      (a) If element is greater than 0th element then
             search in left array
      (b) Else Search in right array
    */
   int left ,right;
    if(K>=vec[0])
    {
        left = 0;
        right = pivot;
        // cout<<"element is in left array";
    }
    else
    {
        left = pivot + 1;
        right = vec.size()-1; 
        // cout<<"element is in right array";
    }
    // cout<<"\npivot pos is"<<pivot<<"element is"<<vec[pivot]<<endl;
   

    // cout<<"\n";

    // now just apply normal binary search on this array
        long long mid;
    while(left<=right){
    mid = (left+right)/2;
        if(vec[mid] == K)
            return mid;

        else if(vec[mid] > K)
            right = mid -1;
        
        else
        left = mid + 1;
    }
    return -1;
}
int naiveApproah(vector<int> vec, int K)
{
    
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i] == K)
        {
            return i;
        }
        
    }
    return -1;
}
int Search(vector<int> vec, int K) {
    //code here
    int ans=0;
    ans = naiveApproah(vec,K);
    // ans = optimizeApproch(vec,K); giving segmention fault
    return ans;
}