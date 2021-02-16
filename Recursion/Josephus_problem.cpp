#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int k, int index, int &ans)
{
    if(v.size() == 1)
    {
        ans = v[0];
        return;
    }
    
    index = (index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,k,index,ans);
    return;
}

int main()
{
       int n,k;
        cin>>n>>k;
        k--;
        vector<int> v;
        int index = 0;
        int ans = -1;
        for(int i = 1; i<=n; i++)
        {
            v.push_back(i);
        }
        solve(v,k,index,ans);
        cout<<ans<<endl;
}
