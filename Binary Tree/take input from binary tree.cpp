#include <iostream>

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
    Binarynode<int>* root=takeinput();
    printtree(root);
    return 0;
}