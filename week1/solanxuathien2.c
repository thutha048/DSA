#include<stdio.h>
#include<string.h>
#define LENGTH 26

int main(void)
{
  int i, count[LENGTH]={0};
  char c= '\0';
  printf(" Enter a line of text: \n");
  c= getchar();
  while( c != '\n')
    {
      if(c <= 'z' && c>= 'a')
	++count[c - 'a'];
      c= getchar();
    }
  for( int i=0;i<26;i++){
    if(count[i])
      printf("letter '%c' appears %d time\n",i+'a',count[i]);
  }
  return 0;
  
}
