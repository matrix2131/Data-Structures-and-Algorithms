#include<bits/stdc++.h>
using namespace std;

void solve(string str, int l, int h)
{
    if(l == h)
        cout<<str<<" ";
    
    for(int i = l; i<=h; i++)
    {
        swap(str[l], str[i]);
        solve(str, l+1, h);
        swap(str[l],str[i]);      // Backtracing
    }
}

int main()
{
    string ip;
    cin>>ip;
    int l = 0;
    int h = ip.size()-1;
    solve(ip,l,h);
}
