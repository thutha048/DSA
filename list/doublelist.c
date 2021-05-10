#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

typedef struct product {
  char id[20];
  char name[80];
  int price;
}product;

typedef struct node{
  product data;
  struct node *next;
  struct node *prev;
}node;

node *first, *last;
int num;

void insert(node ** head,product new);
void printlist(node *node);
void findid(char idfind[20]);
void removelist(node *node);

int main()
{
  first = NULL;
  last = NULL;
  int choice;
  product a;
  printf("Enter the number of products: ");scanf("%d",&num);
  printf("Enter the information for list:\n");

  for(int i=1;i<=num;i++)
    {
      printf("Product %d:\n",i);
      __fpurge(stdin);
      printf("ID: "); scanf("%[^\n]*c",a.id);
      __fpurge(stdin);
      printf("Name: "); scanf("%[^\n]*c",a.name);
      __fpurge(stdin);
      printf("Price: "); scanf("%d",&a.price);
      insert(&first,a);
      printf("\n");
    }
  printlist(first); printf("\n");
      
  
  do{
    printf("*******************************\n");
    printf("THE PRODUCT MANAGEMENT PROGRAM:\n");
    printf("1.Insert a new product at the end \n");
    printf("2.Find the product following id\n");
    printf("3.Delete all the list\n");
    printf("4.Exit\n");
    printf("*******************************\n\n");

    printf("Enter your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
      {
      case 1:
	num++;
	printf("Input data for the last node:\n");
	printf("New product %d:\n",num);
	__fpurge(stdin);
        printf("ID: "); scanf("%[^\n]*c",a.id); __fpurge(stdin);
        printf("Name: "); scanf("%[^\n]*c",a.name);__fpurge(stdin);
        printf("Price: "); scanf("%d",&a.price);__fpurge(stdin);
        insert(&first,a);
        printf("\n");
	printlist(first);
	break;
      case 2:
	printf("Enter ID to find: ");
	char idfind[20];
	__fpurge(stdin);
	scanf("%[^\n]*c",idfind);__fpurge(stdin);
	findid(idfind);
	break;
      case 3:
	printf("Delete all the list\n");
	printf("  ID             |     Name         |    Price        \n EMPTY \n");
	while(first!=NULL)
	  removelist(first);
	break;
      case 4:
	printf("Exit \n");
	break;
      default:
	printf("It is not valid. Enter other choice\n");
	break;
      }
  }while( choice !=4);
    return 0;
}

//-----------------------------------
void insert(node** head, product new)
{
  node *newnode = (struct node*)malloc(sizeof(struct node));
  node* end = *head;
  newnode->data = new;
  newnode->next = NULL;
  if(*head == NULL){
    newnode-> prev=NULL;
    *head = newnode;
    return;
  }
  while ( end->next !=NULL)
    end=end->next;
  end->next = newnode;
  newnode->prev= end;
  return;
}
//*--------------------------------

void printlist(node* node)
{
  printf("  ID             |     Name         |    Price        \n");  
    while(node!= NULL)
      {
        printf("%-17s| %-17s| %-17d\n", (node->data).id, (node->data).name, (node->data).price);
	last  = node;
	node=node->next;
  }
}

//----------------------------------

void findid(char idfind[20])
{
  int pos =0;
  if(first == NULL){
    printf("Linked list not initialized\n"); return;
  }
  while(first!=NULL){
    pos++;
    if(strcmp((first->data).id, idfind)==0 ){
      printf("It is product at position %d: \n",pos);
      printf("Name: %s\n",(first->data).name);
      printf("Price: %d\n",(first->data).price);
      return;
    }

    if(first->next != NULL)
      first = first->next;
    else
      break;
      }
  
  printf("It does not exist in the list\n");
}

//-----------------------------------
void removelist( node *node)
{
  if(node->prev==NULL)
    first =node->next;
  else node->prev->next =node->next;
  if(node->next ==NULL) last =node->prev;
  else node->next->prev = node->prev;
}
