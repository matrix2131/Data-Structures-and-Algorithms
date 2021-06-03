/* Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
*/

#include<bits/stdc++.h>
using namespace std;

int countVowelStrings(int n) {
        int dp[n+1][6];
        memset(dp,0,sizeof(dp));
        dp[1][1] = 1;
        
        for(int i = 1; i<n+1; i++)
        {
            for(int j = 1; j<6; j++)
            {
                if(i == 1)
                    dp[i][j] = dp[i][j-1] + 1;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[n][5];
    }
    
int main()
{
    int n1 = 2;
    int n2 = 33;
    cout<<countVowelStrings(n1)<<endl;
    cout<<countVowelStrings(n2)<<endl;
}