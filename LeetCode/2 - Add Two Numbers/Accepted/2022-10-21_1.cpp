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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* top = nullptr;
        ListNode* cur;
        bool carry = false;
        while(l1 != nullptr || l2 != nullptr) {
            
            int sum = 0;
            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += ((carry)?1:0);
            
            carry = sum > 9;
            if(carry) sum -= 10;
            
            if(top == nullptr) {
                top = new ListNode(sum);
                cur = top;
            } else {
                cur->next = new ListNode(sum);
                cur = cur->next;
            }
        }
        if(carry) cur->next = new ListNode(1);
        
        return top;
    }
};