#include<bits/stdc++.h>
using namespace std;


class stock{
	public:
	vector<vector<int> > stockBuySell(vector<int> a, int n){
   	vector<vector<int>> ans;
   	int lower = 0, upper = 0;
   	int i = 0;
    	while(i<n)
    	{
        	if(a[i]>a[i+1] || i == n-1 || ((a[i] == a[i+1]) && (upper == 0)))
        	{
            	if(upper!=0)
            	{
                	vector<int> v;
                	v.push_back(lower);
	                v.push_back(i);
        	        ans.push_back(v);
                	upper = 0;
	            }
        	lower = i+1;
	        }
        	else
	        {
	            upper = max(upper,a[i+1]);
        	}
	        i++;
	    }	
	    return ans;
    }
};



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>A(n);
		for(int i = 0; i<n; i++)
		{
			cin>>A[i];
		}

	stock s;
	vector<vector<int>> ans = s.stockBuySell(A, n);
	if(ans.size() == 0)
		cout<<"No Profit";
	else
	{
		for(int i = 0; i<ans.size(); i++)
		{
			cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<")";
		}
	cout<<endl;
	}
	return 0;
	}
}
