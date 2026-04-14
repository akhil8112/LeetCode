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
        stack<int>st1,st2;

        ListNode* temp=l1;
        while(temp!=NULL){
            st1.push(temp->val);
            temp=temp->next;
        }
        temp=l2;
        while(temp!=NULL){
            st2.push(temp->val);
            temp=temp->next;
        }
        ListNode* head=NULL;
    
        int c=0;
        while(!st1.empty() || !st2.empty()){
            int a,b;
            if(st1.empty()){
                a=0;
            }else{
                a=st1.top();
                st1.pop();
            }

            if(st2.empty()){
                b=0;
            }else{
                b=st2.top();
                st2.pop();
            }
            int sum;
            if(a+b+c>9){
                sum=a+b+c-10;
                c=1;
            }else{
                sum=a+b+c;
                c=0;
            }
            ListNode* newNode= new ListNode(sum);

            if(head==NULL){
                head=newNode;
            }else{
                newNode->next=head;
                head=newNode;
            }

        }
        if(c==1){
            ListNode* newNode= new ListNode(c);
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
};