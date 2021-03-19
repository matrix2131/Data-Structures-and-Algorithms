#include<bits/stdc++.h>
usinh namespace std;

class Solution {
public:
    bool static compare(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),compare);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i<intervals.size(); i++)
        {
            if(ans[ans.size()-1][1] >= intervals[i][0])
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};


