#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int> umap;
    vector<int> v;
    int n,k,s = 0;
    cin>>n;
    cin>>k;
    s = n/k;
    int a[n];
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        umap[a[i]]++;
    }
    
    unordered_map<int,int> :: iterator it;
    for(it = umap.begin(); it != umap.end(); it++)
    {
        if(it->second > s)
            v.push_back(it->first);
    }
    for(int i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
