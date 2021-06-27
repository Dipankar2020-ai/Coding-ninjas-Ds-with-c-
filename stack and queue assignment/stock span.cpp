#include <iostream>
using namespace std;
#include <stack>
void calculatespan(int price[],int S[],int n)
{
    
    /
    stack<int> st;
    st.push(0);
 
    S[0] = 1;
 
   
    for (int i = 1; i < n; i++) {
       
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();
 
        /
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());
 
        // Push this element to stack
        st.push(i);
}
 for(int i=0;i<n;i++)
   {
       cout<<S[i]<<" ";
   }
}

int main() {
   int i,n,arr[100];
  
   cin>>n;
   int span[n];
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   calculatespan(arr,span,n);
  

}