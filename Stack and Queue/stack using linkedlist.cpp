#include <iostream>

using namespace std;
class node
{
     public:
    int data;
    node* next;
   
    node(int data)
    {
        this->data=data;
    }
};
class stack1
{
    node* head;
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
            return 0;
        }
        else
        {
            return 1;
        }
    }
    void push(int value)
    {
        node* newnode=new node(value);
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
    int pop()
    {
        int ans;
        if(head!=NULL)
        {
             ans=head->data;
            head=head->next;
            size--;
        }
        return ans;
    }
    int top()
    {
        return head->data;
        
    }
    
};

int main()
{
    stack1 s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.top()<<endl;
    
    

    return 0;
}