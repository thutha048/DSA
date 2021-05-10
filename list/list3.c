#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define ID 10
#define NAME 30
#define SIZE 100

typedef struct student_t{
  char id[ID];
  char name[NAME];
  int grade;
  // struct student_t *next;
}student;

typedef struct studentlist
{
  student addr;
   struct studentlist *next;
}studentlist;
  

void inputlist(studentlist **root);
void display(studentlist *root);
studentlist *add(studentlist *root, studentlist *toadd);

studentlist *root= NULL , *cur= NULL;

int main()
{
  student a;
  int n,choice;
 

  printf("Enter data into the student list:\n");
  inputlist(&root);
  do{
   printf("\nMENU\n");
  printf("1.Display the list:\n");
  printf("2.Add a student\n");
  printf("3.Sort the list following increasing grade\n");
  printf("5.Exit\n");
  printf("Enter your choice: ");scanf("%d",&choice);
  switch(choice)
    {
    case 1:
      display(root);
      break;
    case 2:
      printf("Add a student:\n");
      /*   printf("Student %d\n",i++);
    printf("Name: ");
    __fpurge(stdin); gets(a.name); 
    printf("ID: ");
    __fpurge(stdin); scanf("%s",a.id);
    printf("Grade: ");
    __fpurge(stdin); scanf("%d",&a.grade);*/
      inputlist(&root);
    add(root,a);
      break;
    case 5:
      printf("Exit\n");
      break;
    default:
      printf("Error!Enter again!\n");
      break;
    }
  }while(choice!=5);
  
 
}


void inputlist(studentlist **root)
{
  student a;
  studentlist *temp , *rear;
  int ch, i=1;
  do{
    printf("Student %d\n",i++);
    printf("Name: ");
    __fpurge(stdin); gets(a.name); 
    printf("ID: ");
    __fpurge(stdin); scanf("%s",a.id);
    printf("Grade: ");
    __fpurge(stdin); scanf("%d",&a.grade);

    temp =(studentlist *)malloc(sizeof(studentlist));

    temp->addr = a;
    temp->next= NULL;
    if(*root ==NULL)
      *root=temp;
    else
      rear->next = temp;
    rear=temp;
    printf("Do you want to continue (1/0): ");
    scanf("%d",&ch);
  }while(ch!=0);
  printf("\n");
}

void display(studentlist *p)
{
  printf("The list is: \n");
  printf("  Name           |     ID           |    Grade        \n");  
    for (studentlist * cur = p; cur != NULL; cur = cur->next ){
      
        printf("%-17s| %-17s| %-17d\n", (cur->addr).name, (cur->addr).id, (cur->addr).grade);
    }
}


studentlist *add(studentlist *root, studentlist *toadd)
{
  studentlist *curr_std, *prev_std = NULL;

  if(root == NULL) return toadd;
  if(toadd->grade > root->grade)
    {
      toadd->next = root;
      return toadd;
    }
  curr_std = root;
  while(curr_std != NULL && toadd->grade < curr_std->grade)
    {
      prev_std = curr_std;
      curr_std = curr_std->next;
    }
  prev_std->next= toadd;
  toadd->next=curr_std;

  return root;
}
