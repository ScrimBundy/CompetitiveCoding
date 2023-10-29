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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
	    
        // copy tree inverted
        
        TreeNode* head = new TreeNode(root->val);
        
	    stack<TreeNode*> stk;
        stack<TreeNode*> nstk;
	    stk.push(root);
        nstk.push(head);
	    
	    while(!stk.empty()) {
    		TreeNode* node = stk.top();
            TreeNode* cur = nstk.top();
    		stk.pop();
            nstk.pop();
    		
            if(node->left != nullptr) {
                cur->right = new TreeNode(node->left->val);
                stk.push(node->left);
                nstk.push(cur->right);
            }
    		
            if(node->right != nullptr) {
                cur->left = new TreeNode(node->right->val);
                stk.push(node->right);
                nstk.push(cur->left);
            }
    	}
        	
	    return head;
    }
};