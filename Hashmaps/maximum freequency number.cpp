#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int highestfrequency(int* input,int n)
{
    unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    {
        map[input[i]]++;
    }
    int key=0;
    int value=0;
    for(int i=0;i<n;i++)
    {
        if(map[input[i]]>value)
        {
            key=input[i];
            value=map[input[i]];
        }
       
    }
     return key;
}

int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int output=highestfrequency(a,n);
     cout<<output;
}