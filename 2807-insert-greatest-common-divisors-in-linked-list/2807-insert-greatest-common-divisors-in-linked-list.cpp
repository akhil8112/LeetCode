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
    int gcd(int a, int b){
    
        if(a == 0)
            return b;
        if(b == 0)
            return a;
        if(a == b)
            return a;

        if(a > b)
            return gcd(a - b, b);

        return gcd(a, b - a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp1=head;
        ListNode* temp2=head->next;

        while(temp2!=NULL){
            int g=gcd(temp1->val,temp2->val);

            ListNode* newNode=new ListNode(g);
            temp1->next=newNode;
            newNode->next=temp2;

            temp1=temp1->next->next;
            temp2=temp2->next;
        }

        return head;
    }
};