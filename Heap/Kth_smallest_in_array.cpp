#include<bits/stdc++.h>
using namespace std;

int KthSmallest(int arr[], int n, int K)
{
    priority_queue<int> maxh;
    for(int i = 0; i<n; i++)
    {
        maxh.push(arr[i]);
        if(maxh.size() > K)
            maxh.pop();
    }
    
    return maxh.top();
}

int main()
{
    int n,K;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    cin>>K;
    
    cout<<KthSmallest(arr,n,K)<<endl;
}
