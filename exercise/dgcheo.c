/*in ra cac duong cheo song song voi duong cheo chinh cua matrix vuong*/
#include<stdio.h>
#define MAX 30

int main()
{
  int a[MAX][MAX],i,j ,n;
  printf("Enter a size of matrix: "); scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
      {
	printf("a[%d%d]= ",i,j);
	scanf("%d",&a[i][j]);
      }
  }
  
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
      {
	printf("%d   ",a[i][j]);
      }
    printf("\n");
  }

  printf("Cac duong cheo song song duong cheo chinh:\n");
  /* for(j=n;j>=1;j--)
    {
      for(i=1;i<=n-j+1;i++)
	printf("%d   ",a[i][j+i-1]);
      printf("\n");
    }
  */
  for(i=2;i<=n;i++)
    for(j=1;j<=i+j-1;j++)
      printf("%d   ",a[i+j-1][j]);
  printf("\n");
  
  return 0;
}
