/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode *p, *q, *r, *tmp;
    int count=0;
    
    if(head == NULL) {
        return NULL;
    }

    p = head;
    tmp = head;
    if(p->next == NULL) {
        return p;
    }

    while(tmp->next != NULL) {
        q = tmp;         /* Second Last element in the list */
        tmp = tmp->next;
        count++;
    }

    r = tmp; /* Last element in the list */

    /* Reduce the k as k=K%ll.size */
    k = k%(count+1);

    while(k>0) {
        r->next = p;
        q->next = NULL;
        p = r;
        tmp = r;
        r = q;
        while(tmp->next != NULL) {
            q = tmp;
            tmp = tmp->next;
        }

        k--;
    }
    return p;
}
