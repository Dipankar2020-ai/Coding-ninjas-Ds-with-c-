
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> longestsequence(int* arr,int n)
{
    vector<int>v;
    unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    {
        map[arr[i]]=1;
    }
    int max=0;
    int k=0;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        int j=0;
        if(map.count(x-1)>0)
        {
           continue;
        }
        while(map.count(x)>0)
        {
            j++;
            x++;
        }
        if(j>max)
        {
            max=j;
            k=arr[i];
        }
    }
    for(int i=0;i<max;i++)
    {
        v.push_back(k);
        k++;
    }
    return v;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>ans=longestsequence(arr,n);
    int len=ans.size();
       cout<<ans.at(0)<<" "<<ans.at(len-1);
    
    return 0;
}