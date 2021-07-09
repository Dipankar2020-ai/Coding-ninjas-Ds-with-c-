#include <iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
template<typename T>

class Binarynode
{
    public:
    T data;
    Binarynode* left;
    Binarynode* right;
    Binarynode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~Binarynode()
    {
        delete left;
        delete right;
    }
    
};

Binarynode<int>* takeinputlevelwise()
{
    int rootdata;
    cout<<"Enter root data: "<<endl;
    cin>>rootdata;
   
    if(rootdata==-1)
    {
        return NULL;
    }
    Binarynode<int>* root=new Binarynode<int>(rootdata);
    queue<Binarynode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        Binarynode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        int leftchild;
        cout<<"Enter left child of :"<<front->data<<"=>";
        cin>>leftchild;
        if(leftchild!=-1)
        {
            Binarynode<int>* child=new Binarynode<int>(leftchild);
            front->left=child;
            pendingnodes.push(child);
            
            
        }
        int rightchild;
        cout<<"Enter right child of :"<<front->data<<"=>";
        cin>>rightchild;
        if(rightchild!=-1)
        {
            Binarynode<int>* child=new Binarynode<int>(rightchild);
            front->right=child;
            pendingnodes.push(child);
            
            
        }
    }
    return root;
    
}
int numberofnodes(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+numberofnodes(root->left)+numberofnodes(root->right);
}
void printlevelwise(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Binarynode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        cout<<pendingnodes.front()->data<<":";
        if(pendingnodes.front()->left==NULL)
        {
            cout<<"L:-1";
        }
        if(pendingnodes.front()->left!=NULL)
        {
            cout<<"L:"<<pendingnodes.front()->left->data<<",";
            pendingnodes.push(pendingnodes.front()->left);
        }
         if(pendingnodes.front()->right==NULL)
        {
            cout<<"R:-1";
        }
        if(pendingnodes.front()->right!=NULL)
        {
            cout<<"R:"<<pendingnodes.front()->right->data<<",";
            pendingnodes.push(pendingnodes.front()->right);
        }
        cout<<endl;
        pendingnodes.pop();
    }
}

pair<int,int> maxmin(Binarynode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int>p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        return p;
    }
    int res=root->data;
    int res1=root->data;
    pair<int,int>leftans=maxmin(root->left);
    pair<int,int>rightans=maxmin(root->right);
    if(leftans.second>res)
    {
        res=leftans.second;
    }
    if(rightans.second>res)
    {
        res=rightans.second;
    }
    if(leftans.first<res1)
    {
        res1=leftans.first;
    }
    if(rightans.first<res1)
    {
        res1=rightans.first;
    }
    pair<int,int>p;
    p.second=res;
    p.first=res1;
    return p;
    
}
    
 int main()
 {
    
     Binarynode<int>* root=takeinputlevelwise();
     pair<int,int> p=maxmin(root);
     cout<<"MAX :"<<p.second<<endl;
     cout<<"MIN: "<<p.first<<endl;
  
    //printlevelwise(root);
    
  // postorder(root);
 }