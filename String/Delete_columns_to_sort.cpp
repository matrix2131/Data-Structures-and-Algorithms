/* You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:

abc
bce
cae
You want to delete the columns that are not sorted lexicographically. 
In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted 
while column 1 ('b', 'c', 'a') is not, so you would delete column 1. */

#include<bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int i = 0; i<strs[0].size(); i++)
        {
            for(int j = 0; j<strs.size()-1; j++)
            {
                if(strs[j][i] > strs[j+1][i])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }

int main()
{
    vector<string> v1 = {"cba","daf","ghi"};
    vector<string> v2 = {"a","b"};
    vector<string> v3 = {"zyx","wvu","tsr"};
    cout<<"Case 1: "<<minDeletionSize(v1)<<endl;
    cout<<"Case 2: "<<minDeletionSize(v2)<<endl;
    cout<<"Case 3: "<<minDeletionSize(v3)<<endl;
}