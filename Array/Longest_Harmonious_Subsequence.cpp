#include<bits/stdc++.h>
using namespace std;

int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> umap;
        for(int i = 0; i<nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        
        for(auto itr : umap)
        {
            if(umap.find(itr.first+1) != umap.end())
                ans = max(ans, umap[itr.first+1] + itr.second);
        }
        return ans;
}

int main()
{
    vector<int> v{1,3,2,2,5,2,3,7};
    int ans = findLHS(v);
    cout<<ans<<endl;
}
