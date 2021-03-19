#include<bits/stdc++.h>
using namespace std;

void FrequencySort(int arr[], int n)
{
    priority_queue<pair<int,int>> maxh;
    unordered_map<int,int> umap;
     for(int i = 0; i<n; i++)
    {
        umap[arr[i]]++;
    }
    
    for(auto i = umap.begin(); i!= umap.end(); i++)
    {
        maxh.push({i->second, i->first});
    }
    
    while(maxh.size() > 0)
    {
        int freq = maxh.top().first;
        int element = maxh.top().second;
        for(int i = 1; i<= freq; i++)
            cout<<element<<" ";
        maxh.pop();
    }
}


int main()
{
    int n;
    cout<<"Size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Array: ";
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    FrequencySort(arr,n);
}
