
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
node*insertnode(node* head,int i,int data)
{
   
    if(head==NULL)
    {
        return NULL;
    }
   node* newnode=new node(data);
    if(i==0)
    {
        newnode->next=head;
        head=newnode;
        return head;
        
    }
    if(i==1)
    {
        node* temp=head;
        newnode->next=head->next;
        head->next=newnode;
        return head;
    }
    node* curr=insertnode(head->next,i-1,data);
    return head;
}


int main()
{
  
node* head=create();
print(head);
head=insertnode(head,2,40);
cout<<endl;
print(head);
    
}