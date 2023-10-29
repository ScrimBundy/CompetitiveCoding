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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> res = recDiameter(root);
        return max(res.first - 1,res.second);
    }
private:
    pair<int,int> recDiameter(TreeNode* root) {
        if(root == nullptr) return {0,0};
        if(root->left == nullptr && root->right == nullptr) return {1,0};
        pair<int,int> left = recDiameter(root->left);
        pair<int,int> right = recDiameter(root->right);
        int longest = max(left.second,right.second);
        int height = max(left.first,right.first) + 1;
        int path = max(left.first + right.first, longest);
        return {height,path};
    }
};