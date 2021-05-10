#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
typedef struct address
{
  char name[30];
  char phone[15];
  char email[30];
}address;

struct address a[MAX];

int compare(const void *n1,const void *n2)
{
  return strcmp(((address*)n1)->name, ((address*)n2)->name);

}
/*
void insertion( address a[MAX], int n)
{
  int i,j;
  char next;
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
*/

int main()
{
  /*FILE *fptr;
  fptr = fopen("/home/thaohust/ex1.txt","r");
  if ( fptr ==NULL)
    {
      printf("Error!\n"); exit(1);
    }*/
  int i=0, n=3;

  for( i=0;i<n;i++)
    {
      
    }
  printf("Sort by name: \n");
  qsort(a,n, sizeof(address), compare);
  
  return 0;
  
  //fclose(fptr);
}
