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
        const int EMPTY_LIST = 1000000;
        
        ListNode* top = nullptr;
        ListNode* cur;
        
        int n = lists.size();
        if(n == 0) return nullptr;
        
        int first[n];
        for(int i = 0; i < n; i++) {
            if(lists[i] != nullptr){
                first[i] = lists[i]->val;
                lists[i] = lists[i]->next;
            } else {
                first[i] = EMPTY_LIST;
            }
        }
        
        while(1) {
            int* v = min_element(first,first+n);
            
            if(*v == EMPTY_LIST) return top;
            
            if(top == nullptr) {
                top = new ListNode(*v);
                cur = top;
            } else {
                cur->next = new ListNode(*v);
                cur = cur->next;
            }
            
            if(lists[v-first] == nullptr) {
                *v = EMPTY_LIST;
            } else {
                *v = lists[v-first]->val;
                lists[v-first] = lists[v-first]->next;
            }
        }
    }
};