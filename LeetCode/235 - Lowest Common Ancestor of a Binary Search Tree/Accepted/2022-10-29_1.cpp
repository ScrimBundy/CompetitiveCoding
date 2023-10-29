/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        TreeNode* cur = root;
        while(1) {
            if((cur == p) || (cur == q)) return cur;
            TreeNode* p_next = (cur->val > p->val)?cur->left:cur->right;
            TreeNode* q_next = (cur->val > q->val)?cur->left:cur->right;
            if(p_next != q_next) return cur;
            cur = p_next;
        }
    }
};