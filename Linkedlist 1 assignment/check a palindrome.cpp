//C#include <iostream>

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
node* removeduplicate(node* head)
{
    node* t1=head;
    node* ans=t1;
    node* t2=head->next;
    while(t2!=NULL)
    {
        if(t1->data==t2->data)
        {
            t2=t2->next;
            
        }
        else
        {
            t1->next=t2;
            t1=t2;
            t2=t2->next;
        }
    }
     t1->next=t2;
     return ans;
     
    
}
node* reverse(node* head)
{
    if(head==NULL)
    {
        return head;
    }
    reverse(head->next);
    cout<<head->data<<" ";
}
bool checkpalindrome(node* head)
{
    node* temp1=head;
    node* temp2=NULL;
    node* head2=NULL;
    int len=length(head);
    int m=len/2;
    for(int i=0;i<m-1;i++)
    {
        temp1=temp1->next;
    }
    if(len%2==0)
    {
        head2=temp1->next;
    }
    else
    {
        head2=temp1;
    }
    head2=reverse(head2);
    temp1=head;
    temp2=head2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data !=temp2->data)
        {
            return 0;
        }
        else
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return 1;
    
}


int main()
{
 
 node* head=create();
 int ans=checkpalindrome(head);
 if(ans)
 {
     cout<<" it is a palindrome";
 }
 else
 {
     cout<<" it is not a palindrome";
 }

}