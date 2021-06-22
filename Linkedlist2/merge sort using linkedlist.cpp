
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* midpoint_linkedlist(node *head)
{
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* merge(node* head1,node* head2)
{
    node* head=NULL;
    node* tail=NULL;
    if(head1->data<=head2->data)
    {
        head=head1;
        tail=head1;
        head1=head1->next;
    }
    else
    {
        head=head2;
        tail=head2;
        head2=head2->next;
        
    }
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<=head2->data)
        {
            tail->next=head1;
            tail=tail->next;
            head1=head1->next;
        }
        else
        {
            tail->next=head2;
            tail=tail->next;
            head2=head2->next;
        }
    }
    if(head1==NULL)
    {
        tail->next=head2;
    }
    else
    {
        tail->next=head1;
    }
    return head;
}

node* mergesort(node* head)
{
    if(head==NULL|| head->next==NULL)
    {
        return head;
    }
    else
    {
        node* mid=midpoint_linkedlist(head);
        node* half1=head;
        node* half2=mid->next;
        mid->next=NULL;
        half1=mergesort(half1);
        half2=mergesort(half2);
        node* finalnode=merge(half1,half2);
        return finalnode;
        
        
    }
}

int main(){
    node*head=takeinput();
    head= mergesort(head);
    print(head);
    
    //print(head);
    return 0;
}