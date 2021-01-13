#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int maxLength(int A[], int n);

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int i = 0; i<N; i++)
		
			cin>>A[i];
		cout<<maxLength(A, N)<<endl;
	}
}

// While finding the sum in the array, if a particular sum is repeated again, that means the sum from previous place where the same sum occured to the present position, the sum was zero. 

int maxLength(int A[], int n)
{
	int sum = 0, ind = 0;
	unordered_map <int, int> umap;
	for(int i = 0; i<n; i++)
	{
		sum += A[i];
		if(sum == 0)
			ind = i+1;  // i + 1 because the index in started from 0
		if(umap.find(sum) != umap.end())
		       ind = max((i - umap.find(sum)->second), ind);
		umap.insert(make_pair(sum, i));
	}
return ind;
}
