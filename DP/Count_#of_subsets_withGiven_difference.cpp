#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1,1,2,3};
    int diff = 1;
    int n = sizeof(arr)/sizeof(arr[0]);
    int S = accumulate(arr, arr+n,0);
    
    int s1 = (S + diff)/2;
    
    int dp[n+1][s1+1];
    
    for(int i = 0; i<n+1; i++)
    {
        for(int j = 0; j<s1+1; j++)
        {
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }
    
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j< s1+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    cout<<dp[n][s1]<<endl;
}