vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    
    vector<node<int>*> v;
    
	if(root==NULL)
    {
       v.push_back(NULL) ;
        
        return v;
    }
        
    
    queue<BinaryTreeNode<int> *> pn;
    
    pn.push(root);
    pn.push(NULL);
    
    node<int> *head=NULL;
    node<int>  *tail =head;
    
   
    while(pn.size()!=0)
    { 
        BinaryTreeNode<int> *front=pn.front();
        pn.pop();
        
       if(front==NULL)
       { tail->next=NULL;
        
        if(pn.size()==0)
           break;
        
        pn.push(NULL);
        
        head=NULL;
        tail=NULL;
        
        
          
       }
        
     else
     {  
       node <int> *n=new node<int> (front->data);
       if(head==NULL)
       {
           head=tail=n;
           v.push_back(head);
       }
      else
      {
          tail->next=n;
          tail=n;
      }
     
        if(front->left)
        pn.push(front->left);
        if(front->right)
         pn.push(front->right);
     }
    }
}