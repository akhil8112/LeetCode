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
    void traverse(TreeNode* root,vector<int>&l){
        if(root==NULL) return;

        traverse(root->left,l);
        l.push_back(root->val);
        traverse(root->right,l);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>l1;
        
        traverse(root1,l1);
        traverse(root2,l1);
        sort(l1.begin(), l1.end());

        return l1;


    }
};