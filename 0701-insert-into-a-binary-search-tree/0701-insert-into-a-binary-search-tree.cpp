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
    void insert(TreeNode* &node, int val){
        if(node==NULL){
            TreeNode* n = new TreeNode(val);
            node=n;
            return;
        }

        if(val<node->val){
            insert(node->left,val);
        }else{
           insert(node->right,val);
        }
        

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);

        TreeNode* node =root;
        insert(node,val);
        return root;
    }
};