/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        return recReverseOddCopy(root,recReverseCopy(root),true);
    }
private:
    TreeNode* recReverseCopy(TreeNode* root) {
        if(root == nullptr) return root;
        return new TreeNode(root->val,
                            recReverseCopy(root->right),
                            recReverseCopy(root->left));
    }
    TreeNode* recReverseOddCopy(TreeNode* orig, TreeNode* rev, bool odd) {
        if(orig == nullptr) return nullptr;
        
        int nval = (odd)?orig->val:rev->val;
        return new TreeNode(nval,
                            recReverseOddCopy(orig->left,rev->left, !odd),
                            recReverseOddCopy(orig->right,rev->right, !odd));
    }
};