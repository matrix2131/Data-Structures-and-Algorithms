#include<bits/stdc++.h>
using namespace std;

void solve(string op, int k)
{
    if(k == 0)
    {
        cout<<op<<" ";
        return;
    }
    
    string opp = op;
    opp.push_back('0');
    solve(opp, k-1);
    if(op[op.size()-1] == '0' || op.empty())
    {
        string opp1 = op;
        opp1.push_back('1');
        solve(opp1,k-1);
    }
    
    return;
}

int main()
{
    int k;
    cin>>k;
    string op = "";
    solve(op,k);
    
    return 0;
}
