
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
node* create(node* head)
{
    int data;
    
    cin>>data;
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
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int length(node* head)
{
    int count=0;
     while(head!=NULL)
    {
        
        head=head->next;
        count++;
    }
    return count;
}
int findnoderecursive(node* head,int ele,int len)
{
    if(len==0)
    {
        return -1;
    }
    if(head->data==ele)
    {
        return 1;
    }
    findnoderecursive(head->next,ele,len-1);
 
}

int main()
{
    //cout<<"Hello World";
    node* head=create(head);
    int len=length(head);
    int ele;
    cin>>ele;
    cout<<findnoderecursive(head,ele,len);
   // print(head);

    return 0;
}