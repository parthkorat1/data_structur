#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
      int data;
      struct node *next;
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
	   if(newnode==0)
	   {
	       printf("\noverflow");
	   }
	   else
	   {
		if(head==0)
		{
		     head=newnode;
		     newnode->next=head;

		  }
		  else
		  {
		       temp=head;
		       while(temp->next!=head)
		       {
			      temp=temp->next;
		       }
		       newnode->next=head;
		       temp->next=newnode;
		     //  head=newnode;

		  }
	   }
	   printf("\nenter your choice(0/1)::");
	   scanf("%d",&choice);
     }

}
void insbig()
{
       struct node *newnode,*temp=head;
       newnode=(struct node*)malloc(sizeof(newnode));

       printf("\nenter data ::");
       scanf("%d",&newnode->data);
       newnode->next=0;

       if(newnode==0)
       {
		printf("\n overflow");
       }
       else
       {

	  if(head==0)
	  {
		 head=newnode;
		 newnode->next=head;
	   }
	  else
	  {
		while(temp->next!=head)
		{
		     temp=temp->next;
		}
		newnode->next=head;
		temp->next=newnode;
		head=newnode;
	  }
     }
}

void in_end()
{
		  struct node *newnode,*temp=head;
       newnode=(struct node*)malloc(sizeof(newnode));

       printf("\nenter data ::");
       scanf("%d",&newnode->data);
       newnode->next=0;



	if(head==0)
	{
	       printf("\nundefloe");
	}
	else
	{

	   while(temp->next!=head)
	   {
		     temp=temp->next;

	   }
	   temp->next=newnode;
	   newnode->next=head;
	}
}

void del_big()
{
      struct node *temp=head;
      if(head==0)
      {
	   printf("\nlist is epmty");
      }
      else if(head->next==head)

      {
		  head=0;
		  free(temp);
      }
      else
      {
	   while(temp->next!=head)
	   {
		 temp=temp->next;
	   }
	   temp->next=head->next;
	   free(head);
	   head=temp->next;
      }


}

void del_end()
{
	struct node *temp=head,*prv;
	if(head==0)
	{
	     printf("\nlist epmty::");
	}
	else if(head->next==head)
	{
	      head=0;
	      free(temp);
	}
	else
	{
	     while(temp->next!=head)
	     {
		   prv=temp;
		   temp=temp->next;
	     }
	     prv->next=temp->next;
	     free(temp);
	}
}

void display()
{
       struct node *temp=head;
       if(head==0)
       {
	   printf("list is empty");
       }
       else
       {

	  while(temp->next!=head)
	  {
		printf("%d",temp->data);
		temp=temp->next;
	  }printf("%d",temp->data);

       }
}


void main()
{
	int choice;
	 clrscr();
	 while(1)
	 {
	printf("\n1.create");
	printf("\n2.insert bigning\n3.insert end\n4.delete bigning");
	printf("\n5.delete end\n");
	printf("\n9.display\n10.exit\n");
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
	     in_end();
	     break;

	     case 4:
	     del_big();
	     break;

	     case 5:
	     del_end();
	     break;

	     case 9:
	     display();
	     break;

	     case 10:
	     exit(0);
	     break;
	   }
	  }
	  getch();
}
