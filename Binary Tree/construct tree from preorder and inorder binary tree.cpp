
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
Binarynode<int>* buildtreehelper(int* in,int* pre,int ins,int inl,int pres,int prel)
{
    if(ins>inl)
    {
        return NULL;
    }
    int rootdata=pre[pres];
    int rootindex=-1;
    for(int i=0;i<=inl;i++)
    {
        if(rootdata==in[i])
        {
            rootindex=i;
            break;
        }
    }
    int lins=ins;
    int linl=rootindex-1;
    int lpres=pres+1;
    int lprel=linl-lins+lpres;
    int rpres=lprel+1;
    int rprel=prel;
    int rins=rootindex+1;
    int rinl=inl;
    Binarynode<int>* root=new Binarynode<int>(rootdata);
    root->left=buildtreehelper(in,pre,lins,linl,lpres,lprel);
    root->right=buildtreehelper(in,pre,rins,rinl,rpres,rprel);
    return root;
}
Binarynode<int>* binarytree(int* in,int inlength,int * pre,int prelength)
{
    Binarynode<int>* temp= buildtreehelper(in,pre,0,inlength-1,0,prelength-1);
    
    return temp;
}
    
 int main()
 {
     int in[]={4,2,5,1,8,6,9,3,7};
     int pre[]={1,2,4,5,3,6,8,9,7};
     Binarynode<int>* root=binarytree(in,9,pre,9);
  
    printlevelwise(root);
    
  // postorder(root);
 }