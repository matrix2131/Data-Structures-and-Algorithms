#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int S = accumulate(arr, arr+n,0);
    
    bool dp[n+1][S+1];
    
    for(int i = 0; i<n+1; i++)
    {
        for(int j = 0; j<S+1; j++)
        {
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }
    
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j< S+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    vector<int> possible;
    int mid = (S/2) + 1;
    for(int j = 0; j<mid; j++)
    {
        if(dp[n][j])
            possible.push_back(j);
    }
    
    int s1 = *max_element(possible.begin(), possible.end());
    int ans = S - (2*s1);
    cout<<"Minimum difference between subarrays is: "<<ans<<endl;
}