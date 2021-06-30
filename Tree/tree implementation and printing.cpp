#include <iostream>
#include<vector>

using namespace std;
template<typename T>
class treenode
{   public:
    T data;
    vector<treenode*>children;
    
    treenode(T data)
    {
        this->data=data;
        
    }
    
};
treenode<int>* takeinput()
{
    int rootdata,i;
    cout<<"Enter data:";
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);
    int n;
    cout<<"enter number of children of "<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        treenode<int>* child=takeinput();
        root->children.push_back(child);
    }
    return root;
    
}
void printtree(treenode<int>*root)
{
    int i;
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" :";
    for(i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<" ,";
    }
    cout<<endl;
     for(i=0;i<root->children.size();i++)
     {
        printtree(root->children[i]);
     }
    
}

int main()
{
    treenode<int>* root=takeinput();
    printtree(root);
   
    
    

    return 0;
}