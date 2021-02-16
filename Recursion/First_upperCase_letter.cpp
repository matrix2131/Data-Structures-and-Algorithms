#include<bits/stdc++.h>
using namespace std;

void solve(string str, int start = 0)
{
    if(isupper(str[start]))
    {
        cout<<str[start]<<endl;
        return;
    }
    if(str[start] == '\0')
    {
        cout<<"No Upper case Letter found!!"<<endl;
        return;
    }
    solve(str, start+1);
}

int main()
{
    string str;
    cin>>str;
    solve(str);
}
