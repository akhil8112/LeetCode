/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>>matrix(m,vector<int>(n,0));
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        
        vector<int>ans;
        
        while(top<=bottom && left<=right){
            //top
            for(int i=left;i<=right;i++){
                if(head!=NULL){
                    matrix[top][i]=head->val;
                    head=head->next;
                }
                else{
                    matrix[top][i]=-1;
                }
            }
            top++;

            //right
            for(int i=top;i<=bottom;i++){
                if(head!=NULL){
                    matrix[i][right]=head->val;
                    head=head->next;
                }
                else{
                    matrix[i][right]=-1;
                }
            }
            right--;

            //bottom
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    if(head!=NULL){
                        matrix[bottom][i]=head->val;
                        head=head->next;
                    }
                    else{
                        matrix[bottom][i]=-1;
                    }
                }
                bottom--;
            }

            //left
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    if(head!=NULL){
                        matrix[i][left]=head->val;
                        head=head->next;
                    }
                    else{
                        matrix[i][left]=-1;
                    }
                }
                left++; 
            }
        }
        return matrix;
    }
};