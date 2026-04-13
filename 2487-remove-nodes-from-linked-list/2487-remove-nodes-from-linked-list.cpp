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
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode* temp=head;

        stack<int>st;
        while(temp!=NULL){
            while(!st.empty() && st.top()<temp->val){
                st.pop();
            }
            st.push(temp->val);
            temp=temp->next;
        }
        ListNode* head1=NULL;

        while(!st.empty()){
            int x=st.top();
            st.pop();
            ListNode* newNode=new ListNode(x);

            if(head1==NULL){
                head1=newNode;
            }else{
                newNode->next=head1;
                head1=newNode;
            }
        }
        return head1;
    }
};