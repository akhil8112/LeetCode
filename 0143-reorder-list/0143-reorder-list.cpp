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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* next;

        while(temp!=NULL){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    // void reorderList(ListNode* head) {
    //     ListNode* temp=head;
    //     while(temp->next!=NULL){
    //         temp->next=reverseList(temp->next);
    //         temp=temp->next;
            
    //     }

    // }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* head1=head;
        ListNode* head2=reverseList(slow->next);
        slow->next=NULL;

        while (head2) {
            ListNode* temp1 = head1->next;
            ListNode* temp2 = head2->next;
            head1->next=head2;
            head2->next = temp1;
            head1 = temp1;
            head2 = temp2;
        }
    }

};