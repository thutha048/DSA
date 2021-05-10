/*Implement the function my_strcat :
– Input – two strings, s1 and s2
– Output – a pointer to a dynamically
allocated concatenation
– For example: The concatenation of
“hello_” and “world!” is the string
“hello_world!”
• Test your function*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

#define MAX 10

char *scat(char *str1, char *str2)
{
  int len;
  char *result;

  len = strlen(str1);

  strcpy(result,str1);
  strcpy(result+ len, str2);

  return result;
}

int main()
{
  char str1[MAX+1], str2[MAX+1];
  char *catstr;
  printf("Enter 2 strings\n");
  scanf("%12s",str1); __fpurge(stdin);
  scanf("%12s",str2); __fpurge(stdin);

  catstr = scat(str1,str2);
  if(catstr== NULL)
    {
      printf("Problem allocating memory\n");
      return 1;
    }
  printf("The concatenation of %s and %s is %s\n",str1,str2,catstr);
  __fpurge(stdin);
  free(catstr);
  return 0;
}
