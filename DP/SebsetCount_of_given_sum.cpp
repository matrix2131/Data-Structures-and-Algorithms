#include<bits/stdc++.h>
using namespace std;
# define n 6
#define s 10

int dp[n+1][s+1];

int subsetCount(int arr[], int sum)
{
    for(int i = 0; i<n+1; i++)
    {
        for(int j = 0; j<sum+1; j++)
        {
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }
    
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<sum+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
    
int main()
{
    int arr[] = {2,3,5,6,8,10};
    int sum = 10;
    cout<<subsetCount(arr,sum);
}