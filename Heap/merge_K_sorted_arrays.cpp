#include<bits/stdc++.h>
using namespace std;
#define N 105

// Time complexity ---> O(k*k*(logk))
// Space complexity ---> O(k*k)

int *mergeKArrays(int arr[][N], int k)
{
    int l = 0;
    int *ans = new int[k*k];
    priority_queue<int, vector<int>, greater<int>> m;
    for(int i = 0; i<k; i++)
    {
        for(int j = 0; j<k; j++)
        {
            m.push(arr[i][j]);
        }
    }
        while(m.size() > 0)
        {
            ans[l] = m.top();
            m.pop();
            l++;
        }
    return ans;
}

int main()
{
    int k = 4;
    int arr[N][N] = {{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}};
    int *output = mergeKArrays(arr,k);
    for(int i = 0; i<(k*k); i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
}
