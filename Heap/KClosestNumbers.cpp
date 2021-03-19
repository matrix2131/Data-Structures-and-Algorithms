#include<bits/stdc++.h>
using namespace std;

void kClosestNumbers(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> maxh;
    for(int i = 0; i<n; i++)
    {
        maxh.push({abs(arr[i]-x),arr[i]});
        if(maxh.size()>k)
            maxh.pop();
    }
    
    while(maxh.size()>0)
    {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
}


int main()
{
    int n,k,x;
    cout<<"Size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Array: ";
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"k and x: ";
    cin>>k>>x;
    kClosestNumbers(arr,n,k,x);
}
