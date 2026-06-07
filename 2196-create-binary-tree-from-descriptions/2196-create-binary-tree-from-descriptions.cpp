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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_map<int, int>mp1;

        
        for(int i=0;i<descriptions.size();i++){
            int p=descriptions[i][0];
            int c=descriptions[i][1];
            int d=descriptions[i][2];
            mp1[p]++;
            if(mp.find(p)==mp.end()){
                TreeNode* node=new TreeNode(p);
                mp[p]=node;
            }
            if(mp.find(c)==mp.end()){
                TreeNode* node=new TreeNode(c);
                mp[c]=node;
            }

            if(d==1){
                mp[p]->left=mp[c];
            }else if(d==0){
                mp[p]->right=mp[c];
            }
        }

        for(int i=0;i<descriptions.size();i++){
            int c=descriptions[i][1];
            if(mp1.find(c)!=mp1.end()){
                mp1[c]=0;
            }
        }
        for(auto i :mp1){
            if(i.second!=0){
                return mp[i.first];
            }
        }
        return NULL;


    }
};