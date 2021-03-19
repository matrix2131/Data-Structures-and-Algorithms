#include<bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for(int i = 0; i<n; i++)
    {
        minh.push(arr[i]);
        if(minh.size()>k)
            minh.pop();
    }
    
    while(minh.size()>0)
    {
        cout<<minh.top()<<" ";
        minh.pop();
    }
}


int main()
{
    int n,k;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    kLargest(arr,n,k);
}
