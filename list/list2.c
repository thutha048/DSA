#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>
#define SIZE 100
 
typedef struct Address{
    char name[20];
    long  tel;
    char email[30];
}Address;

typedef struct AddressList{ 
    struct AddressList *next;
    Address addr;
}AddressList;


AddressList *insert_tohead(AddressList *root, Address ad, AddressList ** cur);
AddressList *insert_after(AddressList *root, Address ad, AddressList ** cur);
AddressList *delete(AddressList *root, AddressList **cur);
AddressList *findname(AddressList *root,Address find);

void print_list(AddressList *root);
void inputlist(int n, Address a[SIZE]);
void reverse(AddressList **root);
void release(AddressList **root);


void clearbuffer()
{
  int ch;
  while((ch=getchar())!= '\n'&& ch!= EOF);
}

AddressList *root = NULL;
AddressList *cur=NULL;
int n, choice, yes;

int main(){
   
  Address a[SIZE], *s1,ad, find;
 
    printf("Enter telephone number list:\n");
    printf("Enter the number of people: "); scanf("%d",&n);
    inputlist(n,a);

 do{
    printf("\nMENU:\n");
    printf("1.Insert an address into the first list\n");
    printf("2.Output the list\n");
    printf("3.Find following the name\n");
    printf("4.Reverse list\n");
    printf("5.Remove a node\n");
    printf("7.Delete all the list and Exit\n");

    printf("Enter your choice: "); scanf("%d",&choice);
    
      switch(choice){
      case 1:
	printf("Enter infor for a new people:\n");
	printf("Name: ");
	__fpurge(stdin); gets(ad.name); clearbuffer();
      printf("Phone number: ");
      __fpurge(stdin); scanf("%ld",&ad.tel); clearbuffer();
      printf("Email: ");
      __fpurge(stdin); gets(ad.email); clearbuffer();
      
	root=insert_tohead(root,ad,&cur);
	break;
      case 2:
	print_list(root);
	break;
      case 3:
	printf("Enter a name: "); __fpurge(stdin); gets(find.name); __fpurge(stdin);
	findname(root,find);
	break;
       case 4:
	reverse(&root);
	print_list(root);
	break;
      case 5:
	remove
      case 7:
	release(&root);
	printf("Delete all list and exist!\n");
	break;
	default:
	  printf("The choice is not exit! Enter again!\n");
      } 
    }while(choice!=5);
    return 0;
}

void release(AddressList **root)
{
    AddressList *temp = *root;
    *root = (*root)->next;
    while ((*root) != NULL)
    {
        free(temp);
        temp = *root;
        (*root) = (*root)->next;
    }
}

AddressList *insert_after(AddressList *root, Address ad, AddressList ** cur)
{
    AddressList * new_item = (AddressList*) malloc(sizeof(AddressList));
    new_item->addr = ad;
    new_item->next = NULL;
    if (root == NULL){
        root = new_item;
        *cur = root;
    } else {
        (*cur)->next = new_item;
        *cur = (*cur)->next;
    }
    return root;
}

AddressList *insert_tohead(AddressList *root, Address ad, AddressList ** cur)
{
    AddressList * new_item = (AddressList*) malloc(sizeof(AddressList));
    new_item->addr = ad;
    new_item->next = root;
    root=new_item;
    n=n+1;
    return root;
}

void inputlist(int n, Address a[SIZE])
{
   for(int i=0;i<n;i++)
    {
      printf("%d:\n",i+1);
      printf("Name: ");
      __fpurge(stdin); gets(a[i].name); clearbuffer;
      printf("Phone number: ");
      __fpurge(stdin); scanf("%ld",&a[i].tel); clearbuffer;
      printf("Email: ");
      __fpurge(stdin); gets(a[i].email); clearbuffer();
      
       root = insert_after(root,a[i], &cur);
     }
}

void print_list(AddressList *root){
  printf("The list is: \n");
  printf("  Name           |     Tel          |    Email        \n");  
    for (AddressList * cur = root; cur != NULL; cur = cur->next ){
      
        printf("%-17s| %-17ld| %-17s\n", (cur->addr).name, (cur->addr).tel, (cur->addr).email);
    }
}


AddressList *findname(AddressList *root, Address find)
{
  int exist=0;
  while(root!= NULL)
    {
      if( strcmp((root->addr).name, find.name)==0)
	{
	  exist++;
	   printf("  Name           |     Tel         |    Email        \n");
	   printf("%-17s| %-17ld| %-17s\n", (root->addr).name, (root->addr).tel, (root->addr).email);
	  
	}
      root =root->next;
    }
  if(exist==0) printf("It's not exist\n");
}


AddressList *delete(AddressList *root, AddressList **cur){
    if (*cur == root) {
        root = (*cur)->next;
        free(*cur);
        *cur = root;
        return root;
    }
    AddressList *prev = root;
    while (prev->next != *cur) prev = prev->next;
    prev->next = (*cur)->next;
    free(*cur);
    *cur = prev;
    return root;
}


void reverse(AddressList **head)
{
    AddressList *p, *q, *r;
 
    p = q = r = *head;
    p = p->next->next;
    q = q->next;
    r->next = NULL;
    q->next = r;
 
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *head = q;
}
