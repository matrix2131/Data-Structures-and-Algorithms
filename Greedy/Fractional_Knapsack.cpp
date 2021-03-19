#include<bits/stdc++.h>
using namespace std;

// Time complexity ---. O(nlogn) ---> which is mostly taken by sorting.

struct Item{
    int value;
    int weight;
};



bool comparison(Item a, Item b)
{
    double aeach = (double)a.value/a.weight;
    double beach = (double)b.value/b.weight;
    return(aeach > beach);
}
// function to return fractionalweights
class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0.0;
        sort(arr, arr+n, comparison);
        for(int i = 0; i<n; i++)
        {
            if(arr[i].weight <= W)
            {
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            
            else
            {
                ans += arr[i].value * ((double)W/arr[i].weight);
                break;
            }
        }
        return ans;
    }
    
        
};

int main()
{
    int t;
    cin>>t;
    cout<<setprecision(2)<<fixed;
    while(t--)
    {
        int n,W;
        cin>>n>>W;
        Item arr[n];
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i].value>>arr[i].weight;
        }
        
        Solution ob;
        cout<<ob.fractionalKnapsack(W,arr,n)<<endl;
    }
    return 0;
}

/* Test case

1) Input ---> n = 3, W = 50;
              value = {60, 100 ,120}
              weight = {10,20,30}
*/
