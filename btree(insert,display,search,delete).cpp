#include<iostream>
using namespace std;
//class to create node
class node{
     public:
     node *parent;
     node *left;
     node *right;
     int data;
    node(){
     parent=left=right=NULL;
     data=0;
    }
};

//class to create a binary tree
class Btree{
     public:
     node *root;       
   
    Btree()
    {
    root=NULL;
    }

// to insert elements
 void insert(int x){
   node *temp=new node;
   temp->data=x;
   temp->parent=temp->left=temp->right=NULL;
   
   if(root==NULL)
   { root=temp;
   }
   else{ node *curr; 
         curr=root;
        while(1){
            if(x<curr->data){
              
               if(curr->left==NULL){
                  temp->parent=curr;
                  curr->left=temp;
               break;
               }              
              else{curr=curr->left;}
            }
           else { 
                    if(curr->right==NULL)
                       {
                       temp->parent=curr;
                       curr->right=temp;
                     break;}
                   else{curr=curr->right;}
                  }
                          
        }
     }
 }

//to display the elements

 void display(node *temp){
     
      if(temp==NULL)
         return;
      display(temp->left);
      cout<<"\t"<<temp->data;
      display(temp->right); 
      cout<<"\t"<<temp->data;
}
   
     //to search a node
node* searchNode(int dt)
{
 int count =0;
 node * check = root;
 if(check == NULL)
     return NULL;
 else
  while(true)
  {
   if(check->data == dt)
   {
	cout << "\nNode found at depth " << count <<".\n";
	display(check);
	return check;
   }
   else if(check->data > dt)
   {
    if(check->left == NULL)	
	{
	 cout << "\nNOT FOUND.\n";
	 return NULL;
	}
    else
	check = check->left;
   }
   else
   {
    if(check->right == NULL)
	{
 	 cout << "\nNOT FOUND.\n";
	 return NULL;
	}
    else
	check = check->right;
   }
   
   count++;
  }
}
	
	
	//To delete a node
void deletenode(node*temp,int s)
{
  
  if(search(temp,s)!=NULL)
  {  
    node*curr=searchNode(temp,s);
    cout<<curr->data;
    // if this is leaf node
    if(curr->left==NULL && curr->right==NULL)
    { 
      if(curr->parent->left==curr)
        curr->parent->left=NULL;
      else
         curr->parent->right=NULL;
    }
    // if node has only one child
    else if(curr->left==NULL || curr->right==NULL)
    { 
      if(curr!=root)
      {
        node* p;
        node* c;
        p=curr->parent; 
        if(curr->left==NULL)
        c=curr->right;
        else
        c=curr->left;
        if(p->data>=curr->data)
        {
          p->left=c;
          c->parent=p;
        }
        else
        {
         p->right=c;
         c->parent=p;
        }
       }
       else
       {
         if(curr->left==NULL)
          root=curr->right;
         else
          root=curr->left;
       }
    }
    // node has at most 2 child
    else
    {
      node*l;
      l=curr->left;
      while(l->right!=NULL)
      {
        l=l->right;
      }
      if(l->left==NULL)
      {
       curr->data=l->data;
       node* p=l->parent;
       if(p->left==l)
        p->left=NULL;
       else
        p->right=NULL;
      }
      else
      {
        curr->data=l->data;
        node* p=l->parent;
        if(p->left==l)
        p->left=l->left;
        else
        p->right=l->left;
      }
    }
  }
}

	

    

};     


int main(){
 Btree b;
 cout<<"\nMENU";
 cout<<"\n1.INSERT";
 cout<<"\n2.DISPLAY";
 cout<<"\n3.SEARCH";  
 cout<<"\n4.DELETE";
 cout<<"\n5.EXIT";
 
int ch,x;
do{
  cout<<"\nenter your choice (1-4): ";
  cin>>ch;
  switch(ch){
  case 1:cout<<"\nenter the data you want to enter :";
         cin>>x;
         b.insert(x);break;
  case 2:b.display(b.root);break;
  case 3:cout<<"\nenter the data you want to search :";
         cin>>x;
         b.searchNode(x);break;  
case 3:cout<<"\nenter the data you want to delete :";
         cin>>x;
         b.deleteNode(b.root,x);break;
  deafult:cout<<"\ntype 1,2,3 or 4 ";break;
  }
}while(ch!=5);
return 0;
}
