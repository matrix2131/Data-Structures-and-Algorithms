#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void side(int arr[], int low, int high)
{
    for(int i = 0; i<=high; i++)
    {
        if(arr[i]<0)
        {
            swap(&arr[i],&arr[low]);
            low++;
        }
    }
}

int main()
{
    int arr[] = {-1,2,3,-17,-21,43,-19};
    int n = sizeof(arr)/sizeof(arr[0]);
    side(arr,0,n-1);
    for(int j = 0; j<n; j++)
    {
        cout<<arr[j]<<" ";
    }
}