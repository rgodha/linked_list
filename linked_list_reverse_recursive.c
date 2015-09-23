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

/* 
 * Reverse the linked list recursively
 * without any extra variable.
 */
mynode* recursive_reverse_ll (mynode **head) {
   
   if(*head->next != NULL) {
        *head->next->next = *head;
        return (*head);
   } else {
        
   }

}

int main(int argc, char *argv[]) {
    mynode *head = NULL, *tail = NULL;
    
    /*
     * Make a linked list with values as 1,2 and 3.
     */
    add(&head, &tail, 1);
    add(&head, &tail, 2);
    add(&head, &tail, 3);
    
    /*
     * Print it.
     */
    print_ll(head);

    /*
     * Reverse the LL
     */
    printf("Reverse: \n");
    
    if(head->next != NULL) {
        mynode *temp = recursive_reverse_ll(&head);
        temp->next = NULL;
    }

    print_ll(head);

    return 0;
}
