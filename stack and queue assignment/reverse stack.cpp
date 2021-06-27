#include <iostream>
#include<stack>

using namespace std;
void reversestack(stack<int>&s1,stack<int>&s2)
{
    int len=s1.size();
    for(int i=0;i<len;i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1=s2;
    
}
int main()
{
    stack<int>s1,s2;
    int size;
    cin>>size;
    int element;
    for(int i=0;i<size;i++)
    {
        cin>>element;
        s1.push(element);
        
    }
    reversestack(s1,s2);
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }

    return 0;
}