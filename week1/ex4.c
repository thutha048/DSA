#include<stdio.h>
#include<math.h>

double frac( double f, double *t){
  return modf(f,t);
}

int main()
{
  double f, i;
  printf("Enter a real number: "); scanf("%lf",&f);
  double ans = frac( f, &i);
  printf("Integer part: %lf\n fraction part: %lf\n",i,ans);
  return 0;
}
