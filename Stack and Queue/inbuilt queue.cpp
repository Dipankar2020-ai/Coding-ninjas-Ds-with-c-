#include <iostream>

#include<queue>  //header file
using namespace std;

int main() {
    // Write C++ code here
    queue<int>q;
    q.push(10);//Enqueur
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<q.front()<<endl;
    q.pop();// dequeue
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    while(!q.empty())
    {
        q.pop();
    }
  cout<<q.empty()<<endl;

    

    return 0;
}