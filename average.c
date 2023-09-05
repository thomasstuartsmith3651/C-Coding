// run using ./a.out averagefile.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void file_read (FILE *ifp, int SIZE, int d[])        //reading the input file
{
	int i; 

    for(i = 0; i < SIZE; i++)
    {
        fscanf(ifp, "%d", &d[i]); //scanning in each individual element
    }
}

//creating output file
void write_to_file (FILE *ifp, FILE *ofp, int SIZE, int DATA[], double avg, int max)
{
    fprintf (ofp, "Array Values : \n");
    int i;
    for (i=0; i<SIZE; i++) fprintf(ofp, "%d\t", DATA[i]);  

    fprintf (ofp, "average value = %.5lf", avg); 
    fprintf (ofp, "\nmax value = %d", max);
}


void average (int SIZE, int d[], double *avg1)                       
{
	double sum;
	int i;
    //summing the elements if the array
	for(i = 0; i < SIZE; i++)
    {
		sum += d[i];                                 
	}

    printf("\n\nAverage of the integers = %lf", sum/SIZE);

    *avg1 = sum/SIZE;    
}

//finds the maximum number by checking each array element against the previous one
void max_number (int SIZE, int d[], int *maxp)
{
    int i;
    int MAX = d[0];

    for(i = 1; i < SIZE; i++)
    {
        if(d[i] >  MAX)
            MAX = d[i];
    }
    
    printf("\n\nThe maximum of the number = %d", MAX);

    *maxp = MAX;       
}


int main (int argc, char *argv[1])
{
    FILE *ifp, *ofp;      //I/O File pointers
    int i, SIZE = 0;
    int maxp;
    double avgp;

    ifp = fopen(argv[1], "r");           //opens input file averagefile.txt
    ofp = fopen("answer-hw3.txt", "w+");    //opens output file

    fscanf(ifp, "%d", &SIZE);
    int DATA [SIZE];                     

    file_read (ifp, SIZE, DATA);         
    
    printf("\n\nThe elements of the array : \n");
    for (i=0; i < SIZE; i++) printf("%d\t", DATA[i]);

    average (SIZE, DATA, &avgp);                
    max_number (SIZE, DATA, &maxp);             

    write_to_file (ifp, ofp, SIZE, DATA, avgp, maxp);     

    fclose(ifp);
    fclose(ofp);

    return 0;
}
