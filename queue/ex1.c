#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX]; 
int front, rear; 
int i; 
int choice; 

void insert(); 
void delet(); 
void display(); 

int main()
{
  int i=1;
  printf ("ARRAY IMPLEMENTATION OF QUEUES\n\n"); 
  front = rear = -1;
  printf("Enter the element:\n");
 do{
   printf("q[%d] = ",i++); 
   insert();
 }while(i<=MAX);
 display();
 printf("q[%d]= ",i++);
 insert();
 printf("The queue is already full\n");
 delet();
  display();
  return 0;
}

void insert()
{
  int element;
  /* if (rear == MAX - 1)
  printf("Queue Overflow\n");
  else
  {*/
  if (front == - 1) front = 0;
  scanf("%d", &element);
  rear++;
  queue[rear] = element;
  
}

void delet()
{
  if (front == - 1 || front > rear)
    {
      printf("Queue Underflow \n");
    }
  else
    {
      printf("The deleted element in the queue is: %d\n", queue[front]);
      front++;
    }
}

void display()
{
  int i;
  if (front == - 1)
    {
      printf("Queue underflow\n");
    }
  else
    {
      printf("The elements of the queue are:\n");
      for (i = front; i <= rear; i++)
      printf("%d\n", queue[i]);
    }
}
