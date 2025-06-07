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
    void reorderList(ListNode* head) {
        typedef struct ListNode* node;
        if (!head || !head->next || !head->next->next) return;

        node slow = head;
        node fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        node curr = slow->next;
        node prev = NULL;
        while (curr != NULL) {
            node temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        slow->next = NULL; 

        node first = head;
        node second = prev;
        while (second != NULL) {
            node tmp1 = first->next;
            node tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
