#include<bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int i = 0; i<nums.size(); i++)
            umap[nums[i]]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        for(auto x : umap)
        {
            p.push({x.second, -x.first});
        }

        int freq = 0, a = 0;
        while(!p.empty())
        {
            freq = p.top().first;
            a = -p.top().second;
            while(freq--)
                ans.push_back(a);
            p.pop();
        }
        return ans;
    }
    
int main()
{
    vector<int> a = {1,1,2,2,2,3};
    vector<int> b = {2,3,1,3,2};
    vector<int> ans1, ans2;
    ans1 = frequencySort(a);
    ans2 = frequencySort(b);
    for(int i = 0; i<ans1.size(); i++)
        cout<<ans1[i]<<" ";
    cout<<endl;
    for(int i = 0; i<ans2.size(); i++)
        cout<<ans2[i]<<" ";
    cout<<endl;
}