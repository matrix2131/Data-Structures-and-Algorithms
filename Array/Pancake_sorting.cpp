/* Given an array of integers arr, sort the array by performing a series of pancake flips.

In one pancake flip we do the following steps:

    1.Choose an integer k where 1 <= k <= arr.length.
    2.Reverse the sub-array arr[0...k-1] (0-indexed).

For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.

Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int j = arr.size()-1;
        while(j >= 0)
        {
            int a = *max_element(arr.begin(), arr.begin()+j+1);
            int x = max_element(arr.begin(), arr.begin()+j+1) - arr.begin();
            if(arr[j] == a)
                j--;
            else
            {
                if(x == 0)
                {
                    ans.push_back(j+1);
                    reverse(arr.begin(), arr.begin()+j+1);
                    j--;
                }
                else
                {
                    ans.push_back(x+1);
                    reverse(arr.begin(), arr.begin()+x+1);
                    ans.push_back(j+1);
                    reverse(arr.begin(), arr.begin()+j+1);
                    j--;
                }
            }
        }
        return ans;
    }
    
int main()
{
    vector<int> arr = {3,2,4,1};
    vector<int> ans;
    ans = pancakeSort(arr);
    for(int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}