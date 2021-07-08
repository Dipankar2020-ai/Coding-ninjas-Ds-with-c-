
#include <iostream>
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
Binarynode<int>* takeinput()
{
    int rootdata;
    cout<<"Enter data :";
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    Binarynode<int>* root=new Binarynode<int>(rootdata);
    Binarynode<int>* leftchild=takeinput(); 
    Binarynode<int>* rightchild=takeinput();    
    root->left=leftchild;
    root->right=rightchild;
    return root;
    
    
}
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
void printtree(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<"L="<<root->left->data<<" ";
    }
     if(root->right!=NULL)
    {
        cout<<"R="<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
    
    
}

int main()
{
    Binarynode<int>* root=takeinputlevelwise();
    printtree(root);
    return 0;
}