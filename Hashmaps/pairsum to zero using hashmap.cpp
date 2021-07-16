
#include <iostream>
#include<map>
using namespace std;
void pairsum(int* input,int n)
{
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        m[input[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(m[-input[i]]>0)
        {
            int x=m[-input[i]];
            while(x>0)
            {
                if(input[i]>-input[i])
                {
                    cout<<-input[i]<<" "<<input[i]<<endl;
                    
                }
                else
                {
                  cout<<input[i]<<" "<<-input[i]<<endl;    
                }
                x--;
            }
            m[input[i]]--;
        }
    }
    
}
int main()
{
    int n,arr[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    pairsum(arr,n);
}