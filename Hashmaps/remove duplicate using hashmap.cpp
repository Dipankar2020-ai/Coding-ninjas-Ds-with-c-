
#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> removeduplicate(int * a,int size)
{  
    vector<int> output;
    unordered_map<int ,bool>ourmap;
    for(int i=0;i<size;i++)
    {
          if(ourmap.count(a[i])>0)
          {
              continue;
          }
          ourmap[a[i]]=true;
          output.push_back(a[i]);
    }
    return output;
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
    vector<int> output=removeduplicate(a,n);
     for(int i=0;i<output.size();i++)
    {
       cout<<output.at(i)<<" ";
    }
}