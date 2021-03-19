#include<bits/stdc++.h>
using namespace std;

char tree[10];

int root(char key)
{
    if(tree[0] != '\0')
        cout<<"Tree already has a root!!";
    else
        tree[0] = key;
    return 0;
}

int insert_left(char key, int parent)
{
    if(tree[2*parent + 1] != '\0')
        cout<<"Already Occupied!!";
    else
        tree[parent*2 + 1] = key;
    return 0;
}

int insert_right(char key, int parent)
{
    if(tree[2*parent + 2] != '\0')
        cout<<"Already Occupied!!";
    else
        tree[parent*2 + 2] = key;
    return 0;
}

int display()
{
    for(int i = 0; i<10; i++)
    {
        if(tree[i]!= '\0')
            cout<<tree[i]<<" ";
        else
            cout<<"-"<<" ";
    }
    return 0;
}


int main()
{
    root('A');
    insert_left('B',0);
    insert_right('C',0);
    insert_left('D',1);
    insert_right('E',1);
    insert_right('F',2);
    display();
    return 0;
}
