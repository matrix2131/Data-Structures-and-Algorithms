#include <iostream>
using namespace std;

// Union and intersection of Unsorted array.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int N,M;
	    cin>>N>>M;
	    int arr[100000], arr2[100000],hash[100000] = {0};
	    int uniun = 0, intersection = 0;
	    for(int i = 0; i<N; i++)
	    {
	        cin>>arr[i];
	        if(hash[arr[i]] == 0)
	        {
	            hash[arr[i]] = 1;
	            uniun++;
	        }
	    }
	    for(int i = 0; i<M; i++)
	    {
	        cin>>arr2[i];
            if(hash[arr2[i]] == 1)
                intersection++;
	        else if(hash[arr2[i]] == 0)
	        {
	            hash[arr2[i]] = 1;
	            uniun++;
	        }

	    }
	    cout<<"No of elements in union: "<<uniun<<endl;
        cout<<"No of elements in intersection: "<<intersection<<endl;

	}
	return 0;
}
