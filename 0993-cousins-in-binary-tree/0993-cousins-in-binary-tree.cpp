/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };no
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,root});
        int l=0;
       
        while(!q.empty()){
            int s=q.size();
            int x1=0;
            int x2=0;
            int p1=0;
            int p2=0;
            l++;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front().first;
                TreeNode* parent=q.front().second;
                int v=node->val;
                int p=parent->val;
                q.pop();
                if(v==x){
                    p1=p;
                    x1=1;
                }
                if(v==y){
                    p2=p;
                    x2=1;
                }
                if(node->left!=NULL) q.push({node->left,node});
                if(node->right!=NULL) q.push({node->right,node});
                
            }
            if(x1 && x2 && l>2 && p1!=p2){
                return true;
            }
        }

        return false;
    }
};