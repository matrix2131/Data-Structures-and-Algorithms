#include<bits/stdc++.h>
using namespace std;

// Time Complexity ----> O(n)
// Space Complexity ----> O(n)

int numberOfArithmeticSlices(vector<int>& A) 
{
    int ans = 0;
    int n = A.size();
    vector<int> d(n);
    for(int i = 2; i<n; i++)
    {
        if(A[i]-A[i-1] == A[i-1]-A[i-2])
        {
            d[i] = 1 + d[i-1];
            ans += d[i];
        }
    }
    return ans;
}

int main()
{
   vector<int> v = {1,2,3,4};
   cout <<numberOfArithmeticSlices(v)<<endl;
}
