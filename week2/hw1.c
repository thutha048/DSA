#include<stdio.h>
#define N 100
int n, x[N] ;

void solution()
{
  int num=0;
   for(int i=1;i<=n;i++)
    {
      if(x[i]==0) num++;
    }
   if(num==2){
     for(int i=1;i<=n;i++)
       printf("%d",x[i]);
     printf("\n");
   }
}

int check( int v, int k){
  return 1;
}

void try(int k){
  for(int v=0;v<=1;v++){
    if(check(v,k)){
      x[k]=v;
      if(k==n ) solution();
      else try(k+1);
    }
  }
}
int main(){
  n=5;
  try(1);
}
