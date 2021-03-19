#include<bits/stdc++.h>
using namespace std;

// Making min-heap from array
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l<n && arr[l] < arr[smallest])
        smallest = l;
        
    if(r < n && arr[r] < arr[smallest])
        smallest = r;
        
    if(smallest != i)
    {
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}

void buildHeap(int arr[], int n)
{
    int start = (n/2) -1;
    for(int i = start; i>=0; i--)
        heapify(arr,n,i);
}

void printHeap(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n = sizeof(arr)/sizeof(arr[0]);
    buildHeap(arr,n);
    printHeap(arr,n);
    return 0;
}
