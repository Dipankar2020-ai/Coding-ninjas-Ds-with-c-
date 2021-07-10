
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
int sumofnodes(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=root->data;
    return ans+sumofnodes(root->left)+sumofnodes(root->right);
}
int height(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
bool balanced(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return 1;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    int ans=true;
     if((abs(lh-rh)==0|| abs(lh-rh)==1) && balanced(root->left) && balanced(root->right))
     {
         return 1;
     }
     return 0;
    
}
 int main()
 {
    
     Binarynode<int>* root=takeinputlevelwise();
     if(balanced(root))
     {
         cout<<"true";
     }
     else{
         cout<<"false";
     }
 } 