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
    void build(TreeNode* root, unordered_map<int, vector<int>>& graph) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                graph[node->val].push_back(node->left->val);
                graph[node->left->val].push_back(node->val);
                q.push(node->left);
            }

            if (node->right) {
                graph[node->val].push_back(node->right->val);
                graph[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>graph;
        build(root,graph);

        unordered_set<int>vis;
        queue<int>q;
        q.push(start);
        vis.insert(start);
        int c=-1;
        while(!q.empty()){
            int s=q.size();

            for(int i=0;i<s;i++){
                int node=q.front();
                q.pop();


                for(int nei :graph[node]){
                    if(vis.find(nei)==vis.end()){
                        vis.insert(nei);
                        q.push(nei);
                    }
                }
            }
            c++;
        }

        return c;



        
    }
};