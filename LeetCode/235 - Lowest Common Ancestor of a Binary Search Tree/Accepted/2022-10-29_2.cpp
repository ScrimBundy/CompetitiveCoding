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
        TreeNode* cur = root;
        int a,b;
        if(p->val < q->val) {
            a = p->val;
            b = q->val;
        } else {
            a = q->val;
            b = p->val;
        }
        while(1) {
            if((cur == p) ||
               (cur == q) ||
               (a < cur->val && cur->val < b)) return cur;
            
            if(a < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
};