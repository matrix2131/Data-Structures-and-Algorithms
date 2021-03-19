#include<bits/stdc++.h>
using namespace std;

long long maxProduct(int *arr, int n) {
	    long long minimum = arr[0];
	    long long maximum = arr[0];
	    long long result = arr[0];
	    
	    for(int i = 1; i<n; i++)
	    {
	        if(arr[i]<0)
	            swap(minimum, maximum);
	       long long x = arr[i];
	        minimum = min(x, x*minimum);
	        maximum = max(x, x*maximum);
	        
	        result = max(result, maximum);
	    }
	    return result;
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<maxProduct(arr,n)<<endl;
}
