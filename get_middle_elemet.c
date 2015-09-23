#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int value;
    struct node *next;
}mynode;

void add (mynode **head, mynode **tail, int value);
void print_ll(mynode *); 

void add(mynode **head, mynode **tail, int value) {
    mynode *cursor;
    mynode *temp = malloc(sizeof(mynode));
    temp->value = value;
    temp->next = NULL;

    if(*head == NULL) {
        *head = temp;
    } else {
        for(cursor = *head; cursor->next != NULL; cursor = cursor->next){}
    
        cursor->next = temp;
        *tail = temp;
    }   
}

/* Logic: Initialize two pointers, 
 * Increment first by one while second by two pointers.
 * As second pointers reaches end node, first pointers 
 * will point to middle element in list.
 */
int get_middle_element(mynode **head)
{
    mynode *t1, *t2;
    if(*head == NULL)
    {
        printf("\nLinked list is NULL");
        return 0;
    }

    /* Initialize both pointers to head*/
    t1 = t2 = *head;

    while(t2 != NULL && t2->next != NULL)
    {
        t1 = t1->next;
        t2 = (t2->next->next)?(t2->next->next):NULL;
    }

    return t1->value;
}

void print_ll(mynode *head){
    mynode *cursor;
    
    printf("Linked List:\n");

    if(head == NULL){
        printf("Linked List is empty.\n");
    }else{
        for(cursor = head; cursor != NULL; cursor = cursor->next){
            printf(" %d ->",cursor->value);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) 
{
    mynode *head = NULL, *tail = NULL;
    int middle = 0;

    /*
     * Make a linked list with values as 1,2 and 3.
     */
    add(&head, &tail, 1);
    add(&head, &tail, 2);
    add(&head, &tail, 3);
    add(&head, &tail, 5);
    add(&head, &tail, 8);
    add(&head, &tail, 10);

    /*
     * Print it.
     */
    print_ll(head);

    /*
     * get Middle Linked List Element
     */
    middle = get_middle_element(&head);

    printf("Middle Element is: %d\n",middle);
    
    return 0;
}
