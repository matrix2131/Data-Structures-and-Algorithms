/*
You are given an integer array coins representing coins of different denominations and an integer amount 
representing a total amount of money.

Return the number of combinations that make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.
*/


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
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }
        
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<val+1; j++)
        {
            if(coin[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i][j-coin[i-1]];
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
	cout << CoinChange(val, coin,  len);
	return 0;
}