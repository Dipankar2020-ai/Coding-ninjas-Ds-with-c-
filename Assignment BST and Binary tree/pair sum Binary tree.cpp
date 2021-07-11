
#include <iostream>
#include<bits/stdc++.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
int k=0;
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

void convert(Binarynode<int>* root,int arr[])
{
    if(root==NULL)
    {
        return;
    }
    arr[k++]=root->data;
    convert(root->left,arr);
    convert(root->right,arr);
    
}
void sumofnodestos(Binarynode<int>* root,int sum)
{
    int arr[1001];
    convert(root,arr);
    sort(arr,arr+k);
    int i=0;
    int j=k-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==sum)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;
            j--;
        }
        if(arr[i]+arr[j]>sum)
        {
            j--;
        }
        if(arr[i]+arr[j]<sum)
        {
            i++;
        }
    }
    
}

 int main()
 {
     Binarynode<int>* root=takeinputlevelwise();
     int sum;
     cin>>sum;
    sumofnodestos(root,sum);
     
     
 } 