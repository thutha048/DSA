#include<stdio.h>
#include<stdlib.h>

#define MAX 10
typedef struct queue{
  int front, rear;
  int  *array;
}queue;

void makenull(queue *q)
{
  q->front = -1;
  q->rear= -1;
}

/*queue create(int n)
{
  queue* q=(struct queue*)malloc( sizeof(struct queue));
  
  q->front =0;
  q->rear = n-1;
  q->array=(int *)malloc(q->datta * sizeof(int));
  return q;
}*/

int empty(queue q)
{
  return q.front==-1;
}

int full(queue q)
{
  return (q.rear-q.front+1)== MAX;
}

void enqueue( queue *q, int x)
{
  if(full(*q)){
    if(empty(*q)) q->front =0;
    q->rear= q->rear+1;
    q->array[q->rear]=x;
    }
       else printf("queue is full!\n");
}

void dequeue( queue *q)
{
  if(!empty(*q)){
    q->front = q->front+1;
    if(q->front > q->rear)
      makenull(q);
  }
  else printf("queue is empty!\n");
}

int main()
{
  int i=0,x;
  queue *q;
  printf("Enter the array :\n");
  do{
    printf(" a[%d] = ",i++);
    scanf("%d",&x);
    enqueue(&q,x);
  }while(i<=10);

  printf("The queue contains:\n");

  while(!empty(q))
    {
      printf("%d  ",q.front);
    }
  printf("\n");
  return 0;
}
