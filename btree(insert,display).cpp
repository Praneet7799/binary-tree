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

    

};     


int main(){
 Btree b;
 cout<<"\nMENU";
 cout<<"\n1.INSERT";
 cout<<"\n2.DISPLAY";
 cout<<"\n3.SEARCH";    
 cout<<"\nEXIT";
 
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
  deafult:cout<<"\ntype 1,2,3 or 4 ";break;
  }
}while(ch!=4);
return 0;
}
