#include <iostream>
#include<unordered_map>
using namespace std;
void pairwithdifferencek(int* arr,int n,int k)
{  int total=0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        int key=arr[i];
        if(k==0)
        {
            int a=m[key];
            int count=a*(a-1)/2;
            for(int j=0;j<count;j++)
            {
                total++;
                cout<<key<<" "<<key<<endl;
            }
        }
        else
        {
            int a=key+k;
            int b=key-k;
            int count=m[key];
            int count1=m[a];
            int count2=m[b];
            for(int j=0;j<count*count1;j++)
            {
                cout<<min(a,key)<<" "<<max(a,key)<<endl;
                total++;
            }
            for(int j=0;j<count*count2;j++)
            {
                cout<<min(b,key)<<" "<<max(b,key)<<endl;
                total++;
            }
        }
     m.erase(key);
    }
    cout<<"Number of pairs : "<<total<<endl;
  
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
   int k;
   cin>>k;
   pairwithdifferencek(arr,n,k);

    return 0;
}