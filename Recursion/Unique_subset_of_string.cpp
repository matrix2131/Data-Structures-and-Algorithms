#include <bits/stdc++.h>
using namespace std;

void subset(string i, string o, unordered_map<string, int> &umap)
{
    if(i.length() == 0)
    {
        umap.insert(make_pair(o,1));
        return;
    }

    string op1 = o;
    string op2 = o;
    op2.push_back(i[0]);
    i.erase(i.begin());
    subset(i,op1,umap);
    subset(i, op2,umap);
    return;
}


int main()
{
    unordered_map<string, int> umap;
    string str;
    cin>>str;
    string o = "";
    subset(str,o,umap);
    for(auto it = umap.begin(); it != umap.end(); it++)
    {
        cout<<"{"<<it->first<<"}"<<" ";
    }
}

