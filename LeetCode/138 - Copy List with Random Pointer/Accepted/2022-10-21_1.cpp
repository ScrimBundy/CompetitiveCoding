/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        
        Node* base = head;
        while(base != nullptr) {
            Node* temp = base->next;
            base->next = new Node(base->val);
            base->next->next = temp;
            base = temp;
        }
        base = head;
        while(base != nullptr) {
            Node* rand;
            if(base->random == nullptr)
                rand = nullptr;
            else
                rand = base->random->next;
            base->next->random = rand;
            base = base->next->next;
        }
        
        base = head->next->next;
        Node* copy_head = head->next;
        Node* copy = copy_head;
        head->next = base;
        
        while(base != nullptr) {
            copy->next = base->next;
            copy = copy->next;
            base->next = base->next->next;
            base = base->next;
        }
        
        return copy_head;
    }
};