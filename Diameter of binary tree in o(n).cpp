
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
pair<int,int> heightdiameter(Binarynode<int>* root)
{
    if(root==NULL)
    {
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>leftans=heightdiameter(root->left);
    pair<int,int>rightans=heightdiameter(root->right);
    int lh=leftans.first;
    int ld=leftans.second;
    int rh=rightans.first;
    int rd=rightans.second;
    int height=1+max(lh,rh);
    int diameter=max(lh+rh,max(ld,rd));
    pair<int,int>p;
    p.first=height;
    p.second=diameter;
    return p;
}
    
 int main()
 {
    
     Binarynode<int>* root=takeinputlevelwise();
     pair<int,int> p=heightdiameter(root);
     cout<<"Height :"<<p.first<<endl;
     cout<<"Diameter: "<<p.second<<endl;
  
    printlevelwise(root);
    
  // postorder(root);
 }