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
    ListNode* rotateRight(ListNode* head, int k) {
         if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        
        ListNode* prev=NULL;
        int c=0;
        while(temp!=NULL){
            prev=temp;
            temp=temp->next;
            c++;
        }
        temp=head;
        int n=k%c;
        ListNode* head1=NULL;
        for(int i=0;i<c-n-1;i++){
            temp=temp->next;
            
        }
        prev->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};