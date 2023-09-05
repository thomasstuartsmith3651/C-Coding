/*
sine function for an input x between (0, 1)
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double input = 0.0, sin_input = 0.0;
    printf("Enter input number:");
    scanf("%lf",&input);
    //check for valid input//
    if ((input>0)&&(input<1)) {

        sin_input = sin(input);      //Calculate the Sine of value

        printf("\nThe sine of %lf is %lf\n", input, sin_input);      //Display the result of the calculation
    }
     else {
        printf("Input %lf was not between 0 and 1\n", input);
    }
}