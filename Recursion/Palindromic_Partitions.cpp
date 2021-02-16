#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int low, int high)
{
    while(low < high)
    {
        if(str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void solve(vector<vector<string>> &final, vector<string> &temp, int start, int n, string str)
{
    if(start >= n)
    {
        final.push_back(temp);
        return;
    }
    for(int i = start; i<n; i++)
    {
        if(isPalindrome(str, start, i))
        {
            temp.push_back(str.substr(start, i-start+1));
            solve(final, temp, i+1, n, str);
            temp.pop_back();
        }
    }
}

void allPartitions(string str)
{
    int n = str.size();
    vector<vector<string>> final;
    vector<string> temp;
    solve(final, temp,0,n,str);
    for(int i = 0; i<final.size(); i++)
    {
        for(int j = 0; j<final[i].size(); j++)
        {
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    string str;
    cin>>str;
    allPartitions(str);
}
