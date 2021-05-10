
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
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

void printlist(AddressList *root);
void inputlist(int n, Address a[SIZE]);
void reverse(AddressList **root);
void release(AddressList **root);

AddressList *insert_tohead(AddressList *root, Address ad, AddressList ** cur);
AddressList *insert_after(AddressList *root, Address ad, AddressList ** cur);
AddressList *delete(AddressList *root, AddressList **cur);
AddressList *search(AddressList *root,Address find, Address a[SIZE]);



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
    printf("Input telephone list:\n");
    printf("Input the number of people: "); scanf("%d",&n);
    inputlist(n,a);

    do{
    printf("MENU\n");
    printf("1.Insert an address into the first list\n ");
    printf("2.Output the list\n");
    printf("3.Find following the name\n");
    printf("4.Reverse list\n");
    printf("5.Delete all the list and Exit\n");

    printf("Enter your choice: "); scanf("%d",&choice);
    
      switch(choice){
      case 1:
	printf("Enter infor for a new people:\n");
	printf("Name: ");
        gets(ad.name); clearbuffer();
      printf("Phone number: ");
       scanf("%ld",&ad.tel); clearbuffer();
      printf("Email: ");
       gets(ad.email); clearbuffer();
	root=insert_tohead(root,ad,&cur);
	break;
      case 2:
	printlist(root);
	break;
      case 3:
	printf("Enter a name: "); gets(find.name); clearbuffer();
	search(root,find);
	break;
	case 4:
	reverse(&root);
	printlist(root);
	break;
      case 5:
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
       gets(a[i].name); clearbuffer();
      printf("Phone number: ");
       scanf("%ld",&a[i].tel); clearbuffer();
      printf("Email: ");
      gets(a[i].email); clearbuffer();
      
       root = insert_after(root,a[i], &cur);
     }
}

void printlist(AddressList *root){
  printf("The list is: \n");
  printf("  Name           |     Tel          |    Email        \n");  
    for (AddressList * cur = root; cur != NULL; cur = cur->next ){
      
        printf("%-17s| %-17ld| %-17s\n", (cur->addr).name, (cur->addr).tel, (cur->addr).email);
    }
}

AddressList *search(AddressList *root, Address find, Address a[SIZE]){
  int k=0;
  for(int i=0;i<n;i++)
    {
      if( strcmp(find.name, a[i].name)==0)
	{
	  k++;
	  printf("  Name           |     Tel         |    Email        \n");
	   printf("%17s| %17ld| %17s\n", a[i].name, a[i].tel, a[i].email); 
	}
    }
  if(k==0) printf("It's not exist in the list!\n");
  }
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
    AddressList *a, *b, *c;
 
    a = b = c = *head;
    a = a->next->next;
    b = b->next;
    c->next = NULL;
    b->next = c;
 
    while (a != NULL)
    {
        c = b;
        b = a;
        a = a->next;
        b->next = c;
    }
    *head = b;
}
 
