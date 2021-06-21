#include <iostream>

using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
node* creation()
{
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;
    while(data!=-1)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
           
        }
        cin>>data;
    }
    return head;
}
void print(node* temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
int length(node* temp)
{
    int count=0;
    while(temp!=NULL)
    {
        count++;
        
        temp=temp->next;
    }
    return count;
    
}

int main()
{
    node* head=creation();
    print(head);
    cout<<endl;
    cout<<"Length of the linked list: "<<length(head);
}