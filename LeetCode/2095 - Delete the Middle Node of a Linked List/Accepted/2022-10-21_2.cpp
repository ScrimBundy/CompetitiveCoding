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
        
        ListNode* fast = head->next->next;
        ListNode* slow = head;
        
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        /*
        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        */
        slow->next = slow->next->next;
        
        return head;
    }
};