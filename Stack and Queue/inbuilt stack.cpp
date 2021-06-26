
#include <iostream>
#include<stack> //ibulit stack header file

using namespace std;

int main()
{
   stack<int>s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   cout<<s.top()<<endl;
   s.pop();//here pop function's return type is void
   
   cout<<s.top()<<endl;
   cout<<s.size()<<endl;
   cout<<s.empty()<<endl; // here isempty() function named as empty()
   s.pop();
   
    cout<<s.top()<<endl;
   
}
