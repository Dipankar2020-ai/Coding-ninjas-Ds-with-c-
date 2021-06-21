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
        next=NULL;
    }
};
node* create()
{
    int data;
    cin>>data;
    node* head=NULL;
    while(data!=-1)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            
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

node* insertnode(node* head,int i, int data)
{
    node* newnode=new node(data);
    int count=0;
    if(i==0)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    else
    {
        node* temp=head;
        while(temp!=NULL && count<i-1)
        {
            temp=temp->next;
            count++;
        }
        if(temp!=NULL)
        {
            node*a=temp->next;
            temp->next=newnode;
            newnode->next=a;
            
        }
        return head;
        
    }
}
node* deletenode(node* head,int i)
{
    node*temp=head;
    int count=0;
    if(i==0)
    {
        head=temp->next;
        temp->next=NULL;
        return head;
    }
    while(temp!=NULL && count<i-1)
    {
        temp=temp->next;
        count++;
        
    }
    node*a=temp->next;
    if(temp!=NULL)
    {
    
       temp->next=a->next;
       a->next=NULL;
       
    }
    return head;
}
int  length(node* head)
{
    
    if(head==NULL)
    {
        return 0;
        
    }
    else
    { 
        head=head->next;
        return 1+length(head);
    }
}

int main()
{
    node* head=create();
    print(head);
    cout<<endl;
    
    head=insertnode(head,2,80);
    
    print(head);
    cout<<endl;
    head=deletenode(head,0);
   
    print(head);
    cout<<endl;
    cout<<length(head);

    
    

    return 0;
}