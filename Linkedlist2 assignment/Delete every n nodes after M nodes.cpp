
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
node* oddaftereven(node* head)
{
    node* oddH=NULL;
    node* oddT=NULL;
    node* evenH=NULL;
    node*evenT=NULL;
    while(head!=NULL)
    {
        if(head->data%2!=0)
        {
            if(oddH==NULL)
            {
                oddH=head;
                oddT=head;
            }
            else
            {
                oddT->next=head;
                oddT=oddT->next;
            }
        }
        else
        {
            if(evenH==NULL)
            {
                evenH=head;
                evenT=head;
            }
            else
            {
                evenT->next=head;
                evenT=evenT->next;
            }
        }
        head=head->next;
    }
    if(oddT==NULL)
    {
        return evenH;
    }
    if(evenH==NULL)
    {
        return oddH;
    }
    oddT->next=evenH;
    return oddH;
}
node* skipMdeleteN(node  *head, int M, int N) {
    node* temp = head;
    while(temp!=NULL){
        for(int i=0;i<M-1;i++){
            if(temp!=NULL){
                temp=temp->next;
            }
            else{
                break;
            }
        }
        node* p = temp;
         if(temp==NULL){
            return head;
        }
        for(int j= 0;j<N;j++){
            
            if(temp!=NULL && temp->next!=NULL && p->next!=NULL){
                p=temp->next;
                temp->next=p->next;
                delete(p); 
            }
        }
        temp=temp->next;
   }
    return head;
}

int main()
{
   
    node* head=create(head);
 
   print(head);
   cout<<endl;
   int M,N;
   cin>>M>>N;
   head=skipMdeleteN(head,M,N);
    print(head);
   

    return 0;
}