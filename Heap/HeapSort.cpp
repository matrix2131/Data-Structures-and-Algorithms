#include<bits/stdc++.h>
using namespace std;

// Time Complexity ---> O(nlogn) 
// In-place ---> YES
// Stable -----> NO

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l<n && arr[l] > arr[largest])
        largest = l;
        
    if(r<n && arr[r] > arr[largest])
        largest = r;
        
    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n)
{
    int start = (n/2)-1;
    for(int i = start; i>=0; i--)
    {
        heapify(arr,n,i);
    }
    
    for(int i = n-1; i>0; i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int arr[] = {10,2,3,19,8,9,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
