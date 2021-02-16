#include<bits/stdc++.h>
using namespace std;

void solve(char c[], int k, int n, string op)
{
    if(op.length() == k)
    {
        cout<<op<<"   ";
        return;
    }
    string opp[n];
    for(int i = 0; i<n; i++)
    {
        opp[i] = op;
        opp[i].push_back(c[i]);
        solve(c,k,n,opp[i]);
    }
    return;
}

int main()
{
    int n,k;
    cout<<"Enter no. of characters: ";
    cin>>n;
    char ch[n];
    cout<<"Enter the characters: ";
    for(int i = 0; i<n; i++)
    {
        cin>>ch[i];
    }
    cout<<"Enter max length: ";
    cin>>k;
    string op = "";
    cout<<"Output: ";
    solve(ch,k,n,op);
}
