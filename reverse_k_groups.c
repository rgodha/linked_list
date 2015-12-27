/**
 * Definition for singly-linked lits
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *p, *q, *r, *tmp;
    int count, size_ll=0;
    
    if(head == NULL) {
        return NULL;
    }

    p = head;
    q = (head->next)?head->next : NULL;

    if(q == NULL) {
        return p;
    }

    for(tmp = head; tmp != NULL; tmp = tmp->next, size_ll++); 

    if(size_ll < k) {
        return p;
        //k = k%size_ll;
    }
    
    if(k == 1) {
        return p;
    }

    p->next = NULL;
    count = 2;

    while(q != NULL && count < k) {
        r = (q->next)?(q->next) : NULL;
        q->next = p;
        p = q;
        q = r;
        count = count + 1;
    }

    r = (q->next)?(q->next) : NULL;
    q->next = p;
    head->next = reverseKGroup(r, k);

    return q;
}
