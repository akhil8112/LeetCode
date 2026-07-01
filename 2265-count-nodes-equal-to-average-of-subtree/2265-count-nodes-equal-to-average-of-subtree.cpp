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
    vector<int> help(TreeNode* root, int& count){
        if(root==NULL) return {0,0};

        vector<int> left=help(root->left,count);
        vector<int> right=help(root->right,count);

        if ( (left[0]+right[0]+root->val) / (left[1]+right[1]+1) == root->val ){
            count++;
        }
        return {left[0]+right[0]+root->val,1+left[1]+right[1]};
    }
    int averageOfSubtree(TreeNode* root) {
         int count=0;
         help(root,count);
         return count;
    }
};