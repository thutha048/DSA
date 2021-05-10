#include<stdio.h>
// 1 1 2 3 5 8 13. f(n)= f(n-1)+f(n-2), n la chi so cua cac p.tu
int fibo(int n)
{
  if(n<=1) return 1;
  return fibo(n-1)+ fibo(n-2);
}

int main()
{
  for(int i=0;i<=5;i++)
    printf("%d\n",fibo(i));
      }
