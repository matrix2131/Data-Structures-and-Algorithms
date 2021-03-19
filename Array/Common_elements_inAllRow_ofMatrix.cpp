#include<bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

// Time Complexity ---> O(mn)

void solve(int a[M][N])
{
    unordered_map<int, int> umap;
    
    for(int j = 0; j<N; j++)
    {
        umap[a[0][j]]++;
    }
    
    for(int i = 1; i<M; i++)
    {
        for(int j = 0; j<N; j++)
        {
            if(umap[a[i][j]] == i)
            {
                umap[a[i][j]] = i + 1;
                
                if(i == M-1)
                    cout<<a[i][j]<<" ";
            }
        }
    }
}


int main()
{
    int a[M][N] = {
        {1,2,3,4,1},
        {2,1,6,7,8},
        {9,2,1,4,5},
        {5,2,3,4,1},
    };
    solve(a);
    return 0;
}
