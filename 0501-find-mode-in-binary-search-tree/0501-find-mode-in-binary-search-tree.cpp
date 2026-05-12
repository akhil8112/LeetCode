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
    int maxi=0;
    TreeNode* prev=NULL;

    vector<int>ans;

    void mode(TreeNode* root,int& c){

        if(root==NULL){
            return;
        }

        mode(root->left,c);

        if(prev!=NULL && prev->val==root->val){
            c++;
        }else{
            c=1;
        }

        if(c>maxi){
            ans.clear();
            ans.push_back(root->val);
            maxi=c;
            
        }else if(maxi==c){
            ans.push_back(root->val);
        }
        prev=root;

        mode(root->right,c);
    }
    vector<int> findMode(TreeNode* root) {
        int c=0;
        mode(root,c);
        return ans;
    }
};