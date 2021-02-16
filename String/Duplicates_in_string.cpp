#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> umap;
    string s;
    cin>>s;
    for(int i = 0; i<s.size(); i++)
    {
        umap[s[i]]++;
    }
    
    unordered_map<char, int> :: iterator itr;
    
    for(itr = umap.begin(); itr!=umap.end(); itr++)
    {
        if(itr->second > 1)
        {
            cout<<itr->first<<" ";
        }
    }
}
