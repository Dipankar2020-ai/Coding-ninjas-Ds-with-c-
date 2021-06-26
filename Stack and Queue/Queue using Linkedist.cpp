#include <iostream>
using namespace std;
template<typename T>
class node
{
    public:
    T data;
    node<T>* next;
    node(T data)
    {
        this->data=data;
        next=NULL;
        
    }
    
};
template<typename T>
class queue
{
    public:
    int size;
    node<T>* head;
    node<T>* tail;
    queue()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return (size==0);
    }
    void enqueue(T data)
    {
        node<T>* newnode=new node<T>(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            size=1;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
            size++;
        }
        
    }
    T front()
    {
        if(head!=NULL)
        {
        T ans=head->data;
        return ans;
        }
    }
    void deque()
    {
       if(head!=NULL)
        {
        T ans=head->data;
        node<T>* temp=head;
        head=head->next;
        temp->next=NULL;
        size--;
        //return ans;
        }
        
    }
    
    
    
};
int main() {
    // Write C++ code here
    queue<int>q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout<<q.front()<<endl;
    q.deque();
    cout<<q.front()<<endl;
    q.deque();
    cout<<q.front()<<endl;
    cout<<q.getsize()<<endl;
    q.deque();
    q.deque();
    cout<<q.isempty()<<endl;
     
    

    return 0;
}