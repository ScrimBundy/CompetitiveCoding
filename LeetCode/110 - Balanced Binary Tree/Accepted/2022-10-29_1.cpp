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
    bool isBalanced(TreeNode* root) {
        return -1 < heightIfBalanced(root);
    }
private:
    // return height if balanced or -1 if not
    int heightIfBalanced(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int left = heightIfBalanced(root->left);
        if(left == -1) return -1;
        
        int right = heightIfBalanced(root->right);
        if(right == -1) return -1;
        
        int diff = abs(left - right);
        if(diff > 1) return -1;
        
        // balanced
        return max(left,right) + 1;
    }
};