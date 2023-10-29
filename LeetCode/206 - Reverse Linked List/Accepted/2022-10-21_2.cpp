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
    ListNode* reverseList(ListNode* head) {
        ListNode* idx = head;
        ListNode* current = nullptr;
        while(idx != nullptr) {
            current = new ListNode(idx->val, current);
            idx = idx->next;
        }
        return current;
    }
};