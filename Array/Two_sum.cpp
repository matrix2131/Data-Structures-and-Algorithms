#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> a;
        map<int,int> m;
        for(int i = 0; i<numbers.size(); i++)
        {
            m[numbers[i]] = i+1;
        }
        
        for(int i = 0; i<numbers.size(); i++)
        {
            if(m[abs(target-numbers[i])])
            {
                a.push_back(i+1);
                a.push_back(m[abs(target-numbers[i])]);
                break;
            }
        }
        return a;        
    }
    
int main()
{
    vector<int> v = {2,3,4};
    int target = 6;
    vector<int> ans;
    ans = twoSum(v,target);
    for(int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}