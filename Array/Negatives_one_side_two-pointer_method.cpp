#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void separate(int arr[], int low, int high)
{
    while(low <= high)
    {
        if(arr[low]<0 && arr[high]>0)      // if left side element is negative and right side is positive.
        {
            low++;
            high--;
        }
        else if(arr[low]>0 && arr[high]<0)   // if left side element is positive and right side is negative
        {
            swap(&arr[low], &arr[high]);
            low++;
            high--;
        }
        else if(arr[low]>0)               // if left side element is positive.
            high--;
        else if(arr[high]<0)              // if right side element is negative.
            low++;

    }
}

int main()
{
    int arr[] = {22,3,-10,-23,-32,9,98,-80,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    separate(arr,0,n-1);
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}