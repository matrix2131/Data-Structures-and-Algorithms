#include<bits/stdc++.h>
using namespace std;

void kSorted(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    for(int i = 0; i<n; i++)
    {
        minh.push(arr[i]);
        if(minh.size()>k)
        {
            cout<<minh.top()<<" ";
            minh.pop();
        }
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
    kSorted(arr,n,k);
}
