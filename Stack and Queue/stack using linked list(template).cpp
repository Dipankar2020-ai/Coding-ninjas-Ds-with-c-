
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
    }
};
template<typename T>
class stack1
{
    node<T>* head;
    int size;
    public:
    stack1()
    {
        head=NULL;
        size=0;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        if(head==NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(T value)
    {
        node<T>* newnode=new node<T>(value);
        if(head==NULL)
        {
            head=newnode;
            cout<<head->data<<" ";
            size++;
        }
        else
        {
            newnode->next=head;
            head=newnode;
            cout<<head->data<<" ";

            size++;
        }
    }
    T pop()
    {
        int ans;
        if(head!=NULL)
        {
             ans=head->data;
             node<T>* temp=head;
             head=head->next;
             temp=NULL;
             size--;
             return ans;
        }
        return 0;
        
    }
    T top()
    {
        if(head!=NULL)
         {
          return head->data;
         }
         return 0;
        
    }
    
};

int main()
{
    stack1<char> s;
    s.push(97);
    s.push(98);
    s.push(99);
    s.push(100);
    cout<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.top()<<endl;
    
    

    return 0;
}