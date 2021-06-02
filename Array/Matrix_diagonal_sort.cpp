#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> m;
        int n = mat.size();
        int s = mat[0].size();
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<s; j++)
            {
                m[i-j].push_back(mat[i][j]);
                sort(m[i-j].begin(), m[i-j].end());
            }
        }
        
        for(int i =0; i<n; i++)
        {
            for(int j = 0; j<s; j++)
            {
                mat[i][j] = m[i-j].front();
                m[i-j].erase(m[i-j].begin());
            }
        }
        return mat;
    }
    
int main()
{
    vector<vector<int>> mat1 = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    vector<vector<int>> mat2 = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
    vector<vector<int>> ans1;
    vector<vector<int>> ans2;
    ans1 = diagonalSort(mat1);
    ans2 = diagonalSort(mat2);
    for(int i = 0; i<ans1.size(); i++)
    {
        for(int j = 0; j<ans1[0].size(); j++)
        {
            cout<<mat1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i<ans2.size(); i++)
    {
        for(int j = 0; j<ans2[0].size(); j++)
        {
            cout<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }
}