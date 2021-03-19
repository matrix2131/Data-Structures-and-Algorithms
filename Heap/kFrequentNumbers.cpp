#include<bits/stdc++.h>
using namespace std;

void kFrequentNumbers(int arr[], int n, int k)
{
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> >minh;
    unordered_map<int,int> umap;
     for(int i = 0; i<n; i++)
    {
        umap[arr[i]]++;
    }
    
    for(auto i = umap.begin(); i!= umap.end(); i++)
    {
        minh.push({i->second, i->first});
        if(minh.size() > k)
            minh.pop();
    }
    
    while(minh.size() > 0)
    {
        cout<<minh.top().second<<" ";
        minh.pop();
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
    cout<<"k: ";
    cin>>k;
    kFrequentNumbers(arr,n,k);
}
