#include <iostream>
#include<queue>
using namespace std;
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
    
    queue<Treenode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        cout<<pendingnodes.front()->data<<":";
        for(int i=0;i<pendingnodes.front()->children.size();i++)
        {
            cout<<pendingnodes.front()->children[i]->data;
            pendingnodes.push(pendingnodes.front()->children[i]);
        
        if(i<pendingnodes.front()->children.size()-1)
        {
            cout<<",";
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

int main()
{
     Treenode<int>* root=createlevel();
     //printlevelwise(root);
     preorder(root);
     

   