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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k == 1) return head;
        
        // beginning of section to reverse
        ListNode* curHead = head;
        // node after last of section to reverse
        ListNode* tail = head->next;
        // store head of new list
        ListNode* result = head;
        
        // move tail to first position
        int count = k - 1;
        while(count-- > 0) {
            if(tail != nullptr) {
                tail = tail->next;
                result = result->next;
            } else {
                // List not long enough to reverse anything
                return head;
            }
        }
        
        // store last node of previous section
        ListNode* last = head;
        
        while(1) {
            
            // reversing pointers
            ListNode* prev = nullptr;
            ListNode* cur = curHead;
            ListNode* next = nullptr;
            
            if(curHead != head) {
                prev = last;
            }
            
            // reverse section
            while(cur != tail) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            last->next = prev;
            curHead->next = tail;
            last = curHead;
            curHead = tail;
            
            // move tail
            count = k;
            while(count-- > 0) {
                if(tail != nullptr) {
                    tail = tail->next;
                } else {
                    // finished
                    return result;
                }
            }
        }
    }
};