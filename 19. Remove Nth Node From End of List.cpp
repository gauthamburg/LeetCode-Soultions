/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        typedef struct ListNode* node;
        int cnt=0;
        node curr=head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        if(cnt==1 && n==1){
            return NULL;
        }
        int rm=cnt-n;
        if(rm==0){
            return head->next;
        }
        int it=1;
        node curt=head;
        while(it<rm){
           curt=curt->next;
           it++;
        }
        curt->next=curt->next->next;
        return head;



    }
};