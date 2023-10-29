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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        
        ListNode* r_first = nullptr;
        ListNode* r = new ListNode();
        
        
        while(list1 != nullptr || list2 != nullptr) {
            
            int new_val;
            if(list1 == nullptr) {
                new_val = list2->val;
                list2 = list2->next;
            } else if(list2 == nullptr) {
                new_val = list1->val;
                list1 = list1->next;
            } else {
                if(list1->val < list2->val) {
                    new_val = list1->val;
                    list1 = list1->next;
                } else {
                    new_val = list2->val;
                    list2 = list2->next;
                }
            }
            
            r->next = new ListNode(new_val);
            if(r_first == nullptr) {
                r_first = r->next;
                delete r;
                r = r_first;
            }
            else r = r->next;
        }
        return r_first;
    }
};