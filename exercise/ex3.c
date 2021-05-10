#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define fin "address.txt"
#define fbin "address.dat"

typedef struct address{
  char name[20];
  char tel[15];
  char email[30];
}address;

typedef struct node{
  address data;
  node *next;
};

node *position;

typedef struct{
  position front , rear;
}queue;

void makenullqueue(queue *q)
{
  position head;
  head = new node; //allocation head
  head->next =NULL;
  q->front = head;
  q->rear=head;
}

int emptyqueue(queue q){
  return (q.front ==q.rear);
}

void insert(address x, queue *q){
  q->rear->next = new node;
  q-> rear= q-> rear ->next;
  q->rear->data = x;
  q->rear->next = NULL;
}

void delete(queue *q)
{
  if(!emptyqueue(q)){
    position t; // gan vi tri can xoa vao t
    t= q->front; // xoa front
    q->front = q->front->next;
    free(t);
  }
  else printf("Error: queue is empty\n");
}


node *first, *second, *third;
int main()
{
  FILE *fptr;
  fptr= fopen("/home/thaohust/address.txt","r+");
  if(fptr==NULL)
    {
      printf("Empty\n"); exit(1);
    }
  
  fclose(fptr);
  return 0;
}
