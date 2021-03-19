#include<bits/stdc++.h>
using namespace std;

void ClosestToOrigin(int arr[][2], int n, int k)
{
    priority_queue <pair<int, pair<int,int>>> maxh;
    for(int i = 0; i<n; i++)
    {
        maxh.push({pow(arr[i][0],2) + pow(arr[i][1],2), {arr[i][0], arr[i][1]} });
        if(maxh.size() > k)
            maxh.pop();
    }
    
    while(maxh.size() > 0)
    {
        pair<int, int> p;
        p = maxh.top().second;
        cout<<p.first<<" "<<p.second<<endl;
        maxh.pop();
    }
    
}

int main()
{
    cout<<"No. of Points: ";
    int n,k;
    cin>>n;
    cout<<"Points: ";
    int arr[n][2];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    cout<<"k : ";
    cin>>k;
    ClosestToOrigin(arr,n,k);
}
