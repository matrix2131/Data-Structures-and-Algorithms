#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
}

void sort(int arr[], int low, int high)
{
    int mid = low;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(&arr[mid], &arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {0,1,2,1,2,0,1,0,2,0,1,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,0,n-1);
    cout<<"Sorted Array is: ";
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}