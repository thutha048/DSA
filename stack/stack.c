#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *link;
}node;



void display(node *p);
node *push( node *p, int value);
node *pop(node *p, int *value);


void main()
{
  struct node *top=NULL;
  int n, value;
  do{
    do{
      printf("Enter the element to be pushed\n");
      scanf("%d",&value);
      top= push(top,value);
      printf("Enter 1 to continue\n");
      scanf("%d",&n);
    }while(n==1);
    printf("Enter 1 to pop an element\n");
    scanf("%d",&n);
    while(n==1)
      {
	top= pop(top,&value);
	printf("The value poped is %d\n",value);
	printf("Enter 1 to pop an element\n");
	scanf("%d",&n);
      }
    printf("Enter 1 to continue\n");
    scanf("%d",&n);
  }while(n==1);
  printf("The list of stack:\n");
  display(top);
}

//-----------------------
node *push(node *p, int value)
{
  node *temp;
  temp= (node*)malloc(sizeof(node));
  if(temp==NULL){
    printf("No memory available Error\n");
    exit(0);
  }
  temp->data= value;
  temp->link=p;
  p=temp;
  return (p);
}

//------------------------
node *pop(node *p, int *value)
{
  node *temp;
  if(p==NULL){
    printf("The stack is empty can not pop Error\n");
    exit(0);
  }
  *value= p->data;
  temp=p;
  p=p->link;
  free(temp);
  return (p);
}

//-------------------
void display(node *p)
{
  while(p!=NULL)
    {
      printf("%9d   ",p->data);
      p=p->link;
    }
  printf("\n");
  
}

/*-------------------------------
void display(node *p)
{
  node *snode;
  int ct=0;
  int m;
  printf("List of stack:\n");
  snode = p->top;
  do{
    m= snode->data;
    printf("%5d",m);
    ct++;
    if(ct%5==0) printf("\n");
    snode=snode->next;
  }
  while(!(snode==NULL));
  printf("\n");
}
*/

