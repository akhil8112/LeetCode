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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*  temp=head;
        vector<int>a;
        while(temp!=slow){
            a.push_back(temp->val);
            temp=temp->next;
        }
        int sum=INT_MIN;
        int i=a.size()-1;
        while(slow!=NULL){
            sum=max(sum,a[i]+slow->val);
            i--;
            slow=slow->next;
        }
        return sum;
    }
};