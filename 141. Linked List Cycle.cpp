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
    bool hasCycle(ListNode *head) {
        typedef struct ListNode* node;
        node curr=head;
        for(int i=0;i<10001;i++){
            if(curr==NULL){
                return false;
                break;
            }
            curr=curr->next;
        }
        return true;
    }
};