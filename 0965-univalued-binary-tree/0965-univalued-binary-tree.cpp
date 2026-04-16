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
    void dfs(TreeNode* root,int& v,bool& uni){
        if(root==NULL) return;

        if(root->val!=v){
            uni=false;
            return;
        }

        dfs(root->left,v,uni);
        dfs(root->right,v,uni);
    }
    bool isUnivalTree(TreeNode* root) {
        bool uni=true;
        int v=root->val;

        dfs(root,v,uni);
        return uni;
    }
};