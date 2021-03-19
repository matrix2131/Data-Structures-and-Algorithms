#include<bits/stdc++.h>
using namespace std;

int KthSmallest(int arr[], int n, int k)
{
    priority_queue <int> maxh;
    for(int i = 0; i<n; i++)
    {
        maxh.push(arr[i]);
        if(maxh.size() > k)
            maxh.pop();
    }
    
    return maxh.top();
}


// Sum between k1th and k2th smallest elements.
int main()
{
    cout<<"Size: ";
    int n,k1,k2;
    cin>>n;
    cout<<"Array: ";
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"k1 and k2: ";
    cin>>k1>>k2;
    
    int first = KthSmallest(arr,n,k1);
    int second = KthSmallest(arr,n,k2);
    
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] > first && arr[i] < second)
            sum += arr[i];
    }
    
    cout<<"Sum :"<<sum<<endl;
}
