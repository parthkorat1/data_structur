#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
      int data;
      struct node *next;
      struct node *prv;
}*head;

void create()
{
     int choice;
     struct node *newnode,*temp;

     while(choice)
      {
	  newnode=(struct node*)malloc(sizeof(newnode));
	  printf("\n\nenter data::");
	  scanf("%d",&newnode->data);
	   newnode->next=0;
	   newnode->prv=0;
	  if(head==0)
	  {
	       head=newnode;
	       temp=newnode;
	  }
	  else
	  {
	       temp->next=newnode;
	       newnode->prv=temp;
	       temp=newnode;
	   }
	   printf("\nenter your choice(0/1)::");
	   scanf("%d",&choice);
     }

}
void insbig()
{
       struct node *newnode;
       newnode=(struct node*)malloc(sizeof(newnode));

       printf("\nenter data ::");
       scanf("%d",&newnode->data);

       if(head==0)
       {
		 head=newnode;
		 newnode->next=0;

       }
       else
       {
		newnode->next=head;
		head->prv=newnode;
		head=newnode;
       }
}
void in_any()
{
	 int i=1,pos;

	if(head==0)
	{
	    printf("list s empty");
	}
	else
	{
	  struct node *newnode,*temp=head;
       newnode=(struct node*)malloc(sizeof(newnode));

       printf("\nenter data ::");
       scanf("%d",&newnode->data);
       printf("\nenter position ::");
       scanf("%d",&pos);

       while(i<pos-1)
       {
	     temp=temp->next;
	     i++;
       }
       newnode->prv=temp;
       newnode->next=temp->next;
       temp->next=newnode;
       newnode->next->prv=newnode;

       }
}

void in_any_after()
{
	 int i=1,pos;

	if(head==0)
	{
	    printf("list s empty");
	}
	else
	{
	  struct node *newnode,*temp=head;
       newnode=(struct node*)malloc(sizeof(newnode));

       printf("\nenter data ::");
       scanf("%d",&newnode->data);
       printf("\nenter position ::");
       scanf("%d",&pos);

       while(i<pos)
       {
	     temp=temp->next;
	     i++;
       }
       newnode->prv=temp;
       newnode->next=temp->next;
       temp->next=newnode;
       newnode->next->prv=newnode;
       }
}

void in_end()
{
		  struct node *newnode,*temp=head;
       newnode=(struct node*)malloc(sizeof(newnode));

       printf("\nenter data ::");
       scanf("%d",&newnode->data);


	if(head==0)
	{
	       head=newnode;
	       newnode->next=0;
	}
	else
	{

	   while(temp->next!=0)
	   {
		     temp=temp->next;

	   }
	   newnode->prv=temp;
	   temp->next=newnode;
	   newnode->next=0;
	}
}

void del_big()
{
      struct node *temp=head;
      if(head==0)
      {
	   printf("\nlist is epmty");
      }
      else
      {
	   head=temp->next;
	   head->prv=0;
	   free(temp);
      }
}
void del_any()
{
    struct node *temp=head,*nextnode;
    int pos,i=1;
    if(head==0)
    {
	 printf("\ninst is epmty");
    }
    else
    {
	 printf("\nenter position::");
	 scanf("%d",&pos);

	 while(i<pos-1)
	 {
	    temp=temp->next;
	    i++;
	 }
	 temp->prv->next=temp->next;
	 temp->next->prv=temp->prv;

       //	 nextnode=temp->next;
       //	 temp->next=nextnode->next;
       //	 nextnode->next->prv=temp;
	 free(temp);
   }
}

void del_end()
{
	struct node *temp=head;
	if(head==0)
	{
	     printf("\nlist epmty::");
	}
	else if(head->next==0)
	{
	      head=0;
	      free(temp);
	}
	else
	{
	     while(temp->next!=0)
	     {
		   temp=temp->next;
	     }
	     temp->prv->next=0;
	     free(temp);
	}
}

void display()
{
       struct node *temp=head;
       if(head==0)
       {
	 printf("\n list is empty");
       }
       else
       {

	   while(temp!=0)
	   {
		printf("%d",temp->data);
		temp=temp->next;
	    }
       }
}

void serch()
{
       struct node *temp=head;
       int i=1,data;
       if(head==0)
       {
	    printf("\nlist is epmty");
       }
       else
       {
	   printf("\nenter data to serch::");
	   scanf("%d",&data);

	   while(temp!=0)
	   {
		if(temp->data==data)
		{
		  printf("\ndata found at %d position",i);
		  break;
		}
		temp=temp->next;
		i++;
	  }
	  if(temp==0)
	  {
	       printf("\ndata not found");
	  }
       }
}

void main()
{
	int choice;
	 clrscr();
	 while(1)
	 {
	printf("\n1.create");
	printf("\n2.insert bigning\n3.insert any psition\n4.insert after any position");
	printf("\n5.insert end\n6.delete bigning\n7.delete any position\n8.delete end");
	printf("\n9.display\n10.serch\n11.exit\n");
	   printf("\nenter your choice\n");
	   scanf("%d",&choice);

	   switch(choice)
	   {
	     case 1:
	     create();
	     break;

	     case 2:
	     insbig();
	     break;

	     case 3:
	     in_any();
	     break;

	     case 4:
	     in_any_after();
	     break;

	     case 5:
	     in_end();
	     break;

	     case 6:
	     del_big();
	     break;

	     case 7:
	     del_any();
	     break;

	     case 8:
	     del_end();
	     break;

	     case 9:
	     display();
	     break;
																																														
	     case 10:
	     serch();
	     break;

	     case 11:
	     exit(0);
	     break;
	   }
	  }
	  getch();
}
