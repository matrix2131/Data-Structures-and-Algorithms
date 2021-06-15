/*
order and str are strings composed of lowercase letters. In order, no letter occurs more than once.

order was sorted in some custom order previously. We want to permute the characters of str so that they match the order 
that order was sorted. More specifically, if x occurs before y in order, then x should occur before y in the returned string.

Return any permutation of str (as a string) that satisfies this property.
*/

#include<bits/stdc++.h>
using namespace std;

string customSortString(string order, string str) {
        string ans = "";
        unordered_map<char, int> umap;
        for(int i = 0; i<str.size(); i++)
        {
            umap[str[i]]++;
        }
        
        for(int i = 0; i<order.size(); i++)
        {
            if(umap.find(order[i]) != umap.end())
            {
                while(umap[order[i]]--)
                    ans.push_back(order[i]);
                umap.erase(order[i]);
            }
        }
        
        for(auto x: umap)
        {
            while(x.second--)
                ans.push_back(x.first);
        }
        return ans;
    }


// Method 2: USING COMPARE FUNCTION
/*string o;
// Compare function 

bool compare(char &c1, char &c2){
    unordered_map<char, int> umap;
    for(int i = 0; i<o.size(); i++)
        umap[o[i]] = i;
    
    return umap[c1] < umap[c2];

}

string customSortString(string order, string str) {
        o = order;
        
        sort(str.begin(),str.end(),compare);
        return str;
}
*/

int main()
{
    string order = "cba";
    string str = "abcd";
    cout<<customSortString(order, str)<<endl;
}
