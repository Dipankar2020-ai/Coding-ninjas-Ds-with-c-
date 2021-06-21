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


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    node* head=create();
    //print(head);
    cout<<endl;
    int element;
    cin>>element;
    cout<<findnode(head,element,0);
    }
    return 0;
}