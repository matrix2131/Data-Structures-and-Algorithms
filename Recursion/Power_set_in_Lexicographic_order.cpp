#include<bits/stdc++.h>
using namespace std;

void solve(string str,int n, int index = -1, string curr = "")
{
    if(index == n)
        return;
        
    cout<<curr<<" ";
    for(int i = index+1; i<n; i++)
    {
        curr += str[i];
        solve(str,n,i,curr);
        curr = curr.erase(curr.size()-1);
    }
}


int main()
{
    string str;
    cin>>str;
    sort(str.begin(), str.end());
    solve(str,str.size());
}
