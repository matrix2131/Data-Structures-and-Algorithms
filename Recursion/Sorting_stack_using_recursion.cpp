#include<bits/stdc++.h>
using namespace std;

stack<int> s;
void sort_insert( int x)
{
        if(s.size() == 0 || s.top()<x)
        {
                s.push(x);
		return;
        }
        else
        {
                int a = s.top();
                s.pop();

                sort_insert(x);
                s.push(a);
        }
}


void reverse()
{
	if(s.size() > 0)
	{
                int x = s.top();
                s.pop();
                reverse();

                sort_insert(x);
	}
}


int main()
{
        s.push(3);
        s.push(5);
        s.push(0);
        s.push(8);
        s.push(1);
        s.push(6);
        reverse();
        while(!s.empty())
        {
                cout<<s.top()<<" ";
                s.pop();
	} 
}

