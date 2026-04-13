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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* head1=NULL;
        ListNode* temp1=NULL;
        int sum=0;
        while(temp!=NULL){
            if(temp->val==0){
                ListNode* newNode= new ListNode(sum);
                if(head1==NULL){
                    head1=newNode;
                    temp1=head1;
                   
                }else{
                    temp1->next=newNode;
                    temp1=temp1->next;
                   
                }
                sum=0;
            }else{
                sum += temp->val;
            }
            temp=temp->next;

        }
        return head1;
    }
};