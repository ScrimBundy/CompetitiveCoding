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
        if(head == nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(1) {
            fast = fast->next;
            if(fast == nullptr) return false;
            fast = fast->next;
            if(fast == nullptr) return false;
            slow = slow->next;
            if(fast == slow) return true;
        }
    }
};