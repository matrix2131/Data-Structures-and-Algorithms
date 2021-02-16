#include<bits/stdc++.h>
using namespace std;

void solve(string ip, string op, int start, int &count)
{
    if(op[0] == op[op.size()-1]  && !op.empty())
    {
        cout<<op<<" ";
	count++;
    }
    
    if(start == ip.size())
        return;
    
    if(op == "")
    {
        string opp[ip.size()];
        for(int i = 0; i<ip.size(); i++)
        {
            opp[i].push_back(ip[i]);
            solve(ip,opp[i],i+1,count);
        }
    }
    
    else
    {
        string op1 = op;
        op1.push_back(ip[start]);
        solve(ip, op1, start+1,count);
    }
    return;
}

int main()
{
    string ip;
    cin>>ip;
    int count = 0;
    string op = "";
    solve(ip,op,0,count);
    cout<<"\nTotal: "<<count<<endl;
    return 0;
}
