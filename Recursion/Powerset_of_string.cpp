#include <bits/stdc++.h>
using namespace std;

void subset(string i, string o)
{
    if(i.length() == 0)
    {
        cout<<"{"<<o<<"}"<<" ";
        return;
    }
    
    string op1 = o;
    string op2 = o;
    op2.push_back(i[0]);
    i.erase(i.begin());
    subset(i,op1);
    subset(i, op2);
    return;
}


int main()
{
    string str;
    cin>>str;
    string o = "";
    subset(str,o);
}
