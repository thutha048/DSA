#include<stdio.h>
#include<string.h>
#define N 10
int n, x[N], mark[N];
void solution(){
  for(int i=1;i<=n;i++)
    printf("%d",x[i]);
  printf("\n");
}

void Try( int k){
  for(int v=1;v<=n;v++){
    if(!mark[v]){// v chua xuat hien
      x[k]=v;
      mark[v]=1;
      if(k==n) solution();
      else Try(k+1);
      mark[v]=0;
    }
  }
}
int main(){
  n=3;
  memset(mark,0,sizeof(mark));
  Try(1);
}
