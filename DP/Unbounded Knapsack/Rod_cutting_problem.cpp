/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of 
size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if the length of the rod is 8 and the values of different pieces are given as the following, 
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 
*/

#include <bits/stdc++.h>
using namespace std;
#define s 8
#define l 8

int dp[s+1][l+1];
int rodCutting(int L, int ln[], int price[], int n)
{
    for(int i = 0; i<n+1; i++)
        dp[i][0] = 0;
    for(int j = 0; j<L+1; j++)
        dp[0][j] = 0;
        
    for(int i = 1; i<n+1; i++)
    {
        for(int j = 1; j<L+1; j++)
        {
            if(ln[i-1] <= j)
                dp[i][j] = max(price[i-1]+dp[i][j-ln[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][L];
}

// Driver code
int main()
{
	int price[] = { 1,5,8,9,10,17,17,20};
	int ln[] = { 1,2,3,4,5,6,7,8};
	int L = 8;
	int len = sizeof(price) / sizeof(price[0]);
	cout << rodCutting(L, ln, price, len);
	return 0;
}