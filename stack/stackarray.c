#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#define MAX 100

typedef struct address{
  char name[50];
  char number[15];
  char email[50];
}address;

typedef struct node{
  address data[MAX];
  node *next;
};

node *top= NULL;
node *push( node *p, int value);
node *pop(node *p, int *value);

int main()
{
  FILE *fptr;
  fptr = fopen("\home\phonelist.txt","r");
  if(fptr ==NULL)
    {
      printf("Error!"); exit(1);
    }
  
}
