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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return root2;
        if(root2 == NULL) return root1;

        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root1,root2});
        
        while(!q.empty()){
            TreeNode* a1=q.front().first;
            TreeNode* a2=q.front().second;
            q.pop();

            a1->val += a2->val;

            if(a1->left!=NULL && a2->left!=NULL){
                q.push({a1->left,a2->left});
            }else if(a1->left==NULL){
                a1->left=a2->left;
            }
            if(a1->right!=NULL && a2->right!=NULL){
                q.push({a1->right,a2->right});
            }else if(a1->right==NULL){
                a1->right=a2->right;
            }
        }
        return root1;
    }
};