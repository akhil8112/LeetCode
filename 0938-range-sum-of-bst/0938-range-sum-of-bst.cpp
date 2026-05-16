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
    void help(TreeNode* root, int& s,int low, int high){
        if(root==NULL) return;

        help(root->left,s,low,high);
        if(root->val>=low && root->val<=high){
            s=s+root->val;
        }
        help(root->right,s,low,high);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int s=0;
        help(root,s,low,high);
        return s;
    }
};