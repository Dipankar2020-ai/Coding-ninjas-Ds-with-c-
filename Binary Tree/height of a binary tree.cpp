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
int numberofnodes(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+numberofnodes(root->left)+numberofnodes(root->right);
}
bool isnodepresent(Binarynode<int>* root,int x)
{
    
    
    if(root==NULL)
    {
        return 0;
    }
   
    if(root->data==x)
    {
        return true;
    }
    bool res1=isnodepresent(root->left,x);
    if(res1)
    {
        return true;
    }
    bool res2=isnodepresent(root->right,x);
    return res2;
}
int height(Binarynode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=1;
    
    return ans+(height(root->left)>height(root->right)?height(root->left):height(root->right));
    
}
int main()
{
    Binarynode<int>* root=takeinputlevelwise();
   // printlevelwise(root);
    //cout<<numberofnodes(root);
    cout<<height(root);
    return 0;
}