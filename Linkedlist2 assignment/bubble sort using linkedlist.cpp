
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
void print(node* temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
node* bubblesort(node* head)
{
    node* current=head;
    node* index=NULL;
    int temp;
    if(head==NULL)
    {
        return head;
    }
    while(current!=NULL)
    {
        index=current->next;
    
        while(index!=NULL)
        {
            if(current->data>index->data)
            {
                temp=current->data;
                current->data=index->data;
                index->data=temp;
            }
            index=index->next;
        }
        current=current->next;
    }
    return head;
    
}

int main()
{
   node* head=create(head);
   print(head);
   cout<<endl;
   head=bubblesort(head);
   print(head);
   

}