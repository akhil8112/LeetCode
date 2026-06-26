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
        queue<TreeNode*>q;
        string s="";

        q.push(root);

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr==NULL){
                s=s.append("#,");
            }else{
                s.append(to_string(curr->val)+',');
                q.push(curr->left);
                q.push(curr->right);
            }
           
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;

        getline(ss,s,',');
        if(s=="#") return NULL;
        TreeNode* node=new TreeNode(stoi(s));
        queue<TreeNode*>q;
        q.push(node);

        while(!q.empty()){
            
            TreeNode* curr=q.front();
            q.pop();

            getline(ss,s,',');

            if(s=="#"){
                curr->left=NULL;
            }else{
                TreeNode* no=new TreeNode(stoi(s));
                curr->left=no;
                q.push(curr->left);
            }

            getline(ss,s,',');
            if(s=="#"){
                curr->right=NULL;
            }else{
                TreeNode* no=new TreeNode(stoi(s));
                curr->right=no;
                q.push(curr->right);
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));