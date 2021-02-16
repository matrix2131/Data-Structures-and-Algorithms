#include<bits/stdc++.h>
using namespace std;

stack<int> s;
void at_bottom(int x)
{
	if(s.size() == 0)
	{
		s.push(x);
	}
	else
	{
		int a = s.top();
		s.pop();

		at_bottom(x);
		s.push(a);
	}
}


void reverse()
{
	if(s.size()>0)
	{
		int x = s.top();
		s.pop();
		reverse();

		at_bottom(x);
	}
}


int main()
{
	s.push(6);
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	reverse();
	cout<<"Stack after reversing: ";
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
