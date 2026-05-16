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
    TreeNode* prev=NULL;
    TreeNode* mis1=NULL;
    TreeNode* mis2=NULL;
//we traverse in inorder if prev is greater then curr node it violate bst store Both node here first node is found if any other violation then that root node store in second first node remain same
    void help(TreeNode* root){
        if(root==NULL) return;

        help(root->left);

        if(prev!=NULL && prev->val>root->val){
            if(mis1==NULL){
                mis1=prev;
            }
            mis2=root;
        }
        prev=root;

        help(root->right);

    }
    void recoverTree(TreeNode* root) {
        help(root);
        int t=mis1->val;
        mis1->val=mis2->val;
        mis2->val=t;
    }
};