#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   int num;
   FILE *fptr;
 if ((fptr = fopen("/home/thaohust/test.txt","r")) == NULL){
       printf("Error! opening file\n");
       exit(1);
   }
 
   fscanf(fptr,"%d", &num);
 
   printf("Value of n=%d\n", num);
   fclose(fptr); 
   
   return 0;
}
