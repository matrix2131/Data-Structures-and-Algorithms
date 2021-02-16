#include<bits/stdc++.h>
using namespace std;

int solve(int N, int K)
{
    if(N == 1 && K == 1)
        return 0;
    int mid = (pow(2,N-1))/2;
    if(K <= mid)
        return solve(N-1,K);
    else
        return !(solve(N-1,K-mid));

}



int main()
{
    int N,K;
    cin>>N>>K;
    int ans = solve(N,K);
    cout<<ans<<endl;

}
