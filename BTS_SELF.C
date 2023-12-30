#include<stdio.h>
#include<conio.h>
struct node
{
      struct node *left,*right;
      int data;
}*root,*temp;

int getdata()
{
     int data;
     printf("\n enter a data::");
     scanf("%d",&data);
     return data;
}

struct node * create(int data)
{
       struct node *newnode;
       newnode=(struct node*)malloc(sizeof(struct node));

       newnode->data=data;
       newnode->left=NULL;
       newnode->right=NULL;

       return newnode;
}
struct node *smallest(struct node *root)
{
	 struct node *curr=root;
	 while(curr!=NULL && curr->left!=NULL)
	 {
	       curr=curr->left;
	 }
	 return curr;
}
void insert(int data)
{
	 struct node *newnode=create(data);
	 struct node *temp=root;
	 struct node *prv;

	 if(newnode!=NULL)
	 {
		 if(root==NULL)
		 {
			root=newnode;
			printf("\nnode inserted");
			return;
		 }
		 else
		 {
			temp=root;
			while(temp!=NULL)
			{
			       prv=temp;
			       if(data>temp->data)
			       {
				      temp=temp->right;
			       }
			       else
			       {
				      temp=temp->left;
			       }
			}
			if(data>prv->data)
			{
			       prv->right=newnode;
			}
			else
			{
			       prv->left=newnode;
			}   printf("\n node successfully iserted");
		 }
	  }
}
struct node *del(struct node *root,int key)
{
	 /*    if(root==NULL)
	     {      //   printf("\n jo root ma kai hoi j nai");
		       return root;
	     }*/
	     if(key<root->data)
	     {
		    root->left=del(root->left,key);
	     }
	     else if(key>root->data)
	     {
		    root->right=del(root->right,key);
	     }
	     else
	     {
		    if(root->left==NULL && root->right==NULL)
		    {
			    return NULL;
		    }
		   else if(root->left==NULL)
		    {
			 temp=root->right;
			 free(root);
			 return temp;
		    }
		    else if(root->right==NULL)
		    {
			  temp=root->left;
			  free(root);
			  return temp;
		    }
		    else
		    {
			 temp=smallest(root->right);
			 root->data=temp->data;
			 root->right=del(root->right,temp->data);
			 printf("\nnode delete in last else stetment(double node)");
		    }
	      }

	      return root;
}
struct node *largest(struct node *root)
{
	   struct node *curr=root;
	   while(curr!=NULL && curr->right!=NULL)
	   {
		  curr=curr->right;
	   }
	   return curr;
}
void inoder(struct node *root)
{
	 if(root==NULL)
	 {
	      return;
	  }
	  inoder(root->left);
	  printf("%d",root->data);
	  inoder(root->right);
}
void main()
{
	   int data,choice;
	   struct node *result;
	 clrscr();
	 while(1)
	 {


	 printf("\n enter your choice:;");
	 scanf("%d",&choice);
	 switch(choice)
	 {
	     case 1:
	      data=getdata();
	      insert(data);
	      break;

	      case 2:
	      inoder(root);
	      break;

	      case 3:
	      result=largest(root);
	      if(result!=NULL)
	      {
		     printf("\n largest is %d",result->data);
	      }
	      break;

	      case 4:
	      result=smallest(root);
	      if(result!=NULL)
	      {
		      printf("\n smallest is %d",result->data);
	      }
	      break;

	      case 5:
	      data=getdata();
	      root=del(root,data);
	      break;

	      case 9:
	      exit(0);
	      break;

	  }
       }
	 getch();
}