
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
           
            //head->next=newnode;
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
int findnode(node* temp,int element,int pos)
{
    while(temp!=NULL)
    {
        if(temp->data==element)
        {
            return pos;
            
        }
        pos++;
        temp=temp->next;
    }
    return -1;
    
}

void print(node* temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int length(node*temp)
{
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
        
    }
    return count;
}

node* appendNfirst(node* temp,int m)
{
    int i=0;
    node* head=temp;
    while(i<m-1)
    {
        temp=temp->next;
        i++;
        
    }
    node* newnode=temp->next;
    temp->next=NULL;
    node* newnode1=newnode;
    while(newnode1->next!=NULL)
    {
        newnode1=newnode1->next;
    }
    newnode1->next=head;
    return newnode;
    
}


int main()
{
    
    node* head=create();
    //print(head);
    cout<<endl;
     int len=length(head);
       int pos;
      cin>>pos;
    int m=len-pos;
    cout<<m<<endl;
  
   
   
   
    head=appendNfirst(head,m);
    print(head);
    
    return 0;
}