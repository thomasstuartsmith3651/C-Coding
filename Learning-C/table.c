#include <stdio.h>
#include <math.h>

int main(void)
{
    double step,sine,cosine;
    int i;
    for(i = 0; i < 100; i++)
        {
            step = i/100.0;
            sine = sin(step);
            printf("sin(%lf) = %lf\t", step, sine);  

            cosine = cos(step);   
            printf("Cos(%lf) = %lf\n", step, cosine); 

        }


}