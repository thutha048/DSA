#include<stdio.h>
//chuyển 4 đĩa từ A sang B = chuyển 3 đĩa từ A sang C thông qua B+ chuyển đĩa to nhất từ A sang B+ chuyển 3 đĩa từ C sang B thông qua A

int cnt=0;
void move( int n, char a, char b, char c){
  if(n==1){
    cnt++;
    printf("Step %d: move from %c to %c\n",cnt,a,b);
  }else{
    move(n-1,a,c,b);
    move(1,a,b,c);
    move(n-1,c,b,a);
  }
}
int main(){ move(3,'a','b','c');}
