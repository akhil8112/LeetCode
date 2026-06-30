/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "#";
        string ans="";
        queue<TreeNode*>q;
        ans.append(to_string(root->val));
        ans.append(",");

        q.push(root);

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr->left==NULL){
                ans.append("#");
                ans.append(",");
            }else{
                q.push(curr->left);
                ans.append(to_string(curr->left->val));
                ans.append(",");
            }
            if(curr->right==NULL){
                ans.append("#");
                ans.append(",");
                
            }else{
                q.push(curr->right);
                ans.append(to_string(curr->right->val));
                ans.append(",");
            }

        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;
        stringstream ss(data);
        string s;

        getline(ss,s,',');
        TreeNode* root=new TreeNode(stoi(s));

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            getline(ss,s,',');

            if(s=="#"){
                curr->left=NULL;
            }else{
                TreeNode* l=new TreeNode(stoi(s));
                curr->left=l;
                q.push(curr->left);
            }

            getline(ss,s,',');

            if(s=="#"){
                curr->right=NULL;
            }else{
                TreeNode* l=new TreeNode(stoi(s));
                curr->right=l;
                q.push(curr->right);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;