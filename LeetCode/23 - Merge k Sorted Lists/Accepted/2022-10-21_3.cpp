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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return recursiveMerge(lists, 0, lists.size() - 1);
    }
private:
    ListNode* recursiveMerge(vector<ListNode*>& lists, int l, int r) {
        if(l == r) return lists[l];
        if(l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(recursiveMerge(lists, l, mid), recursiveMerge(lists, mid+1, r));
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return ((!l1)?l2:l1);
        
        ListNode node;
        ListNode* cur = &node;
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (!l1)?l2:l1;
        
        return node.next;
    }
};