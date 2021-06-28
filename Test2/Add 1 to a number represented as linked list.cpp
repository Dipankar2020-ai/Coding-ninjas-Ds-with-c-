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
node* reverse(node* head)
{
   
    if(head==NULL|| head->next==NULL)
    {
      return head;
    }
    node* smallans=reverse(head->next);
    node* tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallans;
   
    
}
node* create()
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
        
        tail->next=newnode;
        tail=tail->next;
            
        
        cin>>data;
        
    }
    return head;

}
void print(node* temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
        
    }
}
node* addone(node* head)
{
    head=reverse(head);
    bool f=true;
    node* curr=head;
    while(curr!=NULL && f==true)
    {
        if(curr->next==NULL && curr->data==9)
        {
            curr->data=1;
            node* temp=new node(0);
            temp->next=head;
            head=temp;
            curr=curr->next;
            
        }
        else if(curr->data==9)
        {
            curr->data=0;
            curr=curr->next;
        }
        else
        {
            curr->data=curr->data+1;
            curr=curr->next;
            f=false;
        }
    }
    head=reverse(head);
    return head;
}

int main()
{
    node* head=create();
    print(head);
    cout<<endl;
    head=addone(head);
    print(head);
   

    return 0;
}