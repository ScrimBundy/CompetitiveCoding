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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return nullptr;
        
        // fast slow pointer but hold the slow back once
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        bool hold = true;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            if(hold) {
                hold = false;
                continue;
            }
            slow = slow->next;
        }
        
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        
        return head;
    }
};