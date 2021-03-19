#include<bits/stdc++.h>
using namespace std;

void ConnectRopes(int arr[], int n)
{
    int cost = 0;
    priority_queue <int, vector<int>, greater<int>> minh;
    for(int i = 0; i<n; i++)
    {
        minh.push(arr[i]);
    }
    
    while(minh.size() >= 2)
    {
        int r1 = minh.top();
        minh.pop();
        int r2 = minh.top();
        minh.pop();
        cost += r1 + r2;
        minh.push(r1+r2);
    }
    cout<<"Minimum Cost: "<<cost<<endl;
}

int main()
{
    cout<<"No. of ropes: ";
    int n;
    cin>>n;
    cout<<"Lengths of ropes: ";
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    ConnectRopes(arr,n);
}
