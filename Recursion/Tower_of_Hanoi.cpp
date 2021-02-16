#include<bits/stdc++.h>
using namespace std;

void solve(int n, int s, int d, int h)
{
    if(n == 1)
    {
        cout<<"Move disc "<< n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    solve(n-1,s,h,d);
    cout<<"Move disc "<<n<<" from "<<s<<" to "<<d<<endl;
    solve(n-1,h,d,s);
}

int main()
{
    int n;
    cin>>n;
    int s = 1;
    int h = 2;
    int d = 3;
    solve(n,s,d,h);
    
}
