
#include <iostream>
#include<queue>
using namespace std;
void reverse(queue<int>&q)
{
    if(q.empty())
    {
        return;
    }
    int a=q.front();
    q.pop();
    reverse(q);
    q.push(a);
    
    
}

int main()
{
    queue<int>q;
    int t;
    cin>>t;
    while(t--)
    {
        int size;
        cin>>size;
        int element;
        for(int i=0;i<size;i++)
        {
            cin>>element;
            q.push(element);
        }
        reverse(q);
        while(!q.empty())
        {
            cout<<q.front()<<" ";
            q.pop();
        }
    }
    

    return 0;
}