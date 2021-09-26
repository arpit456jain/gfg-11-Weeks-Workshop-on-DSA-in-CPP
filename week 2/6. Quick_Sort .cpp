// { Driver Code Starts
#include <stdio.h>
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
    void printArray(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        
        cout<<"\n";
    }
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
{
    // code here
    if(low<high)
    {
        int pi = partition(arr,low,high);
        printArray(arr,8);
        cout<<"pivot pos"<<pi<<endl;
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
    
int partition (int arr[], int low, int high)
{
   // Your code here
   // let take last element as pivot
   int pivot = arr[high];
   int pindex = low;
   for(int i=low;i<high;i++)
   {
       if(arr[i]<=pivot)
       {
           //swap the element to left
        //    cout<<"swapping"<<arr[i]<<"and"<<arr[pindex]<<endl;
           swap(arr[i],arr[pindex]);
           pindex++;
       }
   }
   swap(arr[high],arr[pindex]);
   
   return pindex;
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
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends