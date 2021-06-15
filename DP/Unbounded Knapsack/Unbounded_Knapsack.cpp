#include <bits/stdc++.h>
using namespace std;
#define s 4
#define w 8

int dp[s+1][w+1];
int knapSack(int W, int wt[], int val[], int n)
{
    for(int i = 0; i<n+1; i++)
        dp[i][0] = 0;
    for(int j = 0; j<W+1; j++)
        dp[0][j] = 0;
        
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<W+1; j++)
        {
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

// Driver code
int main()
{
	int val[] = { 10, 40, 50, 70};
	int wt[] = { 1,3,4,5};
	int W = 8;
	int len = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, len);
	return 0;
}