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
        ListNode* front = head;
        while(n > 0) {
            front = front->next;
            n--;
        }
        //if(n > 0) error nth from back doesn't exist
        if(front == nullptr) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        
        ListNode* back = head;
        
        while(front->next != nullptr) {
            front = front->next;
            back = back->next;
        }
        
        ListNode* del = back->next;
        back->next = back->next->next;
        delete del;
        
        return head;
    }
};