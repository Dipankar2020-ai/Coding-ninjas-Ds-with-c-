
#include <iostream>
#include<queue>
using namespace std;
   int nextlargerdata=0;
template<typename T>
class Treenode
{
    public:
    T data;
    vector<Treenode*>children;
    Treenode(T data)
    {
        this->data=data;
    }
};
Treenode<int>* createlevel()
{
    int rootdata;
    cout<<"Enter root data : ";
    cin>>rootdata;
     Treenode<int>*  root=new Treenode<int>(rootdata);
    queue<Treenode<int>*>pendingnodes;
     pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        Treenode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        int numdata;
        
        cout<<"enter the number of children of : "<<front->data<<"=>";
        cin>>numdata;
        for(int i=0;i<numdata;i++)
        {
            int childata;
            cout<<"Enter "<<i<<" th children of :"<<front->data<<"=>";
            cin>>childata;
            cout<<endl;
             Treenode<int>* child= new Treenode<int>(childata);
             front->children.push_back(child);
             pendingnodes.push(child);
        }
    }
    return root;
    
    
}
int numnodes(Treenode<int>* root)
{
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans=ans+numnodes(root->children[i]);
    }
    return ans;
}
void printlevelwise(Treenode<int>* root)
{
    cout<<root->data<<endl;
    queue<Treenode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
       // cout<<pendingnodes.front()->data<<endl;
        for(int i=0;i<pendingnodes.front()->children.size();i++)
        {
            cout<<pendingnodes.front()->children[i]->data;
            pendingnodes.push(pendingnodes.front()->children[i]);
        
        if(i<pendingnodes.front()->children.size()-1)
        {
            cout<<" ";
        }
        }
        cout<<endl;
        pendingnodes.pop();
        
    }
}
void preorder(Treenode<int>*root)
{
    if(root==NULL)
     {
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preorder(root->children[i]);
    }
}
int countx(Treenode<int>* root,int x)
{
    int count=0;
    if(root==NULL)
    {
        return 0;
    }
    if(root->data>x)
    {
        count++;
    }
    for(int i=0;i<root->children.size();i++)
    {
        count+=countx(root->children[i],x);
    }
    return count;
} 
int nextlarger(Treenode<int>*root,int k)
{
 
    if(root==NULL)
    {
        return 0;
    }
    bool ans=true;
    if(root->data>k)
    {
        ans=false;
        nextlargerdata=root->data;
        return ans;
    }
    bool temp=true;
    for(int i=0;i<root->children.size();i++)
    {
        if(ans==temp)
        {
            temp=nextlarger(root->children[i],k);
        }
        else{
            return nextlargerdata;
        }
        
    }
    return 0;
}
void replacewithdepth(Treenode<int>* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    root->data=k;
    for(int i=0;i<root->children.size();i++)
    {
        replacewithdepth(root->children[i],k+1);
    }
}

int main()
{
    
    Treenode<int>* root=createlevel();
   
     replacewithdepth(root,0);
     printlevelwise(root);
}    
