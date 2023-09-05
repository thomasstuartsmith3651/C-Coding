#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>  
#define NUM_INTEGERS 100 

typedef struct list{int data;struct list *next;}list;

int is_empty(const list *l){ return (l == NULL);}

list *createList (int d)
{
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list *addTofront (int d, list *h)
{
    list *head = createList(d);
    head -> next = h;
    return head;
}


void printList(list *h, char *title)
{
    printf("%s\n", title);
    int i=0;

    while(h != NULL)
    {   
        
        if(i != NUM_INTEGERS-1 && (i+1) % 5 == 0)
            {printf("%d\t", h->data);
            printf("\n");}
        else if(i != NUM_INTEGERS-1 && (i+1) % 5 != 0) 
            {printf("%d\t", h->data);
            }
        else 
            {printf("%d", h->data);
            }
        h = h->next;

        i++;
  
}}

void swap(list *p1, list *p2)
{
    int p1store = p1->data;    //put p1 data into p1store
    p1->data = p2->data;    //duplicate p2 data into p1
    p2->data = p1store;        //put p1 data from temp to p2
}

//standard bubblesort code
void bubblesort(list *h)
{
    int i, j;
    list *point1, *point2;

    for(i = NUM_INTEGERS-2; i >= 0; i--)
    {
        point1 = h;
        point2 = point1->next;

        for (j = 0; j <= i; j++)
        {
            if(point1->data > point2->data)      
                swap(point1, point2);            
                                         
            point1 = point2;                     
            point2 = point2->next;               
        }
    }
}


int main ()
{
    int i;
    // generating random first data pount in list
    srand(time(0));                            
    list *l = createList(rand() % 100);     
    //generating unsorted list
    for(i = 1; i < NUM_INTEGERS; i++) l = addTofront (rand() % 10000, l);    
    
    printList(l, "\n Unsorted List of 100 Integers Between 0 and 1000 : \n");
    bubblesort(l);
    printList(l, "\n Sorted List of 100 Integers Between 0 and 1000 : \n");
    return 0;    
}