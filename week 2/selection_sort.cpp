// { Driver Code Starts
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int select(int arr[], int i);
void selectionSort(int arr[], int n);
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
    int FindindexOfMin(int arr[], int low,int n) 
    {
        int pos = low;
        int min_element = arr[low];
        for (int i=low; i < n; i++)
        {
            if(arr[i]<min_element)
            {
                min_element = arr[i];
                pos = i;
            }
        }
        return pos;
    }
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


int select(int arr[], int i)
{
    // code here such that selecionSort() sorts arr[]
}


void selectionSort(int arr[], int n)
{
  //code here
  int min_index;
  for(int i = 0; i < n; i++)
  {
      min_index = FindindexOfMin(arr,i,n);
        swap(&arr[i],&arr[min_index]);
  }
}