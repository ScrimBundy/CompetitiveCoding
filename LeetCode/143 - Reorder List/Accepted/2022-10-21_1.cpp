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
        
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // sever halves
        ListNode* temp = slow->next;
        slow->next = nullptr;
        slow = temp;
        
        // reverse back half
        ListNode* b = reverseList(slow);
        
        // merge list halves
        merge(head,b);
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* rest;
        ListNode* current = nullptr;
        while(head != nullptr) {
            rest = head->next;
            head->next = current;
            current = head;
            head = rest;
        }
        return current;
    }
    void merge(ListNode*& l1, ListNode* l2) {
        if(l1 == nullptr) {
            l1 = l2;
            return;
        }
        
        ListNode* head = l1;
        
        while(head != nullptr && l2 != nullptr) {
            
            // store l1 after head
            ListNode* temp = head->next;
            // link head to l2
            head->next = l2;
            // move l2 pointer to next
            l2 = l2->next;
            // split old l2 node from l2 and reattach temp
            head->next->next = temp;
            // move head forward 2 nodes
            head = temp;
        }
        
        // head reched end but not l2
        if(head->next == nullptr)
            head->next = l2;
    }
};