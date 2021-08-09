/*
Given an array A of size N, print the reverse of it.

Input:
First line contains an integer denoting the test cases 'T'. T testcases follow. Each testcase contains two lines of input. First line contains N the size of the array A. The second line contains the elements of the array.
Input:
1
4
1 2 3 4
Output:
4 3 2 1
*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
	//code
    int t;
	//taking testcases
    cout<<"Enter t";
	cin>>t;
	int n;
    int arr[100];
    cout<<t;
	while(t--){
        cout<<"enter no of elements";
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        // logic is to swap elements from first and last
        int left = 0;
        int right = n-1;
        // reverseArray(arr,left,right);    
        while(left<right)
            {
                    swap(arr[left],arr[right]);
                    left++;
                    right--;
            }
        for(int i=0; i<n; i++){
            cout<<arr[i];
        }
    }
    
	return 0;
}