#include<stdio.h>
#include<conio.h>

int arr[10];

void marge(int first,int mid,int last)
{
	  int i,j,u,k,temp[10];
	  i=first;
	  k=first;
	  j=mid+1;

	  while(i<=mid   &&  j<=last)
	  {
		 if(arr[i]<=arr[j])
		 {
			temp[k]=arr[i];
			i++;k++;
		 }
		 else
		 {
			temp[k]=arr[j];
			j++;k++;
		 }
	  }
	  while(i<=mid)
	  {
		  temp[k]=arr[i];
		  i++;k++;
	  }
	  while(j<=last)
	  {
		  temp[k]=arr[j];
		  j++;k++;
	  }
	  for(u=first;u<=last;u++)
	  {
		  arr[u]=temp[u];
	  }

}

void sort(int first,int last)
{
	if(first!=last)
	{
	    int mid ;
	    mid=(first+last)/2;
	    sort(first,mid);
	    sort(mid+1,last);
	    marge(first,mid,last);
	}
}

void main()
{

      int size,i;
      clrscr();

      printf("\nenter size of arry ::");
      scanf("%d",&size);

      printf("\nelement of arry ::");
      for(i=0;i<size;i++)
      scanf("%d",&arr[i]);

      sort(0,size-1);

      for(i=0;i<size;i++)
      printf("%d",arr[i]);

      getch();
}
