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
	    
	    stack<TreeNode*> stk;
	    stk.push(root);
	    
        // invert tree in place
        
	    while(!stk.empty()) {
    		TreeNode* node = stk.top();
    		stk.pop();
    		
    		if(node == nullptr) continue;
    		
            // swap left and right sub trees
            TreeNode* temp = node->left;
    		node->left = node->right;
    		node->right = temp;
    		
            // push sub trees to stack
    		stk.push(temp);
        	stk.push(node->left);
    	}
        	
	    return root;
    }
};