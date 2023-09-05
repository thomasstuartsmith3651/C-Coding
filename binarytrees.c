#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>  
#define NUM_INTEGERS 100 

typedef struct list{int data;struct list *next;struct list *prev;}list;

int is_empty(const list *l){ return (l == NULL);}

list *createList (int d)
{
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    head -> prev = NULL;
    return head;
}

list *addTofront (int d, list *h)
{
    list *head = createList(d);
    head -> next = h;
    h -> prev = head;
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

void removeElement(list *node)
{ 
    list *my_prev = node->prev;
    list *my_next = node->next;

    node -> next = NULL;           

    my_prev -> next = my_next;
    my_next -> prev = my_prev;

    return;   
}

//Remove duplicate from the list
void removeDups(list *h)
{
    while (h->next != NULL)
    {
        if (h->data == h->next->data)    
        {
            removeElement(h->next);
        }

        else
            h = h->next;                 // will move on if not (also serves as double check)
    }
}

//counts number of integers in the list
void countFinal(list *h)
{
    int total;

    while (h == NULL)
    {
        total++;
        h = h ->next;
    }
    
    printf("\nNumber of elements remaining from the list = %d", total);
}

int main()
{
    int i;
    list *list1 = createList(rand()%49);   //first element of list

    for(i = 0; i < NUM_INTEGERS-1; i++)
    {
        list1 = addTofront(rand()%49, list1);       //creating a random generated list
    }

    printList(list1, "\n\nList before sorting : \n");

    bubblesort(list1);
    printList(list1, "\n\nList after Sorting : \n");

    removeDups(list1);
    printList(list1, "\n\nList after duplicate removal : \n");
    countFinal(list1);

    return 0;
}