// Given a sorted array containing only 0s and 1s, find the transition point. 
// Input:
// N = 5
// arr[] = {0,0,0,1,1}
// Output: 3
// Explanation: index 3 is the transition 
// point where 1 begins.
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    if(arr[0]==1)
    for(int i = 0; i < n-1; i++) {
        if(arr[i] == 0 && arr[i + 1] == 1)
        return i+1;
    }
    return -1;
}