#include <iostream>
#include<vector>
#include<queue>
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
treenode<int>* takeinputlevel()
{
    int rootdata;
    cout<<"Enter root data"<<endl;
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);
    queue<treenode<int>* >pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        treenode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter the number of children of : "<<front->data;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++)
        {
            int childdata;
            cout<<"enter "<<i<<" th child of  : "<<front->data<<endl;
            cin>>childdata;
            treenode<int>* child=new treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
            
        }
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
    treenode<int>* root=takeinputlevel();
    printtree(root);
   
    
    

   