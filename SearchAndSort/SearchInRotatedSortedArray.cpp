#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(logn)

int search(vector<int>& nums, int target) {
        int j = nums.size()-1;
        while(nums[j] < nums[0])
            j--;
        int l,h;
        if(target >= nums[0])
        {
            l = 0;
            h = j;
        }
        else
        {
            l = j+1;
            h = nums.size()-1;
        }
         
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0; // Answer = 4;
    cout<<search(arr, target)<<endl;
}
