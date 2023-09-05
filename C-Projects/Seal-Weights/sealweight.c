
#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *data;    
    data = fopen("sealdata.txt", "r"); //loading in seal weights text file//

    int weights[1000], i, sum = 0;
    double averageWeight;

    for (i = 0; i < 1000; i++){
        fscanf(data, "%d,", &weights[i] ); //scans data into array//
        sum = sum + weights[i]; //sums weights
    }

    averageWeight = sum/1000.0;//divide by number of seals//
    printf("\nAverage Weight of Seals = %lf\n", averageWeight);
        fclose(data);     //close file

    return 0;
}
