
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include<ctype.h>

void xuat(int a[],char str[])
{
  for(int i=0;i<26;i++)
    {
      if(a[i]>0)
    printf("%c: %d\n",str[i],a[i]);
    }
}
void dem(char s[])
{
  int i=0;
  for(i=0;i<strlen(s);i++)// ham chuyen chuoi ve chu thuong
    {
      if(isupper(s[i]))
	 s[i]=tolower(s[i]);
    }

      char str[26];
      strcpy(str,"abcdefghiklmnopqrstuvwxyz");
      int a[26]={0};
      for(i=0;i<strlen(s);i++)
	for(int j=0;j<26;j++)
	  if(s[i]==str[j]) a[j]++;
      xuat(a,str);
}

int main()
{
  char s[255];
  printf("nhap s: "); gets(s);
  dem(s);
    return 0;
  
}
