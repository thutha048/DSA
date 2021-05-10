#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>

void replace( char *s, char c1, char c2)
{
   for(int i=0;i< strlen(s);i++)
    {
      if(s[i]==c1)
	s[i]=c2;
    }
}

int main()
{
  char s[100];
  char c1, c2;
   printf("Enter a string: "); scanf("%s",s);
  __fpurge(stdin);
  printf("\n enter letter to replace: "); scanf("%c",&c1);
  __fpurge(stdin);
  printf("\n enter letter to replace with: "); scanf("%c",&c2);
  replace(s,c1,c2);
  printf("After change: %s\n",s);
  
}
