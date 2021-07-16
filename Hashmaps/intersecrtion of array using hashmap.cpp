#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void intersection(int *input1,int *input2,int size1,int size2)
{
    unordered_map<int,int>map;
    for(int i=0;i<size1;i++)
    {
        map[input1[i]]++;
    }
    for(int i=0;i<size2;i++)
    {
        if(map[input2[i]]>0)
        {
            cout<<input2[i]<<" ";
            map[input2[i]]--;
        }
    }
}

int main()
{
    int a[100],b[100];
    int t;
    cin>>t;
 while(t--)  
 {
    int n;
    int m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
  intersection(a,b,n,m);
 }
}