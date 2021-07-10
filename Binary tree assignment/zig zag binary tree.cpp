#include <iostream>
#include<bits/stdc++.h>
#include<queue>
#include<vector>
#include<stack>
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
void printlevelorder(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Binarynode<int>*>pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);
    while(pendingnodes.size()!=0)
    {
        if(pendingnodes.front()==NULL)
        {
            pendingnodes.pop();
            if(pendingnodes.size()==0)
            {
                break;
            }
            pendingnodes.push(NULL);
            cout<<endl;
        }
        if(pendingnodes.front()->left!=NULL)
        {
            pendingnodes.push(pendingnodes.front()->left);
        }
         if(pendingnodes.front()->right!=NULL)
        {
            pendingnodes.push(pendingnodes.front()->right);
        }
        cout<<pendingnodes.front()->data<<" ";
        pendingnodes.pop();
    }
}
void zigzag(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<Binarynode<int>*>s1;
    stack<Binarynode<int>*>s2;
    s1.push(root);
    while(!s1.empty() && !s1.empty())
    {
        while(!s1.empty())
        {
            Binarynode<int>* top=s1.top();
            s1.pop();
            cout<<top->data<<" ";
            if(top->left!=NULL)
            {
                s2.push(top->left);
            }
            if(top->right!=NULL)
            {
                s2.push(top->right);
            }
        }
    
      cout<<endl;
      while(!s2.empty())
        {
            Binarynode<int>* top=s2.top();
            s2.pop();
            cout<<top->data<<" ";
            if(top->right!=NULL)
            {
                s1.push(top->right);
            }
            if(top->left!=NULL)
            {
                s1.push(top->left);
            }
        }
    cout<<endl;
    } 
}
 int main()
 {
     
    
     Binarynode<int>* root=takeinputlevelwise();
     zigzag(root);
 } 