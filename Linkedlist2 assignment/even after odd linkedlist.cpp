
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
node* arrange_LinkedList(node* head){
    node* oddHead = NULL;
    node* oddTail = NULL;
    node* evenHead = NULL;
    node* evenTail = NULL;
    while(head!=NULL){
        if(head->data%2!=0){
            if(oddHead == NULL){
                oddHead=head;
                oddTail=head;
            }
            else{
                oddTail->next=head;
                oddTail=oddTail->next;
            }
        }
        else{
            if(evenHead == NULL){
                evenHead=head;
                evenTail=head;
            }
            else{
                evenTail->next=head;
                evenTail=evenTail->next;
            }
        }
        head = head->next;
        
    }
    
    if(oddTail==NULL){
        return evenHead;
    }
    if(evenHead==NULL){
        return oddHead;
    }
    oddTail->next = evenHead;
    return oddHead;
}

int main()
{
   
    node* head=create(head);
 
   print(head);
   cout<<endl;
   head=arrange_LinkedList(head);
    print(head);
   

    return 0;
}