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
class isbstreturn
{
    public:
    int minimum;
    int maximum;
    bool isbst;
};

isbstreturn isbst2(Binarynode<int>* root)
{
    if(root==NULL)
    {
        isbstreturn output;
        output.isbst=true;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        return output;
    }
    isbstreturn leftoutput=isbst2(root->left);
    isbstreturn rightoutput=isbst2(root->right);
    int minimum=min(root->data,min(leftoutput.minimum,rightoutput.minimum));
    int maximum=max(root->data,max(leftoutput.maximum,rightoutput.maximum));
    bool bstfinal=(root->data)>leftoutput.maximum && root->data<=rightoutput.minimum && leftoutput.isbst && rightoutput.isbst;
    isbstreturn output;
    output.minimum=minimum;
    output.maximum=maximum;
    output.isbst=bstfinal;
    return output;
    
}
bool isBST(Binarynode<int> *root){
    isbstreturn output = isbst2(root);
    return output.isbst;
}

 int main()
 {
     
    
     Binarynode<int>* root=takeinputlevelwise();
     if(isBST(root))
     {
         cout<<"true";
     }
     else{
         cout<<"false";
     }
     
 } 