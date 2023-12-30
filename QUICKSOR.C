#include<stdio.h>
#include<conio.h>
void quick(int [],int , int);
void main()
{
       int i,n,arry[10];
       clrscr();
       printf("\nenter size of arry");
       scanf("%d",&n);
       printf("\nenter element of arry");
       for(i=0;i<n;i++)
       {
	   scanf("%d",&arry[i]);
       }
       quick(arry,0,n-1);

	for(i=0;i<n;i++)
       {
	   printf("%d",arry[i]);
       }

       getch();
}

void quick(int arry[10],int first,int last)
{
	    if(first<last)
	    {
		   int i,j,pivot,temp;
		   pivot=first;
		   i=first;
		   j=last;

		   while(i<j)
		   {
		       while(arry[i]<=arry[pivot] && i<last)
		       {
			  i++;
		       }
		       while(arry[j]>arry[pivot])
		       {
			   j--;
		       }
		       if(i<j)
		       {
			   temp=arry[i];
			   arry[i]=arry[j];
			   arry[j]=temp;
		       }
		   }
		   temp=arry[j];
		   arry[j]=arry[pivot];
		   arry[pivot]=temp;

		   quick(arry,first,j-1);
		   quick(arry,j+1,last);
	}
}