#include<stdio.h>
#define PI 22/7
int main(void)
{ 
 double radius = 0.0;
 printf("Enter radius:");
 scanf("%lf", &radius);
printf("volume is : %lf \n\n", 4.0 *radius*radius*radius/3.0 );
return 0;
}