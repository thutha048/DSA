#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#include<string.h>

typedef struct Address{
  char name[30];
  long tel;
  char email[30];
}Address;

typedef struct AddressList
{
  Address addr;  // num la addr
    struct AddressList *next;
}AddressList;
 
void create(AddressList **);
void reverse(AddressList **);
void release(AddressList **);
void display(AddressList *);
AddressList insert(AddressList **head, Address ad);

void clearbuffer()
{
  int ch;
  while((ch=getchar())!= '\n'&& ch!= EOF);
}

AddressList *cur= NULL;
int main()
{
  AddressList *p = NULL; //p la root
    int n;
 
    printf("Enter data into the list\n");
    create(&p);
    printf("Displaying the nodes in the list:\n");
    display(p);
    printf("Reversing the list...\n");
    reverse(&p);
    printf("Displaying the reversed list:\n");
    display(p);
    release(&p);
    printf("Insert to head:\n");
    create(&p);
    insert(&p,);
 
    return 0;
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
 
void create(AddressList **head)
{
  int i=0;
  Address c;
  int ch;
    AddressList *temp, *rear;
 
    do
    {
      
      printf("%d:\n",i++);
      printf("Name: ");
      __fpurge(stdin); gets(c.name); clearbuffer;
      printf("Phone number: ");
      __fpurge(stdin); scanf("%ld",&c.tel); clearbuffer;
      printf("Email: ");
      __fpurge(stdin); gets(c.email); clearbuffer();
      
        temp = (AddressList *)malloc(sizeof(AddressList));
        temp->addr = c;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}
 
void display(AddressList *p)
{
  printf("The list is: \n");
  printf("  Name           |     Tel          |    Email        \n");  
    for (AddressList * cur = p; cur != NULL; cur = cur->next ){
      
        printf("%17s| %17ld| %17s\n", (cur->addr).name, (cur->addr).tel, (cur->addr).email);
    }
}
 
void release(AddressList **head)
{
    AddressList *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}

AddressList insert(AddressList **head, Address ad)
{
    AddressList * new_item = (AddressList*) malloc(sizeof(AddressList));
    new_item->addr = ad;
    new_item->next = *head;
    *head=new_item;
    return *head;
}
