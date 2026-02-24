/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    long long dfs(TreeNode* root, int cur){
         if (root == NULL)
        return 0;

    cur = cur * 2 + root->val;

    if (root->left == NULL && root->right == NULL)
        return cur;

    long long leftSum = dfs(root->left, cur);
    long long rightSum = dfs(root->right, cur);

    return leftSum + rightSum;

        
    }

    long long sumRootToLeaf(TreeNode* root) {
     
        return dfs(root,0);
        
        
    }
};