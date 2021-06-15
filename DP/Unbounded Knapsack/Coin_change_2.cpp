#include <bits/stdc++.h>
using namespace std;
#define N 3
#define V 5

int dp[N+1][V+1];
int CoinChange(int val, int coin[], int n)
{
    for(int i = 0; i<n+1; i++)
    {
        for(int j = 0; j<val+1; j++)
        {
            if(i == 0)
                dp[i][j] = INT_MAX-1;
            if(j == 0)
                dp[i][j] = 0;
        }
    }
    
    for(int j = 1; j<val+1; j++)
    {
        if(j%coin[0] == 0)
            dp[1][j] = j/coin[0];
        else
            dp[1][j] = INT_MAX-1;
    }
        
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<val+1; j++)
        {
            if(coin[i-1] <= j)
                dp[i][j] = min(1 + dp[i][j-coin[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][val];
}

// Driver code
int main()
{
	int coin[] = { 1,2,3};
	int val = 5;
	int len = sizeof(coin) / sizeof(coin[0]);
	cout << "Minimum no. of coins: "<<CoinChange(val, coin,  len);
	return 0;
}