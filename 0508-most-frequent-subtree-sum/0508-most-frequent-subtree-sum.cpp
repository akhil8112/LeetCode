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
    int maxi=INT_MIN;
    int help(TreeNode* root, unordered_map<int, int>& mp){
        if(root==NULL) return 0;

        int left=help(root->left,mp);
        int right=help(root->right,mp);

        mp[left+right+root->val]++;
        maxi=max(maxi,mp[left+right+root->val]);
        return left+right+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int,int>mp;
        help(root,mp);
        vector<int>ans;
        for(auto i : mp){
            if(i.second==maxi){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};