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
    void dfs(TreeNode* root , vector<int>& a1){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            a1.push_back(root->val);
        }
        dfs(root->left,a1);
        dfs(root->right,a1);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        dfs(root1,l1);
        dfs(root2,l2);
        return l1==l2;
    }
};