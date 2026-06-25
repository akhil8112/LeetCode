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
    int cameras = 0;

    int dfs(TreeNode* root) {
        if (root==NULL) return 2;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 0 ||right==0) {
            cameras++;
            return 1;
        }

        if (left== 1||right==1) {
            return 2;
        }
        
        return 0;
    }
//0 means not covered
//1 has camera
//2 covered
//ulta traverse karenge neeche se upar 
//leaf ke child null hai to return 2 karenge assume covered hai to leaf cover nhi hogi to ham 0 return kar denge
//agar 0 mil gya to ham camera laga denge aur 1 return kar denge matlab hamne camera laga diya
//ab agar 1 mil gya matlab child me camera laga hai to ab iss node to covered kar denge aur 2 return kar denge
//ab 2 milega upar to matlab return 0 ho jayega aur uss node to uncovered mark kar denge
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
};