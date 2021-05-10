#include<stdio.h>
#define MAX 10
void bruteSearch(int a[], int n, int q)
{
  int i,j;
  for(i=0;i<n-1;i++)
    {
      for(j=i+1;j<n;j++)
	{
	  if(a[i]+a[j]==q)
	    printf("%d , %d\n",a[i], a[j]);
	}
    }
}

void sort( int a[MAX], int n)
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

int binary(int l, int r, int y)
{
  if(l>r) return 0;
  if(l==r) if(a[l]=y) return 1; else return 0;
  int m= (l+r)/2;
  if(a[m]==y) return 1;
  if(a[m]>y) return binary(l,m-1,y);
  return binary(m+1,r,y);
}

void binarySearch(int a[], int n,int q)
{
  int key = q/2 ,m, tmp=0, l=0; r=n-1;
  while(l<=r)
    {
      
    }
  
}
/*
void binarySearch(int a[], int n, int q)
{
  sort(a,n);
  int l=0 , r=n-1 ,m, mid , key= q/2, tmp=0, old;
  mid = (l+r)/2;
  old = a[mid];
  if(old<= key)
	  l= mid+1;
      else if(old> key) r = mid-1;
  while(l<=r)
    {
      
      m = (l+r)/2;
      if(a[m]<= key)
	l= m+1;
	
      else if(a[m]> key) r = m-1;
      tmp = old +a[m];
      printf("old = %d , tmp =%d\n", old, tmp);
      if(tmp== q) printf(" %d , %d\n",a[m],tmp-a[m]);
      else tmp =a[m];
    }
}
*/

int main()
{
  int a[5]={9,6,5,10,15}; //5,6,9,10,15
  int key= 15; //7
  printf("Search by brute force al Two elements:\n");
  bruteSearch(a,5,key);
  printf("Search by binary search al Two elements:\n");
  binarySearch(a,5,key);
  return 0;
}
