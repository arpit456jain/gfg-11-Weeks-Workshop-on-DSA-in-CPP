// { Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for(int i = 1; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while(j>0 && arr[j-1]>temp)
            {
                arr[j] = arr[j-1];
                j=j-1;
            }
            arr[j] = temp;
            cout<<i<<"\n";
            printArray(arr,n);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends