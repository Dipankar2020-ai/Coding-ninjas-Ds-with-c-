
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

template<typename T>
class node
{ public:
    T data;
    node<T>* next;
    node(T data)
    {
        this->data=data;
        this->next=NULL;
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
vector<int>* getrootpath(Binarynode<int>* root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==data)
    {
        vector<int>* output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftoutput=getrootpath(root->left,data);
    if(leftoutput!=NULL)
    {
        leftoutput->push_back(root->data);
        return leftoutput;
    }
     vector<int>* rightoutput=getrootpath(root->right,data);
     if(rightoutput!=NULL)
     {
         rightoutput->push_back(root->data);
         return rightoutput;
     }
     else{
         return NULL;
     }
    
}

 int main()
 {
     Binarynode<int>* root=takeinputlevelwise();
     int data;
     cin>>data;
     vector<int>* output=getrootpath(root,data);
     for(int i=0;i<output->size();i++)
     {
         cout<<output->at(i)<<" ";
         
     }
     delete output;
     delete root;
     
 }