#include<stdio.h>
#define MAX 100
int check( int a[MAX], int b[MAX], int n1, int n2)
{
  if(n1!=n2) return 0;
  else{
  for(int i=0; i<n1 ;i++)
    {
      if(a[i]!=b[i]) return 0;
    }
  return 1;
  }
}

int main()
{
  int a[MAX], b[MAX];
  int n1,n2;
  printf("So phan tu mang 1: "); scanf("%d",&n1);
  printf("Nhap mang 1:\n");
  for(int i=0; i<n1;i++){
    printf("a[%d]= ",i);
    scanf("%d",&a[i]);
  }

  printf("So phan tu mang 2: "); scanf("%d",&n2);
  printf("Nhap mang 2:\n");
  for(int i=0; i<n2;i++){
    printf("b[%d]= ",i);
    scanf("%d",&b[i]);
  }
  
  
  int c= check(a,b,n1,n2);
  if(c==1) printf("Giong\n");
  else if (c==0) printf("Khac\n");
  return 0;
}
