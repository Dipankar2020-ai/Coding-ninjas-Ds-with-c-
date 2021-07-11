
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

Binarynode<int>* constructtree(int input[],int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    Binarynode<int>* root= new Binarynode<int>(input[mid]);
    root->left=constructtree(input,s,mid-1);
    root->right=constructtree(input,mid+1,e);
    return root;
}

 int main()
 {
     int n;
     cout<<"Enter size of array"<<endl;
     cin>>n;
     int arr[n];
     cout<<"Enter array elements:"<<endl;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
    
     Binarynode<int>* root=constructtree(arr,0,n-1);
     cout<<"Ouput:"<<endl;
    printlevelorder(root);
     
 } 