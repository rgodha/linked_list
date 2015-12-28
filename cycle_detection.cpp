/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast, *cNode, *MeetNode;
        bool flag = false;
        
        slow = head;

        if(slow == NULL) 
            return NULL;
        
        fast = slow->next;
        if(fast == NULL)
            return NULL;
        

        while(slow != NULL && fast != NULL && flag == false) {
            if(slow == fast) {
                cout <<  "Cycle Exists. ";
                MeetNode = slow;
                flag = true;
            }

            slow = slow->next;
            if(fast->next) {
                fast = (fast->next->next)?(fast->next->next):NULL;
            } else {
                fast = NULL;
            }
       }

        if(flag == true) {
            cNode = head;
            MeetNode = MeetNode->next;
            
            while(cNode != MeetNode) {
                cNode = cNode->next;
                MeetNode = MeetNode->next;
            }
            return cNode;
        } else {
            return NULL;
        }
    }
};
