#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define MAX 10
#define fio "address.txt"
#define fbin "address.dat"

typedef struct address{
  char name[20];
  char tel[15];
  char email[30];
}address;

typedef struct{
  address a[MAX];
  int  front , rear;
  int count;
}queue;

int Isempty (queue q) //kiem tra Queue rong
{
    if (q.count == 0) //so phan tu = 0 => rong
        return 1;
    return 0;
}

void init (queue q) //khoi tao Queue rong
{
    q.front = 0; //phan tu dau
    q.rear = -1; // phan tu cuoi o -1 (khong co phan tu trong Q)
    q.count = 0; //so phan tu bang 0
}

int Isfull (queue q) //kiem tra Queue day
{
    if (q.count == MAX) //so phan tu = Max => day
        return 1;
    return 0;
}

void push(queue q, address x) //them phan tu vao cuoi Queue
{
    if (Isfull(q)) printf("Hang doi day !");
    else
    { 
        q.a[++q.rear] = x; //tang Rear len va gan phan tu vao
        q.count++; //tang so phan tu len
    }
}

 
/*void Push_Circular(queue &q, address x) //them phan tu vao cuoi hang doi vong
{
    if (Isfull(q)) printf("Hang doi day !\n");
    else
    {
        q.a[(++q.rear) % MAX] = x; 
        //tang Rear len va gan phan tu vao, Neu Rear dang o vi tri Max-1 thi tang ve vi tri 0
        q.count++; //tang so phan tu len
    }
    }*/

int n;
void input(queue q)
{
  int i;
  address x;
    printf("Enter the number of people: ");
    scanf("%d",&n);
    
    printf("\n");
    for (i = 0; i < (n); i++){
      printf("Enter the name of people %d : ", i+1);__fpurge(stdin);
        gets(x.name);
        printf("\tEnter the telephone number %d : ", i+1);
	__fpurge(stdin);
	gets(x.tel);
        printf("\tEnter the email %d : ", i+1);
	__fpurge(stdin);
	gets(x.email);

	push(q,x);
	//	Push_Circular(q,x);
        
    }
}

void writebin(queue q){
  FILE *f= fopen(fbin,"wb");
  int i;
  if(f==NULL) printf("Error load file\n");
  else fwrite(q.a,sizeof(address),n,f);
  fclose(f);
}

void readbin(queue q){
    FILE *f = fopen(fbin,"rb");
    fseek(f,0,SEEK_END); //Nhay ve cuoi file, di chuyen di 0 vi tri
    (n) = (ftell(f)+1)/sizeof(address); //ftell(); tra ve vi tri hien tai cua con tro
    // SEEK_CUR: di chuyen bat dau tu vi tri hien tai cua con tro, chi dung trong fseek()
    fseek(f,0,SEEK_SET); //Nhay ve dau file, di chuyen di 0 vi tri
    fread(q.a,sizeof(address),(n),f);
    fclose(f);
}

void write(queue q){
    int i;
    FILE *f = fopen(fio, "w");
    if(f==NULL) printf("Error load file");
    fprintf(f, "%-10s %-15s %-10s\n", "Name", "Tel", "Email");
    for (i = 0; i < n; i++)
      fprintf(f, "%-10s %-15s %-10s\n", q.a[i].name, q.a[i].tel, q.a[i].email);
    fclose(f);
    writebin(q);
    printf("input and write success to file\n");
}

void output(queue q)
{
    if (Isempty(q)) printf("Hang doi rong !");
    else
    {
        for (int i=q.front; i<=q.rear; i++)
        //for (int i=Q.Front, j=0; j<Q.count; j++, i = (i++) % Max) //hang vong
	  printf("%-10s %-15s %-10s \n  ",q.a[i].name,q.a[i].tel,q.a[i].email);
        printf("\n");
    }
}

int main()
{
  queue q;
  init(q);
  input(q);
  write(q);
  readbin(q);
  output(q);
  
  return 0;
}
