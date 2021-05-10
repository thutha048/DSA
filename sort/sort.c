#include<stdio.h>
#define MAX 100
void insertion( int a[MAX], int n)
{
  int i,j;
  int next;
  for(i=1;i<n;i++)
    {
      next = a[i];
      j=i;
      while( (j>0) && (a[j-1]>= next))
	{
	  a[j]=a[j-1];
	  j=j-1;
	}
      a[j]=next;
    }
}


void selection( int a[], int n)
{
  int i,j, min, tmp;
  for(i=0;i<n-1;i++)
    {
      min=i;
      for(j=i+1;j <= n-1; j++)
	if(a[j] <= a[min])
	  min =j;
      tmp= a[i];
      a[i]=a[min];
      a[min]=tmp;
    }
}

int main()
{
  int a[MAX],n;
  printf("n= "); scanf("%d",&n);
  for(int i=0;i<n;i++){
    printf("a[%d]= ",i);
    scanf("%d",&a[i]);
  }
  selection(a,n);
  printf("After sort:\n");
  for(int i=0;i<n;i++)
    printf("a[%d] = %d\n",i,a[i]);
  
}
