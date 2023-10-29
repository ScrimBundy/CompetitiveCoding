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
        if(root == nullptr) return nullptr;
        if(root->left == nullptr) return root;
        
        // swap layer 1
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        if(root->left->left == nullptr) return root;
        
        // fix layer 2
        temp = root->left->left;
        root->left->left = root->right->left;
        root->right->left = temp;
        temp = root->left->right;
        root->left->right = root->right->right;
        root->right->right = temp;
        
        
        stack<TreeNode*> left_stk;
        stack<TreeNode*> right_stk;
        
        // push from innermost to outermost
        // order matters
        left_stk.push(root->left->right);
        left_stk.push(root->left->left);
        right_stk.push(root->right->left);
        right_stk.push(root->right->right);
        
        while(!left_stk.empty()) {
            TreeNode* left = left_stk.top();
            TreeNode* right = right_stk.top();
            left_stk.pop();
            right_stk.pop();
            
            if(left->left == nullptr) continue;
            
            // swap outermost children
            temp = left->left;
            left->left = right->right;
            right->right = temp;
            
            // swap innermost children
            temp = left->right;
            left->right = right->left;
            right->left = temp;
            
            if(left->left->left == nullptr) continue;
            
            // fix grand children
            
            // left side left->left with right side right->left
            temp = left->left->left;
            left->left->left = right->right->left;
            right->right->left = temp;
            
            // left side left->right with right side right->right
            temp = left->left->right;
            left->left->right = right->right->right;
            right->right->right = temp;
            
            // left side right->left with right side left->left
            temp = left->right->left;
            left->right->left = right->left->left;
            right->left->left = temp;
            
            // left side right->right with right side left->right
            temp = left->right->right;
            left->right->right = right->left->right;
            right->left->right = temp;
            
            // push from innermost to outermost
            // order matters
            left_stk.push(left->right->right);
            left_stk.push(left->right->left);
            left_stk.push(left->left->right);
            left_stk.push(left->left->left);
            right_stk.push(right->left->left);
            right_stk.push(right->left->right);
            right_stk.push(right->right->left);
            right_stk.push(right->right->right);
        }
        
        return root;
    }
};