#include <iostream>
#include<unordered_map>
using namespace std;
int longestsubsetzerosum(int* arr,int n)
{
    int length=0;
    int sum=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0 && length==0)
        {
            length=1;
        }
        if(sum==0)
        {
            length=i+1;
        }
        if(m.count(sum)>0)
        {
            length=max(length,i-m[sum]);
        }
        else
        {
            m[sum]=i;
        }
        
    }
    return length;
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
    cout<<"longest subset sum: "<<longestsubsetzerosum(arr,n);
    
    
}