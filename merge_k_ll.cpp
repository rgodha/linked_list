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
    struct compare {
        bool operator()(const ListNode* L1, const ListNode* L2) {
            return L1->val > L2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*, vector < ListNode* >, compare> pq;
        ListNode prehead(0);
        ListNode *min = NULL, *cur = &prehead;
        int total_lists = lists.size();

        for(int i=0; i<total_lists; i++) {
            if(lists[i])
                pq.push(lists[i]);
        }
        
        while(!pq.empty()) {
            min = pq.top(); pq.pop();   
            cur->next = min;
            cur = cur->next;

            if(min->next) {
                pq.push(min->next);
            }
        }
        return prehead.next?prehead.next : NULL;
    }
};
