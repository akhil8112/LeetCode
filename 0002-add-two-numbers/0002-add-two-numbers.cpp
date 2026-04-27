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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        

        ListNode* temp1=l1;
        ListNode* prev=NULL;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int x=temp1->val + temp2->val + carry;
            if(x>9){
                carry=1;
                temp1->val=x-10;
            }else{
                carry=0;
                temp1->val=x;
            }
            prev=temp1;
            temp1=temp1->next;
            temp2=temp2->next;

        }
        if(temp1==NULL && temp2==NULL){
            if(carry==0){
                return l1;
            }else{
                ListNode* dummy=new ListNode(1);
                prev->next=dummy;
                dummy->next=NULL;
                return l1;
            }
        } 
        if(temp1==NULL){
            prev->next=temp2;
            temp1=temp2;
        }
        while(temp1!=NULL){
            int x=temp1->val+ carry;
            if(x>9){
                carry=1;
                temp1->val=x-10;
            }else{
                carry=0;
                temp1->val=x;
            }
            prev=temp1;
            temp1=temp1->next;
        }
        if(carry==1){
                ListNode* dummy=new ListNode(1);
                prev->next=dummy;
                dummy->next=NULL;
                return l1;
            }
        return l1;
    }
};